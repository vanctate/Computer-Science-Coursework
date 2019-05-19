/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#include "pictureDatabase.h"
#include <fstream>
#include <vector>


//displays the main menu within the pictures database
void picturseMenu(BSTree<Pictures, string> *tree)
{
    int choice = 0;
    while(choice != 10)
    {
        cout << endl << "Welcome to the picture database.\n";
        cout << "1 to add a record.\n";
        cout << "2 to search for a picture by name and modify the fields.\n";
        cout << "3 to search for a picture by name and delete that record.\n";
        cout << "4 to sort and print the database by any sortable field.\n";
        cout << "5 to do a complete search on any field.\n";
        cout << "6 to do a partial search on any field.\n";
        cout << "7 to write the picture database to a new csv file.\n";
        cout << "8 to print updated picture database.\n";
        cout << "9 to return to the main menu.\n";
        cout << "10 to exit program.\n";
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
                addRecord(tree);
                break;
                
            case 2:
                //search and modify fields
                modifyRecord(tree);
                break;
                
            case 3:
                //search and delete fields
                deleteRecord(tree);
                break;
                
            case 4:{
                //sort tree
                sortTree(tree);
                break;
            }
            case 5:{
                //complete search
                vector<Pictures> vec;
                completeSearch(tree, vec);
                break;
            }
            case 6:{
                //partial search
                vector<Pictures> vec;
                partialSearch(tree, vec);
                break;
            }
            case 7:{
                //write to csv file
                infoLinePicture();
                writeToFile(tree, tree->Root());
                cout << "Updated picture database sent to new csv file.\n";
                break;
            }
            case 8:{
                //print updated tree
                printPictureTree(tree);
                break;
            }
            case 9:{
                //return to main menu
                return;
                break;
            }
            case 10:{
                exit(10);
                break;
            }
            default:
                cout << "Please enter a number 1-8.\n";
                break;
        }//switch
    }//while
}

//checks if tree is empty, if not empty passes root pointer to printInOrder function
void printPictureTree(BSTree<Pictures, string> *tree)
{
    //if tree not empty
    if (tree->Root() != nullptr) {
        Node<Pictures, string> * newNodePtr = tree->Root();
        printInOrder(newNodePtr);
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints the entire tree in order
void printInOrder(Node<Pictures, string> * leaf)
{
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            printInOrder(leaf->Left());
        }
        //print data
        cout << leaf->Data().name << "\t" << leaf->Data().year << "\t" << leaf->Data().nominations << "\t" << leaf->Data().rating << "\t" << leaf->Data().duration << "\t" << leaf->Data().genre1 << "\t" << leaf->Data().genre2 << "\t" << leaf->Data().release << "\t" << leaf->Data().metacritic << "\t" << leaf->Data().synopsis << endl << endl;
        
        //go right if possible
        if (leaf->Right() != nullptr) {
            printInOrder(leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//picture info is obtained from user and added to the picture tree
void addRecord(BSTree<Pictures, string> *tree)
{
    string tempName, tempGenre1, tempGenre2, tempRelease, tempSynopsis;
    int tempYear, tempNominations, tempMeta, tempDuration;
    double tempRating;
    
    Pictures picture;
    
    cout << endl << "Adding a record to the pictures database.\n";
    cout << "Enter the pictures's name:\n";
    cin.ignore();
    getline(cin, tempName);
    cout << "Enter the picture's first genre:\n";
    getline(cin, tempGenre1);
    cout << "Enter the picture's second genre:\n";
    getline(cin, tempGenre2);
    cout << "Enter the picture's release month:\n";
    getline(cin, tempRelease);
    cout << "Enter the picture's synopsis:\n";
    getline(cin, tempSynopsis);
    
    cout << "Enter the picture's year:\n";
    cin  >> tempYear;
    //ensure char value will not break program
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> tempYear;
    }//while tempYear != int
    
    cout << "Enter the picture's metacritic rating:\n";
    cout << "Value should be 0 - 100.\n";
    cin  >> tempMeta;
    //ensure meta critic score is between 0 - 100 and char value will not break program
    while ((cin.fail()) || (tempMeta < 0) || (tempMeta > 100)) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cout << "Please enter a valid rating number 0 - 100.\n";
        cin  >> tempMeta;
    }//while tempMeta != int
    
    cout << "Enter the picture's total award nominations:\n";
    cin  >> tempNominations;
    //ensure char value will not break program
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> tempNominations;
    }//while tempNominations != int
    
    cout << "Enter the picture's duration in minutes:\n";
    cin  >> tempDuration;
    //ensure char value will not break program
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> tempDuration;
    }//while tempDuration != int
    
    cout << "Enter the picture's rating (0.0 - 10.0):\n";
    cin  >> tempRating;
    //ensure char value will not break program
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> tempRating;
    }//while tempMeta != int
    
    //set struct's data to user entered values
    picture.name = tempName;
    picture.year = tempYear;
    picture.nominations = tempNominations;
    picture.rating = tempRating;
    picture.duration = tempDuration;
    picture.genre1 = tempGenre1;
    picture.genre2 = tempGenre2;
    picture.release = tempRelease;
    picture.metacritic = tempMeta;
    picture.synopsis = tempSynopsis;
    
    //add Picture to the tree, keyed on name
    tree->addNode(picture.name, picture);
}

