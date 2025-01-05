from cs50 import SQL
import tkinter as tk
import pyperclip
import keyboard
import time

# Initializeing the database with exception handling for terminal debugging
try: 
    db=SQL("sqlite:///copy.db")
except Exception as e:
    print(f"db=SQL error: {e}")

# Deleting previous data from database table and setting autoincrement sequence to 0
# Can not use ALTER TABLE data AUTOINCREMENT = 0 \n
# because SQLite does not support AUTOINCREMENT on UPDATE
try:
    db.execute("DELETE FROM data")
    db.execute("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'data'")
    print("table reset")
except Exception as e:
    print(f"Autoincrement reset error: {e}")

"""
Debugging code

# test = "some text to insert"

# try:
#     db.execute("INSERT INTO data (copied_text) VALUES (?)", (test))
#     print("data inserted successfully")
# except Exception as e:
#     print(f"database error: {e}")
"""

# Initialize the tkinter window as root
root = tk.Tk()


# Set the window size and title
root.geometry("300x400")
root.title("Co.PY")

# Making label for window
label = tk.Label(root, text="Co.PY \n Copy & paste like a god", font=("Arial", 12), pady=10)
label.pack()


# Function for copied text with insert to database functionality
def copy_to_clipboard():
    try:
        time.sleep(0.1)
        selected_text = pyperclip.paste()
        # print(type(selected_text))
        print(f"Copied to clipboard: {selected_text}")
        db.execute("INSERT INTO data (copied_text) VALUES (?)", (selected_text))
        print(f"text inserted into data {selected_text}")
    except tk.TclError:
        print("No text selected")
    except Exception as e:
        print(f"Error: {e}")

"""
Code for copy and paste buttons in root window
    Not in use after implementing the creation of
    textboxes per row in database

def copy():
    copied = textbox.get("1.0", "end-1c")
    pyperclip.copy(copied)


def paste():  
    textbox.delete("1.0", "end")
    pasted_text = pyperclip.paste()
    textbox.insert("1.0", pasted_text)
    print(f"Pasted from clipboard {pasted_text}")
    """

# Initializing list to be used to check for text in textbox
text_list = []


# Making the textboxes per row of copied text in database table.
def make_textbox():
    # Getting number of rows in database table
    try:
        count = db.execute("SELECT COUNT(*) FROM data")[0]["COUNT(*)"]
        print(count)
    except Exception as e:
        print(f"Cant get db.row count: {e}")
        return

    # Using in range to itterate over rows. After gettin the int value of count.
    # Need to start at one to match SQL numbering.
    for i in range(1, count+1): 
        try:
            text = db.execute("SELECT copied_text FROM data WHERE id = ?", (i))[0]["copied_text"]
        except Exception as e:
            print(f"Pulling text from db failed: {e}")
            return

        # For loop is making sure the text is not in a text box already
        if text not in text_list:
            text_list.append(text)

            # Making a new textbox for each row in database table. 
            # Inserting text variable for each box.
            textbox = tk.Text(root, height=2, width=30, padx=10)
            textbox.pack()
            textbox.delete("1.0", "end")
            textbox.insert("1.0", text)
            print(f"New textbox created {text}")
            #print(text_list)
            i += 1


"""Code for copy and past buttons in root window
    Also not in use after textbox per row implementation

copy_button = tk.Button(root, text="Copy", command=copy)
copy_button.pack()

paste_button = tk.Button(root, text="Paste", command=paste)
paste_button.pack()
"""

# keyboard.add_hotkey('ctrl+v', paste)
keyboard.add_hotkey('ctrl+c', copy_to_clipboard)
keyboard.add_hotkey('ctrl+q', make_textbox)

"""Code for binding hotkeys using tkinter code
    Not in use

# Bind Ctrl+C and Ctrl+V to the copy_to_clipboard and paste functions
#root.bind_all('<Control-c>', copy_to_clipboard)
#root.bind_all('<Control-v>', paste)
"""

root.mainloop()