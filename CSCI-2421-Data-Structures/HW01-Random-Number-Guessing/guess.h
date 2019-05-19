/*
 - Patrick Tate
 - CSCI 2421 - HW01
 - Program written using Xcode on MacOS
 - Program Description: this program is a game where the user inputs how many random numbers they want to guess(totalNums), and the user also inputs the range for the random numbers 1 - "range." A vector is created with "totalNums" random numbers in the range of 1 - "range." The user then has 3 chances to guess all the numbers correctly. The user has a guessCorrect variable that increments by 1 for each correct guess, when guessCorrect is equivalent to totalNums, the user wins. If the user hasn't guessed all the correct numbers after 3 attempts, they lose. The program accounts for duplicates, for example if the random numbers are 2,2,3, and the user guesses 2,1,0, the user will get only 1 guess correct.
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef guess_h
#define guess_h
#include <vector>
#include <ctime>

class Guess
{
private:
    int totalNums;
    int range;
    std::vector<int> randVec;
    std::vector<int> guessVec;
    
public:
    Guess();//default constructor
    void setTotalNums(int tempNums) {totalNums = tempNums;}
    void setRange(int tempRange) {range = tempRange;}
    void setRandVec(std::vector<int> tempVec) {randVec = tempVec;}
    void setGuessVec(std::vector<int> tempVec) {guessVec = tempVec;}
    int getTotalNums() { return totalNums;}
    int getRange() { return range;}
    std::vector<int> getRandVec() const {return randVec;}
    std::vector<int> getGuessVec() const {return guessVec;}
    std::vector<int> createRandVec(int range, int totalNums);
    std::vector<int> createGuessVec(int totalNums);
    void compareVec(Guess obj);//compare the random vector and the guess vector
    void playGame();
    void userInput(Guess &obj);//obtain range and totalNums from user
};


#endif /* guess_h */