//search for picture and if found, modify fields
//asks user for picture's name
//searches tree for first occurance of that name
//if picture if found, pointer is sent to modifyField function asking user which field to modify
//finds/modifies first occurance of a picture
void modifyRecord(BSTree<Pictures, string> *tree)
{
    string picture;
    cin.ignore();
    cout << "Enter the picture name you wish to search for and modify.\n";
    getline(cin, picture);
    Node<Pictures, string> * newNodePtr = tree->findNode(picture);
    if (newNodePtr == nullptr) {
        cout << "Sorry picture not found.\n";
    }
    else{
        modifyField(tree, newNodePtr);
    }
}

//asks user which field they want to modify
void modifyField(BSTree<Pictures, string> *tree, Node<Pictures, string> * leaf)
{
    int choice = 0;
    while (choice != 11){
        cout << "Which field would you like to modify?\n";
        cout << "1 to modify the picture's name.\n";
        cout << "2 to modify the picture's year.\n";
        cout << "3 to modify the picture's total nominations.\n";
        cout << "4 to modify the picture's rating.\n";
        cout << "5 to modify the picture's duration.\n";
        cout << "6 to modify the picture's first genre.\n";
        cout << "7 to modify the picture's second genre.\n";
        cout << "8 to modify the picture's release month.\n";
        cout << "9 to modify the picture's meta critic score.\n";
        cout << "10 to modify the picture's synopsis.\n";
        cout << "11 to return to previous menu.\n";
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
                //picture name
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 2:
                //picture's ear
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 3:
                //total nominations
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 4:
                //rating, double
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 5:
                //duration, minutes
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 6:
                //genre1
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 7:
                //genre2
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 8:
                //release month
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 9:
                //metacritic score, 0-100
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 10:
                //synopsis
                getInfo(tree, choice, leaf);
                return;
                break;
                
            case 11:
                return;
                break;
                
            default:
                cout << "Please enter a number 1-6.\n";
                break;
        }//switch
    }//while
    
}

