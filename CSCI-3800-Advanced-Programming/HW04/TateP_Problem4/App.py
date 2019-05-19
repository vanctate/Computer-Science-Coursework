# Patrick Tate
# CSCI 3800 HW 4 Problem 4

from Book import Book  # because our App class has books
from PrintedBook import PrintedBook  # because our App class has PrintedBooks
from ElectronicBook import ElectronicBook  # because our App class has ElectronicBooks
from Author import Author  # because books have author/s
from Publisher import Publisher  # because books have a publisher


# App class to model a "library" type application where users can add/remove books, add/remove authors
# and print the books or authors in the "library."
# App class has a list of books and a dictionary of authors, where the dictionary key is the author's name
# and the dictionary value is the author object.
# App class has a menu function that allows the user perform various actions within the applicaiton.
class App:

    # default initializer
    def __init__(self, books=[], authors={}):
        self.__books = books
        self.__authors = authors

    # getters
    def getBooks(self):
        return self.__books

    def getAuthors(self):
        return self.__authors

    # setters
    def setBooks(self, books):
        self.__books = books

    def setAuthors(self, authors):
        self.__authors = authors

    # enables the user to select an option for adding/removing a book, adding/removing an author, and printing books/authors
    def menu(self):
        choice = 0

        # keep the application running until the user wants to quit
        while (choice != 9):
            print("Enter a number for which action you want to perform.")
            print("Enter 1 for adding a book to the library.")
            print("Enter 2 for adding an author to the library.")
            print("Enter 3 to remove a book from the library.")
            print("Enter 4 to remove an author from the library.")
            print("Enter 5 to remove an author from a specific book.")
            print("Enter 6 to add an author to a specific book.")
            print("Enter 7 to print the books in the library.")
            print("Enter 8 to print the authors in the library.")
            print("Enter 9 to exit program")
            try:
                choice = int(input())
            except ValueError as e:
                print("*** Input type error ***")

            # add a PrintedBook or an ElectronicBook to the App's list of books
            if choice == 1:
                bookType = input("Enter 'p' to add a printed book, enter 'e' to add an electronic book:")
                if bookType == 'p':
                    book = self.getPrintedBookInfo()
                    self.addBook(book)
                elif bookType == 'e':
                    book = self.getEBookInfo()
                    self.addBook(book)
                else:
                    print("*** Incorrect value entered for type of book, try again ***")
                    print()

            # add an author the the App's dictionary of authors
            elif choice == 2:
                authorName = input("Enter the name of the author you want to add to the system:")
                self.addAuthorToSystem(authorName)

            # remove a book from the App's list of books
            elif choice == 3:
                bookName = input("Enter the name of the book you wish to remove from the app:")
                self.removeBook(bookName)

            # remove an author from the App's dictionary of authors
            elif choice == 4:
                authorName = input("Enter the author name you want to remove from the library:")
                if self.removeAuthorFromLib(authorName):
                    print(authorName + " removed from the library")
                else:
                    print(authorName + " not found.")

            # remove an author from a specific book's list of authors
            # does not remove that author from the App's dictionary of authors because that author may have other books
            elif choice == 5:
                bookName = input("Enter the book name")
                authorName = input("Enter the author name to remove")
                self.removeAuthorFromBook(bookName, authorName)

            # add an author to a specific book
            elif choice == 6:
                bookName = input("Enter the book name")
                authorName = input("Enter the author's name you wish to add to the book '" + bookName + "':")
                self.addAuthorToBook(bookName, authorName)

            # print the App's books
            elif choice == 7:
                self.printLibraryBooks()

            # print the App's authors
            elif choice == 8:
                self.printAuthors()

            # end program
            elif choice == 9:
                exit(-1)

            # catch non int input and out of range input
            elif not isinstance(choice, int):
                print("*** Enter only a number 1-9")
            else:
                print("*** Incorrect value entered, enter number 1-9 ***")

    # obtain value for a PrintedBook from the user so that a PrintedBook can be instantiated and added to the App
    # returns a PrintedBook object, to be used in conjunction withe the addBook member function
    def getPrintedBookInfo(self):
        title = input("Enter the book title:")
        location = input("Enter the location code:")
        try:
            yearPub = int(input("Enter int value for the year of publication:"))
        except ValueError as e:
            print("*** Input type error, publication year set to 0 ***")
            yearPub = 0
        authors = []
        authorName = input("Enter one author for the book(you can add more late):")
        author = Author(authorName)
        authors.append(author)
        publisherName = input("Enter the publisher:")
        publisher = Publisher(publisherName)
        try:
            pages = int(input("Enter int value for the number of pages:"))
        except ValueError as e:
            print("*** Input type error, total pages set to 0 ***")
            pages = 0
        type = input("Enter the type(hard cover or paperback):")
        print()

        addBook = PrintedBook(title, location, yearPub, authors, publisher, pages, type)
        return addBook

    # obtain value for a ElectronicBook from the user so that an ElectronicBook can be instantiated and added to the App
    # returns an ElectronicBook object, to be used in conjunction withe the addBook member function
    def getEBookInfo(self):
        title = input("Enter the book title:")
        location = input("Enter the location code:")
        try:
            yearPub = int(input("Enter int value for the year of publication:"))
        except ValueError as e:
            print("*** Input type error, publication year set to 0 ***")
            yearPub = 0
        authors = []
        authorName = input("Enter one author for the book(you can add more late):")
        author = Author(authorName)
        authors.append(author)
        publisherName = input("Enter the publisher:")
        publisher = Publisher(publisherName)
        try:
            pages = int(input("Enter int value for the number of pages:"))
        except ValueError as e:
            print("*** Input type error, total pages set to 0 ***")
            pages = 0
        try:
            size = float(input("Enter decimal value for the size in MB of the e-book:"))
        except ValueError as e:
            print("*** Input type error, size set to 0.0 ***")
            size = 0.0
        print()

        addBook = ElectronicBook(title, location, yearPub, authors, publisher, pages, size)
        return addBook

    # add an ElectronicBook or a PrintedBook to the App's list of books
    # adds the book's author/s to the dictioary of authors
    def addBook(self, book):
        if book not in self.__books:
            self.__books.append(book)
            # add the book's author to the dictionary of authors
            for author in book.getAuthors():
                self.__authors[author.getName()] = author

    def addAuthorToSystem(self, authorName):
        addAuthor = Author(authorName)
        self.__authors[addAuthor.getName()] = addAuthor

    def removeBook(self, bookName):
        for book in self.__books:
            if book.getTitle() == bookName:
                self.__books.remove(book)
                print(bookName + " successfully removed from library.")
                print()

    # searches the App's list of books, if found it adds an author to that book
    # also adds that author to the App's dictionary of authors
    def addAuthorToBook(self, bookName, authorName):
        bookFound = False
        for book in self.__books:
            if book.getTitle() == bookName:
                addAuthor = Author(authorName)
                book.addAuthor(addAuthor)
                bookFound = True
                print(authorName + " successfully added to: " + bookName + ".")
                print()
                # add author to the App's dictionary of authors
                self.__authors[addAuthor.getName()] = addAuthor
        if not bookFound:
            print(bookName + " not found, author not added.")
            print()

    # print all the books in the App's list of books
    def printLibraryBooks(self):
        for book in self.__books:
            book.printBook()
            print()

    # print the authors in the App's dictionary of authors
    def printAuthors(self):
        print("Authors currently in the library: ")
        for author in self.__authors:
            print(author)
        print()

    # receives a string authorName parameter and instantiates an author object
    # searches the App's dictionary of authors for that author and if found, deletes that author from the dictionary
    # returns True if author is found and deleted, returns False if author is not found
    def removeAuthorFromLib(self, authorName):
        authorFind = Author(authorName)

        if authorFind.getName() in self.__authors:
            self.__authors.pop(authorName)
            return True
        else:
            return False

    # receives a string for the bookName and string for the authorName
    # first searches the App's list of books for a matching book title, if book title is found, it then searches
    # that book's list of author's for a matching author name and if found removes tha author from the book
    def removeAuthorFromBook(self, bookName, authorName):
        foundBook = False
        foundAuthor = False
        for book in self.__books:
            if book.getTitle() == bookName:
                for author in book.getAuthors():
                    if author.getName() == authorName:
                        book.getAuthors().remove(author)
                        print(author.getName() + " removed from " + book.getTitle())
                        print()
                        foundAuthor = True
                        break
                foundBook = True
        # print message if book title not found
        if not foundBook:
            print("book not found")
        elif not foundAuthor:
            print("author not found")


