# Patrick Tate
# CSCI 3800 HW 4 Problem 4

from Author import Author  # because books have an author
from Publisher import Publisher  # because books have a publisher
from abc import ABCMeta, abstractmethod  # so the Book class can be abstract

# Book class is the abstract base class that PrintedBook and ElectronicBook subclasses will be based off
# Book class has member variables: title, location, yearPub, authors(list), publisher, and pages
# Book class an abstract method PrintBook that is implemented in PrintedBook and ElectronicBook subclasses
class Book(metaclass=ABCMeta):

    # default initializer
    def __init__(self, title="", location="", yearPub=0, authors=[], publisher="", pages=0):
        super().__init__()
        self.__title = title
        self.__location = location
        self.__yearPub = yearPub
        self.__authors = []
        for author in authors:
            self.__authors.append(author)
        self.__publisher = publisher
        self.__pages = pages

    # getters
    def getTitle(self):
        return self.__title
    def getLocation(self):
        return self.__location
    def getYearPub(self):
        return self.__yearPub
    # return the author list
    def getAuthors(self):
        return self.__authors
    # return the author list as a string for easy printing
    def getAuthorsString(self):
        authorList = ""
        for author in self.__authors:
            if len(self.__authors) == 1:
                authorList = author.getName() + "."
            elif author is self.__authors[-1]:
                authorList = authorList + author.getName() + "."
            else:
                authorList = authorList + author.getName() + ", "
        return authorList
    def getPublisher(self):
        return self.__publisher
    def getPages(self):
        return self.__pages

    # setters
    def setTitle(self, title):
        self.__title = title
    def setLocation(self, location):
        self.__location = location
    def setYearPub(self, yearPub):
        self.__yearPub = yearPub
    def setAuthors(self, authors):
        self.__authors = authors
    def setPublisher(self, publisher):
        if isinstance(publisher, Publisher):
            self.__publisher = publisher
        else:
            print("*** Publisher not set: enter a Publisher object as parameter ***")
    def setPages(self, pages):
        self.__pages = pages

    # prints the author names as a string
    # if more than 1 author, author names are separated by a comma
    def printAuthors(self):
        for author in self.__authors:
            if len(self.__authors) == 1:
                print(str(author.getName()) + ".")
            elif author is self.__authors[-1]:
                print(str(author.getName()) + ".")
            else:
                print(str(author.getName()) + ", ", end="")

    # ensures the author parameter is of type Author and adds author to book if it is
    def addAuthor(self, author):
        if isinstance(author, Author):
            self.__authors.append(author)
            return True
        else:
            return False

    # ensures the author parameter is of type Author and removes author from book if it is
    def removeAuthor(self, author):
        if isinstance(author, Author):
            if author in self.__authors:
                self.__authors.remove(author)

    # returns boolean True if found
    def findAuthor(self, author):
        if isinstance(author, Author):
            if author in self.__authors:
                return True

    # compare 2 books to see which has more pages
    def compareTo(self, book):
        if isinstance(book, Book):
            if self.__pages == book.getPages():
                return 0
            elif self.__pages > book.getPages():
                return 1
            else:
                return -1

    # abstract method to be implemented in subclases
    @abstractmethod
    def printBook(self):
        pass

