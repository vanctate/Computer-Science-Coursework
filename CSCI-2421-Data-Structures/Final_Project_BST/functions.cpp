/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#include "functions.h"
#include <sstream>

using namespace std;

//loads bst with actor-actress.csv
void loadTree(BSTree<Actors, string> *tree)
{
    fstream inFile;
    inFile.open("actor-actress.csv");
    string tempLine;
    
    string tempYear;
    string tempAward;
    string isWinner;//read in as 0 or 1
    string tempName;//will also be the key
    string tempFilm;
    int count = 0;//ensure correct amount of Actors loaded from file
    getline(inFile, tempLine);//first line descriptions, not data
    
    while (getline(inFile, tempYear, ',')) {
        getline(inFile, tempAward, ',');
        getline(inFile, isWinner, ',');
        getline(inFile, tempName, ',');
        getline(inFile, tempFilm);
        
        Actors actor;//temp actor to be set with info from file
        
        //convert year string to int
        stringstream newYear(tempYear);
        int year = 0;
        newYear >> year;
        actor.year = year;
        
        actor.award = tempAward;
        
        if (isWinner == "1") {
            actor.isWinner = true;
        }
        else{
            actor.isWinner = false;
        }
        actor.name = tempName;
        actor.film = tempFilm;
        
        tree->addNode(actor.name, actor);//add actor to the database
        count++;
    }//while
    inFile.close();
}

//loads bst with pictures.csv
void loadPictureTree(BSTree<Pictures, string> *tree)
{
    fstream inFile;
    inFile.open("pictures.csv");
    string tempLine;
    
    string tempName;//key
    string tempYear;
    string tempNominations;
    string tempRating;
    string tempDuration;//minutes
    string tempGenre1;
    string tempGenre2;
    string tempRelease;//month
    string tempMetacritic;//0-100
    string tempSynopsis;
    
    
    int count = 0;//ensure correct amount of pictures read in from file
    getline(inFile, tempLine);//first line descriptions not data
    
    while (getline(inFile, tempName, ',')) {
        getline(inFile, tempYear, ',');
        getline(inFile, tempNominations, ',');
        getline(inFile, tempRating, ',');
        getline(inFile, tempDuration, ',');
        getline(inFile, tempGenre1, ',');
        getline(inFile, tempGenre2, ',');
        getline(inFile, tempRelease, ',');
        getline(inFile, tempMetacritic, ',');
        getline(inFile, tempSynopsis);
        
        Pictures picture;//temp picture to be set with info from file
        picture.name = tempName;
        
        //convert year string to int
        stringstream newYear(tempYear);
        int year = 0;
        newYear >> year;
        picture.year = year;
        
        //convert nominations to int
        stringstream newNominations(tempNominations);
        int nominations = 0;
        newNominations >> nominations;
        picture.nominations = nominations;
        
        //convert rating to double
        stringstream newRating(tempRating);
        double rating = 0.0;
        newRating >> rating;
        picture.rating = rating;
        
        //convert duration to int
        stringstream newDuration(tempDuration);
        int duration = 0;
        newDuration >> duration;
        picture.duration = duration;
        
        picture.genre1 = tempGenre1;
        picture.genre2 = tempGenre2;
        picture.release = tempRelease;
        
        //convert metaCritic into int
        stringstream newMeta(tempMetacritic);
        int metaCritic = 0;
        newMeta >> metaCritic;
        picture.metacritic = metaCritic;
        
        picture.synopsis = tempSynopsis;
        
        tree->addNode(picture.name, picture);//add picture to the database
        count++;
    }//while
    inFile.close();
}

//main menu funtion, 3 options, 1 enter pictures database, 2 enter actor database, 3 exit
//within the main menu function, each database will have another menu letting user
//decide which actions to take within that database
//ensures a value from 1-3 entered and char values don't break the menu
void mainMenu(BSTree<Actors, string> *actorTree, BSTree<Pictures, string> *pictureTree)
{
    int choice = 0;
    while(choice != 3)
    {
        cout << endl << "Which database do you want to enter?\n";
        cout << "1 to enter actors/actresses database.\n";
        cout << "2 to enter pictures database.\n";
        cout << "3 to exit program.\n";
        cin  >> choice;
        //prevent char values from breaking the menu
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
        switch (choice) {
            case 1:
                cout << "Entering actors/actresses database.\n\n";
                actorsMenu(actorTree);
                break;
                
            case 2:
                cout << "Entering pictures database.\n";
                picturseMenu(pictureTree);
                break;
                
            case 3:
                exit(0);
                break;
                
            default:
                cout << "Please enter a number 1-3.\n\n";
                break;
        }//switch
    }//while
}

