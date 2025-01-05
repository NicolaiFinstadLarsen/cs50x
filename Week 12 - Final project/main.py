from cs50 import SQL
import tkinter as tk
import pyperclip
import keyboard
import time


try: 
    db=SQL("sqlite:///copy.db")
except Exception as e:
    print(f"db=SQL error: {e}")

try:
    db.execute("DELETE FROM data")
    db.execute("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'data'")
    print("table reset")
except Exception as e:
    print(f"Autoincrement reset error: {e}")

# test = "some text to insert"

# try:
#     db.execute("INSERT INTO data (copied_text) VALUES (?)", (test))
#     print("data inserted successfully")
# except Exception as e:
#     print(f"database error: {e}")

root = tk.Tk()

root.geometry("300x400")
root.title("Co.PY")

label = tk.Label(root, text="Co.PY \n Copy & paste like a god", font=("Arial", 12))
label.pack()

# textbox = tk.Text(root, height=2, width=30, padx=10)
# textbox.pack()

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


# def copy():
#     copied = textbox.get("1.0", "end-1c")
#     pyperclip.copy(copied)


# def paste():  
#     textbox.delete("1.0", "end")
#     pasted_text = pyperclip.paste()
#     textbox.insert("1.0", pasted_text)
#     print(f"Pasted from clipboard {pasted_text}")


def make_textbox():
    try:
        count = db.execute("SELECT COUNT(*) FROM data LIMIT 5")[0]["COUNT(*)"]
        print(count)
    except Exception as e:
        print(f"Cant get db.row count: {e}")
        return

    for i in range(1, count+1): # Need to start at one to match SQL numbering.
        try:
            text = db.execute("SELECT copied_text FROM data WHERE id = ?", (i))[0]["copied_text"]
        except Exception as e:
            print(f"pulling text from db failed: {e}")
            return

        textbox = tk.Text(root, height=2, width=30, padx=10)
        textbox.pack()
        textbox.delete("1.0", "end")
        textbox.insert("1.0", text)
        i += 1


# copy_button = tk.Button(root, text="Copy", command=copy)
# copy_button.pack()

# paste_button = tk.Button(root, text="Paste", command=paste)
# paste_button.pack()


keyboard.add_hotkey('ctrl+c', copy_to_clipboard)
# keyboard.add_hotkey('ctrl+v', paste)
keyboard.add_hotkey('ctrl+q', make_textbox)

# Bind Ctrl+C and Ctrl+V to the copy_to_clipboard and paste functions
#root.bind_all('<Control-c>', copy_to_clipboard)
#root.bind_all('<Control-v>', paste)


root.mainloop()