//gets values from user about which field to modify
//key determines which field to obtain info for
//name has special circumstance since it is a key for the bst
//if name is chosen, that node's info is copied, then the node is deleted and re-added with new name for key
void getInfo(BSTree<Pictures, string> *tree, int key, Node<Pictures, string> *leaf)
{
    if (key == 1) {
        string name;
        cin.ignore();
        cout << "Enter the picture's new name.\n";
        getline(cin, name);
        Pictures temp = leaf->Data();
        tree->deleteNode(leaf->Data().name);
        temp.name = name;
        tree->addNode(temp.name, temp);
    }
    else if (key == 2) {
        int year;
        cin.ignore();
        cout << "Enter the picture's new year.\n";
        cin  >> year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> year;
        }//while year != int
        Pictures temp = leaf->Data();
        temp.year = year;
        leaf->setData(temp);
    }
    else if (key == 3) {
        int nominations;
        cin.ignore();
        cout << "Enter the picture's total nominations.\n";
        cin  >> nominations;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> nominations;
        }//while year != int
        Pictures temp = leaf->Data();
        temp.nominations = nominations;
        leaf->setData(temp);
    }
    else if (key == 4) {
        double rating;
        cout << "Enter the picture's new rating, (0.0 - 10.0)\n";
        cin  >> rating;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> rating;
        }//while year != int
        Pictures temp = leaf->Data();
        temp.rating = rating;
        leaf->setData(temp);
    }
    else if (key == 5) {
        int duration;
        cin.ignore();
        cout << "Enter the picture's duration (minutes).\n";
        cin  >> duration;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> duration;
        }//while year != int
        Pictures temp = leaf->Data();
        temp.duration = duration;
        leaf->setData(temp);
    }
    else if (key == 7){
        string genre1;
        cin.ignore();
        cout << "Enter the picture's first genre.\n";
        getline(cin, genre1);
        Pictures temp = leaf->Data();
        temp.genre1 = genre1;
        leaf->setData(temp);
    }
    else if (key == 8){
        string genre2;
        cin.ignore();
        cout << "Enter the picture's second genre.\n";
        getline(cin, genre2);
        Pictures temp = leaf->Data();
        temp.genre2 = genre2;
        leaf->setData(temp);
    }
    else if (key == 9){
        int metacritic;
        cin.ignore();
        cout << "Enter the picture's metacritic score (0-100).\n";
        cin  >> metacritic;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> metacritic;
        }//while year != int
        Pictures temp = leaf->Data();
        temp.metacritic = metacritic;
        leaf->setData(temp);
    }
    else if (key == 10){
        string synopsis;
        cin.ignore();
        cout << "Enter the picture's new synopsis.\n";
        getline(cin, synopsis);
        Pictures temp = leaf->Data();
        temp.synopsis = synopsis;
        leaf->setData(temp);
    }
}

//driver function for complete search
//asks user what kind of complete search they want to peform
//calls function to match the type of search
void completeSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v)
{
    int choice = 0;
    while(choice != 12){
        cout << "Enter the field you wish to do a complete search on.\n";
        cout << "1 for picture name.\n";
        cout << "2 for picture year.\n";
        cout << "3 for picture's total nominations.\n";
        cout << "4 for picture's rating (0.0 - 10.0).\n";
        cout << "5 for picture's duration (minutes).\n";
        cout << "6 for first genre.\n";
        cout << "7 for second genre.\n";
        cout << "8 for release month.\n";
        cout << "9 for meta critic score (0 - 100).\n";
        cout << "10 for synopsis.\n";
        cout << "11 to return to previous menu.\n";
        cout << "12 to exit program.\n";
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
                //picture name
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 2:
                //picture year
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 3:
                //total nominations
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 4:
                //double rating
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 5:
                //int duration
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 6:
                //genre1
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 7:
                //genre2
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 8:
                //release month
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 9:
                //meta critic
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 10:
                //synopsis
                v.clear();
                completeSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
            
            case 11:
                return;
                break;
                
            case 12:
                exit(12);
                break;
                
            default:
                cout << "Please enter a number 1-6" << endl;
                break;
        }//switch
    }//while
        
}

