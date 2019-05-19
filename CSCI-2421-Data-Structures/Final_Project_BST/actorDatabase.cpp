/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#include "actorDatabase.h"
#include <fstream>

//displays the main menu within the actor database
void actorsMenu(BSTree<Actors, string> *tree)
{
    int choice = 0;
    while(choice != 10)
    {
        cout << endl << "Welcome to the actors/actresses database.\n";
        cout << "1 to add a record.\n";
        cout << "2 to search for an actor by name and modify the fields.\n";
        cout << "3 to search for an actor by name and delete that record.\n";
        cout << "4 to sort and print the database by any sortable field.\n";
        cout << "5 to do a complete search on any field.\n";
        cout << "6 to do a partial search on any field.\n";
        cout << "7 to write the actors/actresses database to a new csv file.\n";
        cout << "8 to print updatd actor/actress database.\n";
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
                vector<Actors> vec;
                completeSearch(tree, vec);
                break;
            }
            case 6:{
                vector<Actors> vec;
                partialSearch(tree, vec);
                break;
            }
            case 7:{
                //write to csv file
                infoLine();
                writeToFile(tree, tree->Root());
                cout << "Updated actor/actress database sent to new csv file.\n";
                break;
            }
            case 8:{
                //print updated tree
                printActorTree(tree);
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

//checks if tree is empty, if not sends Node pointer to printInOrder function
void printActorTree(BSTree<Actors, string> *tree)
{
    //if tree not empty
    if (tree->Root() != nullptr) {
        Node<Actors, string> * newNodePtr = tree->Root();
        printInOrder(newNodePtr);
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints entire tree in order
void printInOrder(Node<Actors, string> * leaf)
{
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            printInOrder(leaf->Left());
        }
        //print data
       cout << leaf->Data().name << "\t" << leaf->Data().award << "\t" << leaf->Data().year << "\t" << leaf->Data().film << "\t";
       
        if (leaf->Data().isWinner) {
            cout << "Winner: yes" << endl << endl;
        }
        else{
            cout << "Winner: no" << endl << endl;
        }
        //go right if possible
        if (leaf->Right() != nullptr) {
            printInOrder(leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}


//actor info is obtained from user and added to the actor tree keyed on name
void addRecord(BSTree<Actors, string> *tree)
{
    int tempYear, tempWinner;
    string tempAward, tempName, tempFilm;
    
    Actors temp;
    
    cout << endl << "Adding a record to the actor/actresses database.\n";
    cout << "Enter the actor's name:\n";
    cin.ignore();
    getline(cin, tempName);
    cout << "Enter the film the actor was in:\n";
    getline(cin, tempFilm);
    cout << "Enter the name of the award the actor was nominated for:\n";
    getline(cin, tempAward);
    cout << "Enter the year of the nomination:\n";
    cin  >> tempYear;
    //ensure char value will not break program
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> tempYear;
    }//while tempYear != int
    
    cout << "Enter 1 if the actor won, enter 0 if they lost:\n";
    cin  >> tempWinner;
    //ensure winner is 1 or 0 and char value will not break program
    while ((cin.fail()) || (tempWinner < 0) || (tempWinner > 1)) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cout << "Please enter a 1 or a 0.\n";
        cin  >> tempWinner;
    }//while choice != int
    
    temp.year = tempYear;
    temp.award = tempAward;
    if (tempWinner == 1) {
        temp.isWinner = true;
    }
    else{
        temp.isWinner = false;
    }
    temp.name = tempName;
    temp.film = tempFilm;
    
    tree->addNode(temp.name, temp);
    
}

//asks user for actor/actress name
//searches tree for first occurance of that name
//if actor/actress if found, pointer is sent to modifyField function asking user which field to modify
//finds/modifies first occurance of an actor
void modifyRecord(BSTree<Actors, string> *tree)
{
    string actor;
    cin.ignore();
    cout << "Enter the actor/actress name you wish to search for and modify.\n";
    getline(cin, actor);
    Node<Actors, string> * newNodePtr = tree->findNode(actor);
    if (newNodePtr == nullptr) {
        cout << "Sorry actor/actress not found.\n";
    }
    else{
        modifyField(tree, newNodePtr);
    }
}

//asks user which field they want to modify
void modifyField(BSTree<Actors, string> *tree, Node<Actors, string> *ptr)
{
    int choice = 0;
    while (choice != 6){
    cout << "Which field would you like to modify?\n";
    cout << "1 to modify actor/actress name.\n";
    cout << "2 to modify award name.\n";
    cout << "3 to modify film name.\n";
    cout << "4 to modify year.\n";
    cout << "5 to modify if they won.\n";
    cout << "6 to return to previous menu.\n";
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
            //actor name
            getInfo(tree, choice, ptr);
            break;
            
        case 2:
            //award name
            getInfo(tree, choice, ptr);
            break;
            
        case 3:
            //film name
            getInfo(tree, choice, ptr);
            break;
            
        case 4:
            //year
            getInfo(tree, choice, ptr);
            break;
            
        case 5:
            //is winner?
            getInfo(tree, choice, ptr);
            break;
            
        case 6:
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
//if name is chosen to change, that Node's info is copied, then deleted, then re-added with new name for key
void getInfo(BSTree<Actors, string> *tree, int key, Node<Actors, string> *ptr)
{
    if (key == 1) {
        string name;
        cin.ignore();
        cout << "Enter the new actor/actress name.\n";
        getline(cin, name);
        Actors temp = ptr->Data();
        tree->deleteNode(ptr->Data().name);
        temp.name = name;
        tree->addNode(temp.name, temp);
    }
    else if (key == 2) {
        string award;
        cin.ignore();
        cout << "Enter the new award name.\n";
        getline(cin, award);
        Actors temp = ptr->Data();
        temp.award = award;
        ptr->setData(temp);
    }
    else if (key == 3) {
        string film;
        cin.ignore();
        cout << "Enter the new film name.\n";
        getline(cin, film);
        Actors temp = ptr->Data();
        temp.film = film;
        ptr->setData(temp);
    }
    else if (key == 4) {
        int year;
        cout << "Enter the new year.\n";
        cin  >> year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> year;
        }//while year != int
        Actors temp = ptr->Data();
        temp.year = year;
        ptr->setData(temp);
    }
    else if (key == 5) {
        int winner;
        cout << "Enter 1 if they won, enter 0 if they lost.\n";
        cin  >> winner;
        while ((cin.fail()) || (winner < 0) || (winner > 1)) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cout << "Please enter a 0 or 1.\n";
            cin  >> winner;
        }//while winner != int
        bool newIsWinner;
        if (winner == 0) {
            newIsWinner = false;
        }
        else{
            newIsWinner = true;
        }
        Actors temp = ptr->Data();
        temp.isWinner = newIsWinner;
        ptr->setData(temp);
    }
}

//asks user which field they want to sort the tree on
void sortTree(BSTree<Actors, string> *tree)
{
    int choice;
    cout << "Which field would you like to sort the actor/actress tree by?\n";
    cout << "Enter 1 for film name.\n";
    cout << "Enter 2 for year.\n";
    cout << "Enter 3 to return to previous menu.\n";
    cin  >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> choice;
    }//while choice != int
    switch (choice) {
        case 1:{
            //film name
            BSTree<Actors, string> *newTree = new BSTree<Actors, string>;
            Node<Actors, string> * newNodePtr = tree->Root();
            sortTreeString(newNodePtr, newTree);
            printActorTree(newTree);
            break;
        }
        case 2:{
            //year
            BSTree<Actors, int> *newTree = new BSTree<Actors, int>;
            Node<Actors, string> * newNodePtr = tree->Root();
            sortTreeInt(newNodePtr, newTree);
            Node<Actors, int> * newTreePtr = newTree->Root();
            printInOrderInt(newTreePtr);
            break;
        }
        case 3:
            //return to previous menu
            return;
            break;
            
        default:
            break;
    }
}

//traverses entire actor tree, places each node into newTree which is keyed on string
void sortTreeString(Node<Actors, string> *ptr, BSTree<Actors, string> *newTree)
{
    if (ptr != nullptr) {
        //go left if possible
        if (ptr->Left() != nullptr) {
            sortTreeString(ptr->Left(), newTree);
        }
        //copy data into new tree with film key
        Actors temp = ptr->Data();
        newTree->addNode(temp.film, temp);
        //go right if possible
        if (ptr->Right() != nullptr) {
            sortTreeString(ptr->Right(), newTree);
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//traverses entire actor tree, places each node into newTree which is keyed on int
void sortTreeInt(Node<Actors, string> *ptr, BSTree<Actors, int> *newTree)
{
    if (ptr != nullptr) {
        //go left if possible
        if (ptr->Left() != nullptr) {
            sortTreeInt(ptr->Left(), newTree);
        }
        //copy data into new tree with film key
        Actors temp = ptr->Data();
        newTree->addNode(temp.year, temp);
        //go right if possible
        if (ptr->Right() != nullptr) {
            sortTreeInt(ptr->Right(), newTree);
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//checks if tree is empty, if not, passes a Node pointer to printInOrderInt
void printTreeInt(BSTree<Actors, int> *newTree)
{
    //if tree not empty
    if (newTree->Root() != nullptr) {
        Node<Actors, int> * newNodePtr = newTree->Root();
        printInOrderInt(newNodePtr);
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints entire tree in order
void printInOrderInt(Node<Actors, int> * leaf)
{
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            printInOrderInt(leaf->Left());
        }
        //print data
        cout << leaf->Data().year << "\t" << leaf->Data().award << "\t" << leaf->Data().name << "\t" << leaf->Data().film << "\t";
        
        if (leaf->Data().isWinner) {
            cout << "Winner: yes" << endl << endl;
        }
        else{
            cout << "Winner: no" << endl << endl;
        }
        //go right if possible
        if (leaf->Right() != nullptr) {
            printInOrderInt(leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//asks user what kind of complete search they want to peform
//calls function to match the type of search
void completeSearch(BSTree<Actors, string> *tree, vector<Actors> &v)
{
    int choice = 0;
    while(choice != 6){
    cout << "Enter the field you wish to do a complete search on.\n";
    cout << "1 for actor/actress name.\n";
    cout << "2 for movie title.\n";
    cout << "3 for award name.\n";
    cout << "4 for year.\n";
    cout << "5 to return to actor/actress database.\n";
    cout << "6 to exit program.\n";
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
            //name
            v.clear();
            completeSearchName(tree, v);
            checkResults(v);
            break;
        
        case 2:
            //movie title
            v.clear();
            completeSearchString(tree, v, choice);
            checkResults(v);
            break;
            
        case 3:
            //award name
            v.clear();
            completeSearchString(tree, v, choice);
            checkResults(v);
            break;
            
        case 4:
            //year
            v.clear();
            completeSearchInt(tree, v);
            checkResults(v);
            break;
            
        case 5:
            return;
            break;
            
        case 6:
            exit(6);
            break;
        default:
            cout << "Please enter a number 1-6" << endl;
            break;
        }//switch
    }//while
}

//obtains info from user
void completeSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key)
{
    if (key == 2) {
        string movie;
        cin.ignore();
        cout << "Enter the movie title you wish to do a complete search on.\n";
        getline(cin, movie);
        completeSearchString(tree, v, movie, tree->Root(), key);
    }
    else if (key == 3){
        string award;
        cin.ignore();
        cout << "Enter the award name you wish to do a complete search on.\n";
        getline(cin, award);
        completeSearchString(tree, v, award, tree->Root(), key);
    }
}

//key deterines which string to search for, actor name, award name, or movie name
void completeSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, string value, Node<Actors, string> * leaf, int key)
{
    if (key == 2) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            if (leaf->Data().film == value) {
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
    else if (key == 3){
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                completeSearchString(tree, v, value, leaf->Left(), key);
            }
            
            if (leaf->Data().award == value) {
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

//obtain name to search for from user and passes name and vector into searchName function
void completeSearchName(BSTree<Actors, string> *tree, vector<Actors> &v)
{
    string actor;
    cin.ignore();
    cout << "Enter the actor/actress name you want to do a complete search for:\n";
    getline(cin, actor);
    searchName(tree, v, actor, tree->Root());
}

//obtain year value from user and passes that value and vector into searchYear function
void completeSearchInt(BSTree<Actors, string> *tree, vector<Actors> &v)
{
    int year;
    cin.ignore();
    cout << "Enter the year you want to do a complete search on:\n";
    cin  >> year;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number and not a character.\n";
        cin  >> year;
    }//while choice != int
    searchYear(tree, v, year, tree->Root());
}

//searches tree for matching year and places it in vector if found
void searchYear(BSTree<Actors, string> *tree, vector<Actors> &v, int value, Node<Actors, string> * leaf)
{
    //if tree not empty
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            searchYear(tree, v, value, leaf->Left());
        }
        if (leaf->Data().year == value) {
            v.push_back(leaf->Data());
        }
        //go right if possible
        if (leaf->Right() != nullptr) {
            searchYear(tree, v, value, leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//searches tree for matching name and if found adds it to vector
void searchName(BSTree<Actors, string> *tree, vector<Actors> &v, string value, Node<Actors, string> * leaf)
{
    
    if (leaf == nullptr) {
        return;
    }
    else if (leaf->Key() == value){
        v.push_back(leaf->Data());
        if (leaf->Right() != nullptr) {
            searchName(tree, v, value, leaf->Right());
        }
        return;
    }
    else if (value < leaf->Key()){
        searchName(tree, v, value, leaf->Left());
    }
    else if (value >= leaf->Key()){
        searchName(tree, v, value, leaf->Right());;
    }
}

//dispalys contents of vector which stores search results
void displayVector(vector<Actors> v)
{
    
    if (v.size() != 0) {
        cout << "Your search yielded " << v.size() << " records:\n\n";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].name << endl;
            cout << v[i].award << endl;
            cout << v[i].film << endl;
            cout << v[i].year << endl;
            cout << v[i].isWinner << endl;
            cout << endl;
        }
    }
    else{
        cout << "No search results matching that request.\n";
    }
}

//prints updated actor/actress tree to new csv file
void writeToFile(BSTree<Actors, string> *tree, Node<Actors, string> * leaf)
{
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("newActorDatabase.csv", std::fstream::app);
    
    if (leaf != nullptr) {
        //go left if possible
        if (leaf->Left() != nullptr) {
            writeToFile(tree, leaf->Left());
        }
        outFile << leaf->Data().name << ",";
        outFile << leaf->Data().award << ",";
        if (leaf->Data().isWinner == true) {
            outFile << 1 << ",";
        }
        else{
            outFile << 0 << ",";
        }
        outFile << leaf->Data().film << ",";
        outFile << leaf->Data().year << endl;
        
        //go right if possible
        if (leaf->Right() != nullptr) {
            writeToFile(tree, leaf->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
}

//prints the first info line for new csv fle
void infoLine()
{
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("newActorDatabase.csv", std::fstream::app);
    
    outFile << "Name,Award,Winner,Film,Year" << "\n";
}

//aks user for the name of the record they want to delete
//searches for record, if found deletes first occurane of node
void deleteRecord(BSTree<Actors, string> *tree)
{
    string actor;
    cin.ignore();
    cout << "Enter the name of the actor/actress you wish to delete.\n";
    getline(cin, actor);
    
    Node<Actors, string> * newNodePtr = tree->findNode(actor);
    if (newNodePtr == nullptr) {
        cout << "Sorry actor/actress not found.\n";
    }
    else{
        cout << "Deleting first occurance of actor: " << actor << endl;
        tree->deleteNode(actor);
    }
}

//checks if results from search are > 5, if yes asks user if they want to search or display the results
void checkResults(vector<Actors> v)
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
void searchResults(vector<Actors> v)
{
    int choice = 0;
    while (choice != 6)
    {
    cout << "Which field would you like to search the results by?\n";
    cout << "1 for actor/actress name.\n";
    cout << "2 for film name.\n";
    cout << "3 for award name.\n";
    cout << "4 for year.\n";
    cout << "5 to return to previous menu.\n";
    cout << "6 to exit program.\n";
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
            //search vector by actor name
            searchResults(v, choice);
            break;
            
        case 2:
            //search vector by film name
            searchResults(v, choice);
            break;
            
        case 3:
            //search vector by award name
            searchResults(v, choice);
            break;
            
        case 4:
            //search vector by year
            searchResults(v, choice);
            break;
            
        case 5:{
            //return to previous menu
            return;
            break;
        }
        case 6:
            exit(6);
            break;
            
        default:
            break;
        }//switch
    }//while
}

//overloaded searchResults function
//once user chooses their option in the menu, that key is passed here to determine which field to search
void searchResults(vector<Actors> v, int key)
{
    //search by actor name
    if (key == 1) {
        string name;
        cin.ignore();
        cout << "Enter the actor/actress name you wish to search for.\n";
        getline(cin, name);
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].name == name) {
                cout << endl << v[i].name << endl;
                cout << v[i].film << endl;
                cout << v[i].award << endl;
                cout << v[i].year << endl;
                if (v[i].isWinner == true) {
                    cout << 1 << endl << endl;
                }
                else{
                    cout << 2 << endl << endl;
                }
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << "No results with that value.\n";
        }
    }//actor name search
    
    //film name
    else if (key == 2){
        string film;
        cin.ignore();
        cout << "Enter the film name you wish to search for.\n";
        getline(cin, film);
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].film == film) {
                cout << endl << v[i].name << endl;
                cout << v[i].film << endl;
                cout << v[i].award << endl;
                cout << v[i].year << endl;
                if (v[i].isWinner == true) {
                    cout << 1 << endl << endl;
                }
                else{
                    cout << 0 << endl << endl;
                }
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << endl << "No results with that value.\n\n";
        }
    }//film name search
    
    //award name
    else if (key == 3){
        string award;
        cin.ignore();
        cout << "Enter the award name you wish to search for.\n";
        getline(cin, award);
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].award == award) {
                cout << endl << v[i].name << endl;
                cout << v[i].film << endl;
                cout << v[i].award << endl;
                cout << v[i].year << endl;
                if (v[i].isWinner == true) {
                    cout << 1 << endl << endl;
                }
                else{
                    cout << 0 << endl << endl;
                }
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << endl << "No results with that value.\n\n";
        }
    }//award name search
    
    //year
    else if (key == 4){
        int year;
        //cin.ignore();
        cout << "Enter the year you wish to search for.\n";
        cin  >> year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> year;
        }//while choice != int
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].year == year) {
                cout << endl << v[i].name << endl;
                cout << v[i].film << endl;
                cout << v[i].award << endl;
                cout << v[i].year << endl;
                if (v[i].isWinner == true) {
                    cout << 1 << endl << endl;
                }
                else{
                    cout << 0 << endl << endl;
                }
                count++;
            }//if record found
        }//for
        if (count == 0) {
            cout << endl << "No results with that value.\n\n";
        }
    }//year search
}

//driver function for partial search
//asks user what kind of partial search they want to peform
//calls function to match the type of search
void partialSearch(BSTree<Actors, string> *tree, vector<Actors> &v)
{
    int choice = 0;
    while(choice != 6){
        cout << "Enter the field you wish to do a partial search on.\n";
        cout << "1 for actor/actress name.\n";
        cout << "2 for movie title.\n";
        cout << "3 for award name.\n";
        cout << "4 for year.\n";
        cout << "5 to return to actor/actress database.\n";
        cout << "6 to exit program.\n";
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
                v.clear();
                partialSearchString(tree, v, choice);
                checkResults(v);
                break;
                
            case 2:
                //movie title
                v.clear();
                partialSearchString(tree, v, choice);
                checkResults(v);
                break;
                
            case 3:
                //award name
                v.clear();
                partialSearchString(tree, v, choice);
                checkResults(v);
                break;
                
            case 4:
                //year
                v.clear();
                partialSearchString(tree, v, choice);
                checkResults(v);
                break;
                
            case 5:
                return;
                break;
                
            case 6:
                exit(6);
                break;
            default:
                cout << "Please enter a number 1-6" << endl;
                break;
        }//switch
    }//while
}

//key determines what kind of input to get from the user
//then the key and string value are passed into overloaded partialSearchString function
void partialSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key)
{
    if (key == 1) {
        string name;
        cin.ignore();
        cout << "Enter the actor/actress name you wish to do partial search on.\n";
        getline(cin, name);
        partialSearchString(tree, v, key, name, tree->Root());
    }
    else if (key == 2) {
        string movie;
        cin.ignore();
        cout << "Enter the movie title you wish to do a partial search on.\n";
        getline(cin, movie);
        partialSearchString(tree, v, key, movie, tree->Root());
    }
    else if (key == 3){
        string award;
        cin.ignore();
        cout << "Enter the award name you wish to do a partial search on.\n";
        getline(cin, award);
        partialSearchString(tree, v, key, award, tree->Root());
    }
    else if (key == 4){
        string year;
        cin.ignore();
        cout << "Enter the year you wish to do a partial search on.\n";
        getline(cin, year);
        partialSearchString(tree, v, key, year, tree->Root());
    }
}

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order because must ensure each node doesn't contain that value
void partialSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key, string value, Node<Actors, string> * leaf)
{
    //actor name
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
    
    //movie name
    else if (key == 2) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().film.find(value);
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
    
    //award
    if (key == 3) {
        if (leaf != nullptr) {
            //go left if possible
            if (leaf->Left() != nullptr) {
                partialSearchString(tree, v, key, value, leaf->Left());
            }
            
            unsigned long found = leaf->Data().award.find(value);
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
    
    //year
    if (key == 4) {
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
}

