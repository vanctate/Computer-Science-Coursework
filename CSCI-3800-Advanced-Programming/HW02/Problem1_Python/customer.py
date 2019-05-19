# Customer class to keep track of a customer's account number, balance from the beginning of the month,
# total charges, total credits, updatedBalance, and credit limit

class Customer:
    accountNum = 0
    beginningBalance = 0
    updatedBalance = 0
    totalCharges = 0
    totalCredits = 0
    creditLimit = 0

    def __init__(self, accountNum, beginningBalance, totalCharges, totalCredits, creditLimit):
        self.accountNum = accountNum
        self.beginningBalance = beginningBalance
        self.totalCharges = totalCharges
        self.totalCredits = totalCredits
        self.creditLimit = creditLimit
        self.updatedBalance = int(beginningBalance) + int(totalCharges) - int(totalCredits)


    def printCustomer(self):
        print("Account Number: " + str(self.accountNum))
        print("Balance from begninning of the month: $" + str(self.beginningBalance))
        print("Total charges this month: $" + str(self.totalCharges))
        print("Total credits this month: $" + str(self.totalCredits))
        print("Credit limit: $" + str(self.creditLimit))
        print("Updated current balance: $" + str(self.updatedBalance))
        self.checkCredit()

    # determine whether customer has exceeded their credit limit
    def checkCredit(self):
        if int(self.updatedBalance) > int(self.creditLimit):
            print("Credit limit exceeded.")
        else:
            print("Credit limit not exceeded.")