# Patrick Tate
# CSCI 3800
# HW02 - Problem 3

# This program prompts the user for a 5 digit number
# if the user does not enter a 5 digit number, a while loop continues to prompt them until they do
# the number is then converted to a string and the first half is compared to the second half to determine
# if the number is a palindrome

userNum = input("Enter a 5 digit number: ")

# run loop until user enters a 5 digit number
while(len(str(userNum)) != 5):
    print("Please only enter a number of 5 digits")
    userNum = input("Enter a 5 digit number: ")

palindrome = str(userNum)
firstHalf = palindrome[0:3]
secondHalf = palindrome[2:]
secondHalf = secondHalf[::-1]

if firstHalf == secondHalf:
    print(str(userNum) + " is a palindrome")
else:
    print(str(userNum) + " is not a palindrome")