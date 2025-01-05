from cs50 import SQL
import tkinter as tk
import pyperclip
import keyboard
import time


try: 
    db=SQL("sqlite:///copy.db")
except Exception as e:
    print(f"db=SQL error: {e}")

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

textbox = tk.Text(root, height=2, width=30, padx=10)
textbox.pack()

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


def copy():
    copied = textbox.get("1.0", "end-1c")
    pyperclip.copy(copied)


def paste():  
    textbox.delete("1.0", "end")
    pasted_text = pyperclip.paste()
    textbox.insert("1.0", pasted_text)
    print(f"Pasted from clipboard {pasted_text}")


copy_button = tk.Button(root, text="Copy", command=copy)
copy_button.pack()

paste_button = tk.Button(root, text="Paste", command=paste)
paste_button.pack()


keyboard.add_hotkey('ctrl+c', copy_to_clipboard)
keyboard.add_hotkey('ctrl+v', paste)

# Bind Ctrl+C and Ctrl+V to the copy_to_clipboard and paste functions
#root.bind_all('<Control-c>', copy_to_clipboard)
#root.bind_all('<Control-v>', paste)


root.mainloop()