/*
 Van Tate
 1411-004
 Rock Paper Scissors Game
    - program asks user1 to enter rock, paper or sciossors in form of char variables R,r,P,p,S,s
    - user1's choice is implemented in a switch statement which then asks for user2's choice
    - user1 and user2's choices are compared and a winner is assigned based on the rules
 Status: program compiles and successfully runs
 */

#include <iostream>

using namespace std;

int main()
{
    //variables to hold R/P/S for each user and the choice to continue or end the game
    char user1Choice, user2Choice, playAgain;
    
    //Intro to the game and rules
    cout << "Welcome to the rock, paper, scissors game.\n\n";
    cout << "Rules of the game: rock beats scissors, paper beats rock, & scissors beats paper.\n\n";
    cout << "Ready to play? Enter Y or y to start the game. Enter N or n to end program.\n";
    cin  >> playAgain;
    if ((playAgain == 'N') || (playAgain == 'n')) {
        return 0;
    }
    
    //set the game up and explain the rules
    cout << endl << "Rules of the game: enter S or s for scissors\n";
    cout << "\t\t\t" << "     " << ": enter R or r for rock\n";
    cout << "\t\t\t" << "     " << ": enter P or P for paper\n\n";
    
    // run the game at least once
    do {
        cout << "Player 1, please enter your choice.\n";
        cin  >> user1Choice;
        //convert user1's input to uppercase to make logical comparisons simpler
        user1Choice = toupper(user1Choice);
        
        
        switch (user1Choice) {
            case 'R' :
                cout << "Now player 2 please enter your selection\n";
                cin  >> user2Choice;
                //convert user2's input to uppercase to make logical comparisons simpler
                user2Choice = toupper(user2Choice);
                
                if (user2Choice == user1Choice) {
                    cout << "Rock and rock. It's a tie!\n\n";
                }
                else if (user2Choice == 'P'){   //paper beats rock
                    cout << "Paper beats rock. Player 2 wins! Congratulations!\n\n";
                }
                else if (user2Choice == 'S'){   //rock beats scissors
                    cout << "Rock beats scissors. Player 1 wins! Congratulations!\n\n";
                }
                else
                    cout << "invalid entry\n";  //control input for user2
                break;
                
            case 'P' :
                cout << "Now player 2 please enter your selection\n";
                cin  >> user2Choice;
                //convert user2's input to uppercase to make logical comparisons simpler
                user2Choice = toupper(user2Choice);
                
                if (user2Choice == user1Choice) {
                    cout << "Paper and paper. It's a tie!\n\n";
                }
                else if (user2Choice == 'S'){   //scissors beat paper
                    cout << "Scissors beats paper. Player 2 wins! Congratulations!\n\n";
                }
                else if (user2Choice == 'R'){   //paper beats rock
                    cout << "Paper beats rock. Player 1 wins! Congratulations!\n\n";
                }
                else
                    cout << "invalid entry\n";  //control input for user2
                break;
                
            case 'S' :
                cout << "Now player 2 please enter your selection\n";
                cin  >> user2Choice;
                //convert user2's input to uppercase to make logical comparisons simpler
                user2Choice = toupper(user2Choice);
                
                if (user2Choice == user1Choice) {
                    cout << "Scissors and scissors. It's a tie!\n\n";
                }
                else if (user2Choice == 'R'){   //rock beats scissors
                    cout << "Rock beats scissors. Player 2 wins! Congratulations!\n\n";
                }
                else if (user2Choice == 'P'){   //scissors beats paper
                    cout << "Scissors beats paper. Player 1 wins! Congratulations!\n\n";
                }
                else
                    cout << "invalid entry\n";  //control input for user2
                break;
                
            default :
                cout << "Invalid entry, please enter a valid value.\n" << endl;  //control user1 input
        }
        
        // prompt to determine if user wants to keep playing
        cout << "Thank you for playing. Play again? Y or N" << endl;
        cin  >> playAgain;
        
    // keep loop running if user wants to play again
    } while ((playAgain == 'y') || (playAgain == 'Y'));
    
    
    return 0;
}