//key determines what kind of input to get from the user
//then the key and string value are passed into overloaded completeSearchString function
void completeSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key)
{
    if (key == 1) {
        string picture;
        cin.ignore();
        cout << "Enter the picture you wish to do a complete search on.\n";
        getline(cin, picture);
        completeSearchString(tree, v, picture, tree->Root(), key);
    }
    else if (key == 2){
        int year;
        cin.ignore();
        cout << "Enter the picture's year.\n";
        cin  >> year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> year;
        }//while year != int
        completeSearchInt(tree, v, year, tree->Root(), key);
    }
    
    else if (key == 3){
        int nominations;
        cin.ignore();
        cout << "Enter the picture's total nominations.\n";
        cin  >> nominations;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> nominations;
        }//while year != int
        completeSearchInt(tree, v, nominations, tree->Root(), key);
    }
    
    else if (key == 4){
        double rating;
        cin.ignore();
        cout << "Enter the picture's rating.\n";
        cin  >> rating;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> rating;
        }//while year != int
        completeSearchDouble(tree, v, rating, tree->Root(), key);
    }
    
    else if (key == 5){
        int duration;
        cin.ignore();
        cout << "Enter the picture's duration.\n";
        cin  >> duration;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> duration;
        }//while year != int
        completeSearchInt(tree, v, duration, tree->Root(), key);
    }
    
    else if (key == 6){
        string genre1;
        cin.ignore();
        cout << "Enter the picture's first genre you wish to do a complete search on.\n";
        getline(cin, genre1);
        completeSearchString(tree, v, genre1, tree->Root(), key);
    }
    else if (key == 7){
        string genre2;
        cin.ignore();
        cout << "Enter the picture's second genre you wish to do a complete search on.\n";
        getline(cin, genre2);
        completeSearchString(tree, v, genre2, tree->Root(), key);
    }
    else if (key == 8){
        string release;
        cin.ignore();
        cout << "Enter the picture's release month you wish to do a complete search on.\n";
        getline(cin, release);
        completeSearchString(tree, v, release, tree->Root(), key);
    }
    
    else if (key == 9){
        int metacritic;
        cin.ignore();
        cout << "Enter the picture's meta critic score.\n";
        cin  >> metacritic;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> metacritic;
        }//while year != int
        completeSearchInt(tree, v, metacritic, tree->Root(), key);
    }
    
    else if (key ==10){
        string synopsis;
        cin.ignore();
        cout << "Enter the picture's synopsis you wish to do a complete search on.\n";
        getline(cin, synopsis);
        completeSearchString(tree, v, synopsis, tree->Root(), key);
    }
}

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchString(BSTree<Pictures, string> *tree, vector<Pictures> &v, string value, Node<Pictures, string> * leaf, int key)
{
    if (key == 1) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().name == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchString(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 6){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().genre1 == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchString(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 7){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().genre2 == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchString(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 8){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().release == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchString(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 10){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().synopsis == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchString(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchInt(BSTree<Pictures, string> *tree, vector<Pictures> &v, int value, Node<Pictures, string> * leaf, int key)
{
    if (key == 2) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().year == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 3){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().nominations == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 5){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().duration == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 9){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().metacritic == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchInt(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchDouble(BSTree<Pictures, string> *tree, vector<Pictures> &v, double value, Node<Pictures, string> * leaf, int key)
{
    if (key == 4) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchDouble(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().rating == value) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                completeSearchDouble(tree, v, value, leaf->Right(), key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//driver function for partial search
//asks user what kind of partial search they want to peform
//calls function to match the type of search
void partialSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v)
{
    int choice = 0;
    while(choice != 12){
        cout << "Enter the field you wish to do a partial search on.\n";
        cout << "1 for picture name.\n";
        cout << "2 for picture year.\n";
        cout << "3 for picture's total nominations.\n";
        cout << "4 for picture's rating (0.0 - 10.0).\n";
        cout << "5 for picture's duration (minutes).\n";
        cout << "6 for first genre.\n";
        cout << "7 for second genre.\n";
        cout << "8 for release month.\n";
        cout << "9 for meta critic score (0 - 100).\n";
        cout << "10 for synopsis.\n";
        cout << "11 to return to previous menu.\n";
        cout << "12 to exit program.\n";
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
                //picture name
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 2:
                //picture year
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 3:
                //total nominations
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 4:
                //double rating
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 5:
                //int duration
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 6:
                //genre1
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 7:
                //genre2
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 8:
                //release month
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 9:
                //meta critic
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 10:
                //synopsis
                v.clear();
                partialSearch(tree, v, choice);
                checkResults(v);
                return;
                break;
                
            case 11:
                return;
                break;
                
            case 12:
                exit(12);
                break;
                
            default:
                cout << "Please enter a number 1-6" << endl;
                break;
        }//switch
    }//while
}

//gets value from user on the field they want to partial search on
void partialSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key)
{
    if (key == 1) {
        string picture;
        cin.ignore();
        cout << "Enter the picture you wish to do a partial search on.\n";
        getline(cin, picture);
        partialSearchString(tree, v, key, picture, tree->Root());
    }
    else if (key == 2){
        string year;
        cin.ignore();
        cout << "Enter the year you wish to do a partial search on.\n";
        getline(cin, year);
        partialSearchString(tree, v, key, year, tree->Root());
    }
    
    else if (key == 3){
        string nominations;
        cin.ignore();
        cout << "Enter the total nominations you wish to do a partial search on.\n";
        getline(cin, nominations);
        partialSearchString(tree, v, key, nominations, tree->Root());
    }
    
    else if (key == 4){
        string rating;
        cin.ignore();
        cout << "Enter the rating you wish to do a partial search on.\n";
        getline(cin, rating);
        partialSearchString(tree, v, key, rating, tree->Root());
    }
    
    else if (key == 5){
        string duration;
        cin.ignore();
        cout << "Enter the duration you wish to do a partial search on.\n";
        getline(cin, duration);
        partialSearchString(tree, v, key, duration, tree->Root());
    }
    
    else if (key == 6){
        string genre1;
        cin.ignore();
        cout << "Enter the picture's first genre you wish to do a partial search on.\n";
        getline(cin, genre1);
        partialSearchString(tree, v, key, genre1, tree->Root());
    }
    else if (key == 7){
        string genre2;
        cin.ignore();
        cout << "Enter the picture's second genre you wish to do a partial search on.\n";
        getline(cin, genre2);
        partialSearchString(tree, v, key, genre2, tree->Root());
    }
    else if (key == 8){
        string release;
        cin.ignore();
        cout << "Enter the picture's release month you wish to do a partial search on.\n";
        getline(cin, release);
        partialSearchString(tree, v, key, release, tree->Root());
    }
    
    else if (key == 9){
        string metacritic;
        cin.ignore();
        cout << "Enter the picture's meta critic score you wish to do a partial search on.\n";
        getline(cin, metacritic);
        partialSearchString(tree, v, key, metacritic, tree->Root());
    }
    
    else if (key == 10){
        string synopsis;
        cin.ignore();
        cout << "Enter the picture's synopsis you wish to do a partial search on.\n";
        getline(cin, synopsis);
        partialSearchString(tree, v, key, synopsis, tree->Root());
    }
}

//searches entire tree in order to find an occurance of searched value
//if searched value is found it is placed in vector of Picture structs
void partialSearchString(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key, string value, Node<Pictures, string> * leaf)
{
    if (key == 1) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().name.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 2){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            string temp = to_string(leaf->Data().year);
            unsigned long found = temp.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 3){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            string temp = to_string(leaf->Data().nominations);
            unsigned long found = temp.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 4){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            string temp = to_string(leaf->Data().rating);
            unsigned long found = temp.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 5){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            string temp = to_string(leaf->Data().duration);
            unsigned long found = temp.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 6){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().genre1.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 7){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().genre2.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 8){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().release.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 9){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            string temp = to_string(leaf->Data().metacritic);
            unsigned long found = temp.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    else if (key == 10){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().synopsis.find(value);
            if (found != string::npos) {
                v.push_back(leaf->Data());
            }
            //go right if possible
            if (leaf->Right() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Right());
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//if results from search are < 5 they are printed, if > 5 user can re-search results or print all
void checkResults(vector<Pictures> v)
{
    int choice;
    if (v.size() > 5) {
        cout << endl << "Your search yielded " << v.size() << " results.\n";
        cout << "Enter 1 to search the results.\n";
        cout << "Enter 2 to display all results.\n";
        cout << "Enter 3 to return to complete search menu.\n";
        cin  >> choice;
        while ((cin.fail()) || (choice < 1) || (choice > 3)) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cout << "Please enter 1, 2, or 3.\n";
            cin  >> choice;
        }//while choice != int
        if (choice == 1) {
            //search vector by choice
            searchResults(v);
        }
        else if (choice == 2){
            displayVector(v);
        }
        else if (choice == 3)
            return;
    }
    else
        displayVector(v);
}

//presents user with a menu choice for which field to search results by
void searchResults(vector<Pictures> v)
{
    int choice = 0;
    while (choice != 12)
    {
        cout << "Which field would you like to search the results by?\n";
        cout << "1 for picture's name.\n";
        cout << "2 for picture's year.\n";
        cout << "3 for picture's total nominations.\n";
        cout << "4 for picture's rating.\n";
        cout << "5 for picture's duration.\n";
        cout << "6 for picture's first genre.\n";
        cout << "7 for picture's second genre.\n";
        cout << "8 for picture's release month.\n";
        cout << "9 for picture's meta critic score.\n";
        cout << "10 for picture's synopsis.\n";
        cout << "11 to return to previous menu.\n";
        cout << "12 to exit program.\n";
        cin  >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cout << "Please enter 1, 2, or 3.\n";
            cin  >> choice;
        }//while choice != int
        switch (choice) {
            case 1:
                //search vector by picture
                searchResults(v, choice);
                break;
                
            case 2:
                //search vector by year
                searchResults(v, choice);
                break;
                
            case 3:
                //search vector by nominations
                searchResults(v, choice);
                break;
                
            case 4:
                //search vector by rating
                searchResults(v, choice);
                break;
                
            case 5:{
                //search vector by duration
                searchResults(v, choice);
                break;
            }
            case 6:
                //search vector by genre1
                searchResults(v, choice);
                break;
                
            case 7:
                //search vector by genre2
                searchResults(v, choice);
                break;
                
            case 8:
                //search vector by release month
                searchResults(v, choice);
                break;
                
            case 9:
                //search vector by meta critic score
                searchResults(v, choice);
                break;
                
            case 10:
                //search vector by synopsis
                searchResults(v, choice);
                break;
                
            case 11:
                //return to previous menu
                return;
                break;
                
            case 12:
                exit(12);
                break;
                
            default:
                cout << "Please enter a value 1 - 12.\n";
                break;
        }//switch
    }//while
}

//overloaded searchResults function
//once user chooses their option in the menu, that key is passed here to determine which field to search
void searchResults(vector<Pictures> v, int key)
{
    if (key == 1) {
        string name;
        cin.ignore();
        cout << "Enter the picture's name.\n";
        getline(cin, name);
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].name == name) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    
    else if (key == 2) {
        int year;
        cin.ignore();
        cout << "Enter the picture's year.\n";
        cin  >> year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> year;
        }//while year != int
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].year == year) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 3) {
        int nominations;
        cin.ignore();
        cout << "Enter the picture's total nominations.\n";
        cin  >> nominations;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> nominations;
        }//while year != int
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].nominations == nominations) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 4) {
        double rating;
        cout << "Enter the picture's rating, (0.0 - 10.0)\n";
        cin  >> rating;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> rating;
        }//while year != int
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].rating == rating) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 5) {
        int duration;
        cin.ignore();
        cout << "Enter the picture's duration (minutes).\n";
        cin  >> duration;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> duration;
        }//while year != int
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].duration == duration) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 6){
        string genre1;
        cin.ignore();
        cout << "Enter the picture's first genre.\n";
        getline(cin, genre1);
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].genre1 == genre1) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 7){
        string genre2;
        cin.ignore();
        cout << "Enter the picture's second genre.\n";
        getline(cin, genre2);
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].genre2 == genre2) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 8){
        string release;
        cin.ignore();
        cout << "Enter the picture's release month.\n";
        getline(cin, release);
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].release == release) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 9){
        int metacritic;
        cin.ignore();
        cout << "Enter the picture's metacritic score (0-100).\n";
        cin  >> metacritic;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> metacritic;
        }//while year != int
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].metacritic == metacritic) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
    else if (key == 10){
        string synopsis;
        cin.ignore();
        cout << "Enter the picture's nsynopsis.\n";
        getline(cin, synopsis);
        
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].synopsis == synopsis) {
                cout << v[i].name << endl;
                cout << v[i].year << endl;
                cout << v[i].nominations << endl;
                cout << v[i].rating << endl;
                cout << v[i].duration << endl;
                cout << v[i].genre1 << endl;
                cout << v[i].genre2 << endl;
                cout << v[i].release << endl;
                cout << v[i].metacritic << endl;
                cout << v[i].synopsis << endl << endl;
                
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }//if count == 0
    }
}

