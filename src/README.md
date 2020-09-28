Project 1: Tokenizer
====================
# Compiling the program:

Typing "make lab1" into the src directory will create two executables
- lab1
- Test

'lab1' is what will be used to demo the implemented functionalities of the
project.

# Running lab1:

When running lab1, the user will be able to perform the following actions:
1. Enter any string to be recorded in history that does not begin with the
keyword indicator '!'
2. Type **!history** to view all recorded strings entered by the user
3. Type **!#** where '#' is replaced by any integer value to view a selected
item tokenized.
4. Type **!exit** to end the program

# Notes/Limitations:
There are 2 limitations of 'lab1':
- Any user input starting with '!' is not stored within history
- Lines of up to 100 characters are stored before they are split

Note: User input is stored exactly as entered in history, so leading and
trailing whitespaces are not trimmed.
