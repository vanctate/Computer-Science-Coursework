# Patrick Tate
# CSCI 3800
# HW 02 - Problem 1
# This program prompts the user for a customer's account number, balance from the beginning of the month,
# total charges, total credits, and credit limit. A Customer object is then instantiated with these values
# and the customer's information is printed

from customer import Customer

# obtain customer information from the user
accountNum = input("Enter your account number: ")
beginningBalance = input("Enter your balance from the beginning of the month:")
totalCharges = input("Enter the total amount of the charges to your account:")
totalCredits = input("Enter the total amount of credits for your account:")
creditLimit = input("Enter the credit limit for your account:")

# instantiate customer object with the prompted values
temp = Customer(accountNum, beginningBalance, totalCharges, totalCredits, creditLimit)

# print the customer information
print()
temp.printCustomer()