//dispalys contents of vector which stores search results
void displayVector(vector<Pictures> v)
{
    if (v.size() != 0) {
        cout << "Your search yielded " << v.size() << " records:\n\n";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].name << endl;
            cout << v[i].year << endl;
            cout << v[i].nominations << endl;
            cout << v[i].rating << endl;
            cout << v[i].duration << endl;
            cout << v[i].genre1 << endl;
            cout << v[i].genre2 << endl;
            cout << v[i].release << endl;
            cout << v[i].metacritic << endl;
            cout << v[i].synopsis << endl << endl;
        }
    }
    else{
        cout << "No search results matching that request.\n";
    }
}

//aks user for the name of the picture they want to delete
//searches for record, if found deletes node
void deleteRecord(BSTree<Pictures, string> *tree)
{
    string picture;
    cin.ignore();
    cout << "Enter the name of the picture you wish to delete.\n";
    getline(cin, picture);
    
    Node<Pictures, string> * newNodePtr = tree->findNode(picture);
    if (newNodePtr == nullptr) {
        cout << "Sorry picture not found.\n";
    }
    else{
        cout << "Deleting the picture: " << picture << endl;
        tree->deleteNode(picture);
    }
}

//prints the first info line for new csv fle, "name,year,nominations,etc"
void infoLinePicture()
{
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("newPictureDatabase.csv", std::fstream::app);
    
    outFile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << "\n";
}

