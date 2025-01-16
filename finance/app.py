import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__, static_folder='templates')

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user = session["user_id"]
    portfolio = db.execute("SELECT * FROM portfolio WHERE user_id = ?", user)

    # I need a total_assets to have in the overview. I start it with the cash in hand.
    cash2 = db.execute("SELECT cash FROM users WHERE id = ?", user)[0]["cash"]
    total_assets = cash2
    cash = usd(cash2)

    # Itterate thru all the rows of my database-portfolio table
    for row in portfolio:

        # Need the ticker for the loopup helper funtion
        ticker = row["ticker"]
        row["symbol_lookup"] = lookup(ticker)

        # Using current price for the total assets. += is the same as ending with + total_assets
        total_assets += row["symbol_lookup"]["price"] * row["shares"]

    total_assets = usd(total_assets)

    for row in portfolio:
        row["symbol_lookup"]["price"] = usd(row["symbol_lookup"]["price"])
        row["cost"] = usd(row["cost"])


    return render_template("/index.html", cash=cash, portfolio=portfolio, total_assets=total_assets)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Get the symbol and the number of shares from website form
        symbol = request.form.get("symbol")
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Shares must be an integer")

        # Check to see if shares are positive number
        if shares <= 0:
            return apology("Needs to be a positive number")

        # Check to see if symbol is written in form
        if len(symbol) < 1:
            return apology("Need a symbol text")

        # Running the lookup helper function on the symbol from form
        symbol_lookup = lookup(symbol)

        # Checking that lookup returns a value
        if symbol_lookup == None:
            return apology("Write a symbol")

        # Finding latest price, user id and cash to use with INSERT INTO in portfolio.db
        latest_price = lookup(symbol)
        price = latest_price["price"]
        cost_of_purchase = price * shares

        # Need the user from user session for user_id
        user = session["user_id"]

        # access the first element of return list dict and then the cash key
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user)[0]["cash"]
        cash_left = cash - cost_of_purchase

        # Check if user has a portfolio from earlier, actually check if they have that ticker from earlier.
        username_exist = db.execute(
            "SELECT * FROM portfolio WHERE user_id = ? AND ticker = ?", user, symbol)
        if cost_of_purchase > cash:
            return apology("Not enough moneies")

        amount = shares * price

        # If user has portfolio, update cash, dont insert row.
        if len(username_exist) > 0:

            # Get the old cost and shares. Remembering that the return value is a list of dict. So I need first element -> value of key "shares"
            already_shares = db.execute(
                "SELECT shares FROM portfolio WHERE user_ID = ? AND ticker = ?", user, symbol)[0]["shares"]
            already_spent = db.execute(
                "SELECT cost FROM portfolio WHERE user_ID = ? AND ticker = ?", user, symbol)[0]["cost"]
            # print(already_shares)
            # print(already_spent)

            total_cost = already_spent + cost_of_purchase
            total_shares = already_shares + shares


            # print(total_cost)
            # print(total_shares)

            # Updating the portfolio table and the cash in users table.
            db.execute("UPDATE portfolio SET cost = ? WHERE user_id = ? AND ticker = ?",
                       total_cost, user, symbol)
            db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND ticker = ?",
                       total_shares, user, symbol)
            #db.execute("UPDATE portfolio SET cash = ? WHERE user_id = ?", cash_left, user)
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_left, user)
            db.execute("INSERT INTO history (user_id, symbol, price, shares, sell_buy, amount) VALUES(?, ?, ?, ?, ?, ?)",
                       user, symbol, price, shares, "buy", amount)
            return redirect("/")

        # Else insert row in portfolio for new user and update cash
        else:
            db.execute("INSERT INTO portfolio (user_id, ticker, shares, cost) VALUES(?, ?, ?, ?)",
                       user, symbol, shares, cost_of_purchase)
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_left, user)
            db.execute("INSERT INTO history (user_id, symbol, price, shares, sell_buy, amount) VALUES(?, ?, ?, ?, ?, ?)",
                       user, symbol, price, shares, "buy", amount)
            return redirect("/")

    else:
        return render_template("buy.html")
        # return apology("Something wrong in /buy-else")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Ja, nå vises det. Men jeg tror egentlig jeg må oppdatere en sql table også vise det sånn. Her får jeg bare oppdaterte priser og ikke selg/buy...
    user = session["user_id"]
    history = db.execute("SELECT * FROM history WHERE user_id = ?", user)

    #amount = 0
    for row in history:
        ticker = row["symbol"]
        row["symbol_lookup"] = lookup(ticker)
        row["symbol_lookup"]["price"] = usd(row["symbol_lookup"]["price"])
        row["shares"]
        row["sell_buy"]
        row["amount"] = usd(row["amount"])

    return render_template("/history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""
    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if len(symbol) < 1:
            return apology("Need a symbol text")
        symbol_lookup = lookup(symbol)
        if symbol_lookup == None:
            return apology("Not a valid symbol")
        formated_price = usd(symbol_lookup["price"])
        #symbol_lookup["price"] = "28.00"
        #print(symbol_lookup["price"])
        return render_template("/quoted.html", symbol_lookup=symbol_lookup, formated_price = formated_price)
    else:
        return render_template("/quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    try:
        if request.method == "POST":
            username = request.form.get("username")
            password = request.form.get("password")
            password_check = request.form.get("confirmation")
            if len(username) <= 0 or len(password) <= 0:
                return apology("Username required")
            if password != password_check:
                return apology("Password does not match")

            username_exist = db.execute("SELECT username FROM users WHERE username = ?", username)
            if len(username_exist) > 0:
                return apology("Username already in use")
            else:
                hash = generate_password_hash(password, method='scrypt', salt_length=24)
                db.execute("INSERT INTO users (USERNAME, HASH) VALUES(?, ?)", username, hash)
                return redirect("/")
        if request.method == "GET":
            return render_template("/register.html")
    except ValueError:
        return apology("Unable to register with that username, choose another.")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        # Get the symbol and the number of shares from website form
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        #print(f"Symbol: {symbol}")

        # Check to see if shares are positive number
        if shares <= 0:
            return apology("Needs to be a positive number")

        # Running the lookup helper function on the symbol from form
        symbol_lookup = lookup(symbol)

        # Checking that lookup returns a value
        if symbol_lookup == None:
            return apology("Write a symbol")

        price = symbol_lookup["price"]

        # Need the user from user session for user_id
        user = session["user_id"]

        # access the first element of return list dict and then the cash key
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user)[0]["cash"]

        # Check if user has a portfolio from earlier
        username_exist = db.execute(
            "SELECT * FROM portfolio WHERE user_id = ? AND ticker = ?", user, symbol)

        # If user has portfolio, update cash, dont insert row.
        if len(username_exist) > 0:

            # Get the old cost and shares. Remembering that the return value is a list of dict. So I need first element -> value of key "shares"
            already_shares = db.execute(
                "SELECT shares FROM portfolio WHERE user_ID = ? AND ticker = ?", user, symbol)[0]["shares"]
            already_spent = db.execute(
                "SELECT cost FROM portfolio WHERE user_ID = ? AND ticker = ?", user, symbol)[0]["cost"]
            # print(already_shares)
            # print(already_spent)
            if already_shares < shares:
                return apology("Can't sell more than you have")

            total_shares = already_shares - shares
            total_cost = already_spent - (price * shares)
            amount = -price*shares
            #print(price)
            #print(shares)
            #print(already_spent)
            #print(total_cost)
            cash_left = cash - total_cost + already_spent
            #print(cash_left)
            if total_shares == 0:
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_left, user)
                db.execute("INSERT INTO history (user_id, symbol, price, shares, sell_buy, amount) VALUES(?, ?, ?, ?, ?, ?)",
                           user, symbol, price, shares, "sell", amount)
                db.execute("DELETE FROM portfolio WHERE ticker = ?", symbol)

                return redirect("/")
            if total_shares > 0:
                # Updating the portfolio table and the cash in users table.
                db.execute("UPDATE portfolio SET cost = ? WHERE user_id = ? AND ticker = ?",
                        total_cost, user, symbol)
                db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND ticker = ?",
                        total_shares, user, symbol)
                #db.execute("UPDATE portfolio SET cash = ? WHERE user_id = ?", cash_left, user)
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_left, user)
                db.execute("INSERT INTO history (user_id, symbol, price, shares, sell_buy, amount) VALUES(?, ?, ?, ?, ?, ?)",
                           user, symbol, price, shares, "sell", amount)
                return redirect("/")

        # Else nothing to sell, since no user.
        else:
            return apology("You don't own that share")

    else:
        rows = db.execute("SELECT ticker FROM portfolio")
        return render_template("sell.html", rows=rows)
        # return apology("Something wrong in /buy-else")
