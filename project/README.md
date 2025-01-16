# co.PY
#### Video Demo:  <https://www.youtube.com/watch?v=hdxFNmY-gz0>
#### Description: An clipboard manipulation code

## The beginning 

I wanted to build something that appeard on the screen and no only in the terminal. The hunt to find an ide was on. 
I had other ideas that had to do with finances and crawling websites, but as I read the project description, I understood that these projects would not be in the spirit of using what we had learned in cs50x.
I then found the sentece in on the project page 

>Strive to create something that outlives this course.

So that was what I wanted to do. I thought about what I acctually would want to use in the future, some project that, even though, I have delivered it in this course, I could keep working on for a long time.
I wanted to make something that I would really use if it was good enough.

At work I always copy and paste alot. There is a lot of copying to be done in the job description. So I figured I should make an copy and past thing. 
That was as far as I had come with my thought when I was sure of what to make.

__I knew what I had to do__

## The first phase 

I started researching different ways to have a window appear on the screen when I run the script. The choise quickly fell on tkInter. Mostly the reason for this was because its included in the core python module. 
I was at this stage hoping I could make the program in codespaces at cs50.dev, and TkInter beeing included in python sounded like a good solution. 

After getting some of the syntax down in code for tkInter I found some of the issues with tkinter, like the poor possibility of "themes". I the discovered customTkInter, and did for some time debate changing. 
In the end I did not because I had all the syntax for tkinter already, and I decided the funtion of the program was more important than the looks for now. 

<ins> I might come back to the look later though! </ins>

I soon realised though, that making a script that open up a new window in the pc is not a good ide to code in a codespaces website. So I had to install a IDE and do it from there. 
I had been using spyder a little but about 5 year ago, but I did not want to do that again. I ended up with two choices: __PyCharm__ or __VScode__.
In the end I went with VScode, reason beeing was that codespaces used in the course was based on VScode, giving me some much neede continuity in a very new world.

After getting labels, textboxes and titles done I moved on to the SQL database.

## The second phase 

I wanted to use an SQL database to store my clipbordcopied text. The whole point of making this program was so that I could have several texts copied and pasted in to my app at the same time. 
Maybe there is other ways to solve this, but for me, the important part was to use SQLite and Python, so I did not look for other methods here. 

The first problem that arrised was the SQLite prompts in python I had been using in the course. 
Code like:
`
db.excecute("SELECT * FROM table")
`
Did not work.

Why? 
I understood that I since I had ended up with the desktop version of VScode, I did not have the luxuary of cs50's library. That is the library that included the SQLite libraries and so on. 

Then I was on to learn about `pip install` and what a `path` was, for all the different libraries I would need. After spending hours and days reading doc's and watching youtube, I acctually got if to work. 
I now had everything I needed to make my project. 

## The third phase 

Making a database, making a table, making sure the table columns had the right attributes. Not something I was comfortable with at first. Again I had to watch some more videos, do some more reading. 

When I had the database running, and I started to insert text to it I realised I was a good part of the way there. 

Now I just needed to get the text out again. And by chance `db.execute(SELECT * FROM data")` work fine for this task, if I wanted to copy all my entries to one tkInter textbox. 

__Not even close to what i wanted__

I did have some issues with the looping of entries in the database, until I understood that the type of return from the prompt was a dict, and that I could get only the value by indexing it after the promp with `...")[0]["column_name"]`.
Understanding that I also realised I probably could do a simple `for i in range(1-x)` loop and have all the entries listed out. 

I also understood that the `COUNT(*)` would give me what I needed for the range.

I took a chance and added the making of textbox widgets from tkInter in the same loop, and it, to my amazement, worked just like i wanted it to.

So I had text copied to the clipboard and inserted to my database, and I had entries in my database showing in different textboxes in my tkInter window. 

## The last phase ##

The last problem I needed to adress what how to stop the same text entries beeing pasted again and again when I wanted to poplulate my window. 
The problem was not easy for me, since this was the kind of thinking I am not used to. 
In the end the solution was simple.

`text_list = []
if text not in text_list
text_list.append(text)
`
Although so simple it took me some time to reach the solution. I did not have any other solution for the issue either. 
<br>
<br>



### Files: <br>
copy.db (database) <br>
main.py (script) <br>
cs50.png (icon art) <br>
requirements.txt (list of libraries needed) <br>
