# Patrick Tate
# CSCI 3800 HW 4 Problem 4

from App import App # so we can model a library based on an App object
from Book import Book # because our App object will have a list of Books
from PrintedBook import PrintedBook # because our App object will hold PrintedBooks in its list
from ElectronicBook import ElectronicBook # because our App object will hold ElectronicBooks in its list
from Author import Author # because all Books have an author and our App has a dictionary of Author objects
from Publisher import Publisher # because all Books have a publisher

# ****************************************
#
# This is the driver program to demonstrate the functionality of our App class.
# 3 PrintedBooks and 1 ElectronicBook are instantiated as well as authors for both.
# All 4 books are added to a list, and all authors are added to a dictionary, which are then used to
# instantiate an App object, which then runs the menu function.
#
# ****************************************

# instantiate authors, and two separate author lists for 3 PrintedBooks and 1 ElectronicBook
a1 = Author("Margaret Weiss")
a2 = Author("Tracy Hickmann")
a3 = Author("JK Rowling")
p1 = Publisher("Wizards of the Coast")
p2 = Publisher("Pottermore")
authors = []
authors.append(a1)
authors.append(a2)
eBookAuthor = []
eBookAuthor.append(a3)

# instantiate 3 PrintedBooks and 1 ElectronicBook for the App object to use
book1 = PrintedBook("Dragons of Autumn Twilight", "Co", 1987, authors, p1, 593, "hard cover")
book2 = PrintedBook("Dragons of Winter Night", "Co", 1989, authors, p1, 617, "paperback")
book3 = PrintedBook("Dragons of Summer Flame", "Co", 1991, authors, p1, 544, "paperback")
book4 = ElectronicBook("Harry Potter", "US", 1997, eBookAuthor, p2, 317, 1.75)

# instantiate a dictionary for the library App's dictionary of authors and add authors to it
libraryAuthors = {}
for author in authors:
    libraryAuthors[author.getName()] = author
libraryAuthors[a3.getName()] = a3

# instantiate a list of the books for the library App object
libraryBooks = [book1, book2, book3, book4]

# instantiate an App object with the book list and the author dictionary
library = App(libraryBooks, libraryAuthors)
print()
print("*** Welcome to the library application, select an option below ***")
print()
# call the App object's menu for the user
library.menu()