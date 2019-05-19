# Patrick Tate
# CSCI 3800
# HW02 - Problem 5

# This program uses a constant world population growth rate of 1.2% that stays the same each year for the next
# 75 years based on a current population in 2018 of 7.6 billion. The results are printed in a column format
# of "Year - World Population Estimate - Increase Amount"

currentPop = 7600000000
count = 2018 # current year
growthRate = 1.012 # World Bank estimates growth rate is 1.2%, I used 1.012 for easy calculation in loop

# variables for determining when the population doubles
firstPop = currentPop # for finding double
popDouble = 0
yearDouble = 0
first = True

# print the current population
print("Year" + "        " + "World Pop Estimate" + "        " + "Increase Amount")
print(str(count) + "        " + str(currentPop) + "                " + "-")

# calculate population for the next 75 years and print the results
while (count < 2093):
    prevPop = currentPop
    currentPop = round(currentPop * growthRate, 2)
    popGrowth = round(currentPop - prevPop, 2)
    count = count + 1

    #find first instance of pop doubling
    if currentPop > (firstPop * 2):
        if first:
            popDouble = currentPop
            yearDouble = count
            first = False

    # format columns to have the same alignment regardless of how many decimal spaces currentPop takes
    val = str(currentPop)
    if len(val) is 14:
        print(str(count) + "        " + str(currentPop) + "            " + str(popGrowth))
    elif len(val) is 13:
        print(str(count) + "        " + str(currentPop) + "             " + str(popGrowth))
    elif len(val) is 10:
        print(str(count) + "        " + str(currentPop) + "              " + str(popGrowth))


print()
print("Population doubles in year " + str(yearDouble))
