# Patrick Tate
# CSCI 3800 HW 4 Problem 4

from Book import Book  # because ElectronicBook inherits from base class Book


# simple class to model a subclass of Book called ElectronicBook
# ElectronicBook has all member variables from Book
# ElectronicBook also has a member variable named "size" to denote the size in MB of the ElectronicBook
class ElectronicBook(Book):

    def __init__(self, title="", location="", yearPub=0, authors=[], publisher="", pages=0, size=0.0):
        super(ElectronicBook, self).__init__(title, location, yearPub, authors, publisher, pages)
        self.__size = size

    def getSize(self):
        return self.__size

    def setSize(self, size):
        self.__size = size

    # overrides the abstract method printBook from the abstract base class Book
    def printBook(self):
        print("Title: " + str(self.getTitle()) + ". " + "Author/s: " + str(self.getAuthorsString()))
        print(
            "Publisher: " + self.getPublisher().getName() + ". " + "Publication year: " + str(self.getYearPub()) + ".")
        print("Pages: " + str(self.getPages()) + "." + " E-Book Size: " + str(self.__size) + " MB.")