//prints updated actor/actress tree to new csv file
void writeToFile(BSTree<Pictures, string> *tree, Node<Pictures, string> * leaf)
{
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("newPictureDatabase.csv", std::fstream::app);
    
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            writeToFile(tree, leaf->Left());
        }
        outFile << leaf->Data().name << ",";
        outFile << leaf->Data().year << ",";
        outFile << leaf->Data().nominations << ",";
        outFile << leaf->Data().rating << ",";
        outFile << leaf->Data().duration << ",";
        outFile << leaf->Data().genre1 << ",";
        outFile << leaf->Data().genre2 << ",";
        outFile << leaf->Data().release << ",";
        outFile << leaf->Data().metacritic << ",";
        outFile << leaf->Data().synopsis << endl;
        
        //go right if possible
        if (leaf->Right() != nullptr) {
            writeToFile(tree, leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//asks user which field they want to sort the tree on
void sortTree(BSTree<Pictures, string> *tree)
{
    int choice = 0;
    while (choice != 11){
        cout << "Which field would you like to sort the tree by?\n";
        cout << "1 to sort by year.\n";
        cout << "2 to sort by total nominations.\n";
        cout << "3 to sort by rating.\n";
        cout << "4 to sort by duration.\n";
        cout << "5 to sort by the first genre.\n";
        cout << "6 to sort by the second genre.\n";
        cout << "7 to sort by release month.\n";
        cout << "8 to sort by meta critic score.\n";
        cout << "9 to sort synopsis.\n";
        cout << "10 to return to previous menu.\n";
        cout << "11 to exit program.\n";
        cin  >> choice;
        //prevent char values from breaking the menu
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
        switch (choice) {
            case 1:{
                //year
                BSTree<Pictures, int> *newTree = new BSTree<Pictures, int>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeInt(newNodePtr, newTree, choice);
                printTreeInt(newTree);
                return;
            }
                break;
                
            case 2:{
                //total nominations
                BSTree<Pictures, int> *newTree = new BSTree<Pictures, int>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeInt(newNodePtr, newTree, choice);
                printTreeInt(newTree);
                return;
            }
                break;
                
            case 3:{
                //rating
                BSTree<Pictures, double> *newTree = new BSTree<Pictures, double>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeDouble(newNodePtr, newTree);
                printTreeDouble(newTree);
                return;
            }
                break;
                
            case 4:{
                //duration
                BSTree<Pictures, int> *newTree = new BSTree<Pictures, int>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeInt(newNodePtr, newTree, choice);
                printTreeInt(newTree);
                return;
            }
                break;
                
            case 5:{
                //genre1
                BSTree<Pictures, string> *newTree = new BSTree<Pictures, string>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeString(newNodePtr, newTree, choice);
                printPictureTree(newTree);
                return;
            }
                break;
                
            case 6:{
                //genre2
                BSTree<Pictures, string> *newTree = new BSTree<Pictures, string>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeString(newNodePtr, newTree, choice);
                printPictureTree(newTree);
                return;
            }
                break;
                
            case 7:{
                //release month
                BSTree<Pictures, string> *newTree = new BSTree<Pictures, string>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeString(newNodePtr, newTree, choice);
                printPictureTree(newTree);
                return;
            }
                break;
                
            case 8:{
                //meta critic
                BSTree<Pictures, int> *newTree = new BSTree<Pictures, int>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeInt(newNodePtr, newTree, choice);
                printTreeInt(newTree);
                return;
            }
                break;
                
            case 9:{
                //synopsis
                BSTree<Pictures, string> *newTree = new BSTree<Pictures, string>;
                Node<Pictures, string> * newNodePtr = tree->Root();
                sortTreeString(newNodePtr, newTree, choice);
                printPictureTree(newTree);
                return;
            }
                break;
                
            case 10:
                //return to previous menu
                return;
                break;
                
            case 11:
                exit(11);
                break;
                
            default:
                cout << "Please enter a number 1-6.\n";
                break;
        }//switch
    }//while
}

//traverses entire picture tree, places each node into newTree which is keyed on strings
void sortTreeString(Node<Pictures, string> *ptr, BSTree<Pictures, string> *newTree, int key)
{
    //genre1
    if (key == 5) {
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeString(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.genre1, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeString(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //genre2
    else if (key == 6){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeString(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.genre2, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeString(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //release month
    else if (key == 7){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeString(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.release, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeString(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //synopsis
    else if (key == 9){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeString(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.synopsis, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeString(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//traverses entire picture tree, places each node into newTree which is keyed on ints
void sortTreeInt(Node<Pictures, string> *ptr, BSTree<Pictures, int> *newTree, int key)
{
    //year
    if (key == 1) {
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeInt(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.year, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeInt(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //nominations
    else if (key == 2){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeInt(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.nominations, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeInt(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //duration
    else if (key == 4){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeInt(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.duration, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeInt(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
    
    //meta critic
    else if (key == 8){
        if (ptr != nullptr) {
            //go left if possible
            if (ptr->Left() != nullptr) {
                sortTreeInt(ptr->Left(), newTree, key);
            }
            //copy data into new tree with film key
            Pictures temp = ptr->Data();
            newTree->addNode(temp.metacritic, temp);
            //go right if possible
            if (ptr->Right() != nullptr) {
                sortTreeInt(ptr->Right(), newTree, key);
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }
}

//checks if bs tree is empty, if not passes Node pointer to printInOrderInt
void printTreeInt(BSTree<Pictures, int> *newTree)
{
    //if tree not empty
    if (newTree->Root() != nullptr) {
        Node<Pictures, int> * newNodePtr = newTree->Root();
        printInOrderInt(newNodePtr);
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints bst in order keyed by int
void printInOrderInt(Node<Pictures, int> * leaf)
{
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            printInOrderInt(leaf->Left());
        }
        //print data
        cout << leaf->Data().name << "\t" << leaf->Data().year << "\t" << leaf->Data().nominations << "\t" << leaf->Data().rating << "\t" << leaf->Data().duration << "\t" << leaf->Data().genre1 << "\t" << leaf->Data().genre2 << "\t" << leaf->Data().release << "\t" << leaf->Data().metacritic << "\t" << leaf->Data().synopsis << endl << endl;
        
        //go right if possible
        if (leaf->Right() != nullptr) {
            printInOrderInt(leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//traverses entire picture tree, places each node into newTree which is keyed on double
void sortTreeDouble(Node<Pictures, string> *ptr, BSTree<Pictures, double> *newTree)
{
    if (ptr != nullptr) {
        //go left if possible
        if (ptr->Left() != nullptr) {
            sortTreeDouble(ptr->Left(), newTree);
        }
        //copy data into new tree with film key
        Pictures temp = ptr->Data();
        newTree->addNode(temp.rating, temp);
        //go right if possible
        if (ptr->Right() != nullptr) {
            sortTreeDouble(ptr->Right(), newTree);
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//checks if bst is empty, if not sends Node pointer to printInOrderDouble
void printTreeDouble(BSTree<Pictures, double> *newTree)
{
    //if tree not empty
    if (newTree->Root() != nullptr) {
        Node<Pictures, double> * newNodePtr = newTree->Root();
        printInOrderDouble(newNodePtr);
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints bst in order keyed by double
void printInOrderDouble(Node<Pictures, double> * leaf)
{
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            printInOrderDouble(leaf->Left());
        }
        //print data
        cout << leaf->Data().name << "\t" << leaf->Data().year << "\t" << leaf->Data().nominations << "\t" << leaf->Data().rating << "\t" << leaf->Data().duration << "\t" << leaf->Data().genre1 << "\t" << leaf->Data().genre2 << "\t" << leaf->Data().release << "\t" << leaf->Data().metacritic << "\t" << leaf->Data().synopsis << endl << endl;
        
        //go right if possible
        if (leaf->Right() != nullptr) {
            printInOrderDouble(leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}
