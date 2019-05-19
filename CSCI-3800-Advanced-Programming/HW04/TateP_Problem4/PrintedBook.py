# Patrick Tate
# CSCI 3800 HW 4 Problem 4

from Book import Book # because PrintedBook inherits from base class Book

# simple class to model a sublcass of Book called PrintedBook
# PrintedBook has all member variables from Book
# PrintedBook also has a member variable named "type" to denote either a "hard cover" or "paperback"
class PrintedBook(Book):

    def __init__(self, title="", location="", yearPub=0, authors=[], publisher="", pages=0, type=""):
        super(PrintedBook, self).__init__(title, location, yearPub, authors, publisher, pages)
        self.__type = type

    def getType(self):
        return self.__type

    def setType(self, type):
        self.__type = type

    # overrides the abstract method printBook from the abstract base class Book
    def printBook(self):
        print("Title: " + str(self.getTitle()) + ". " + "Author/s: " + str(self.getAuthorsString()))
        print("Publisher: " + self.getPublisher().getName() + ". Publication year: " + str(self.getYearPub()) + ".")
        print("Pages: " + str(self.getPages()) + "." + " Type: " + self.__type)