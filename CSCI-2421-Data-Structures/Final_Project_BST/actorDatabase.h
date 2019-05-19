/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */
#ifndef actorDatabase_h
#define actorDatabase_h

#include <vector>
#include "BSTree.h"
#include "BSTree.hpp"
#include "Node.h"

//displays the main menu within the actor database
void actorsMenu(BSTree<Actors, string> *tree);

//checks if tree is empty, if not passes Node pointer to printInOrder
void printActorTree(BSTree<Actors, string> *tree);

//prints bs tree in order keyed on strings
void printInOrder(Node<Actors, string> * leaf);

//actor info is obtained from user and added to the actor tree
void addRecord(BSTree<Actors, string> *tree);

//search for actor and if found, modify fields
//finds/modifies first occurance of an actor
void modifyRecord(BSTree<Actors, string> *tree);

//asks user which field they want to modify
void modifyField(BSTree<Actors, string> *tree, Node<Actors, string> * ptr);

//gets values from user about which field to modify
//key determines which field to obtain info for
//name has special circumstance since it is a key for the bst
void getInfo(BSTree<Actors, string> *tree, int key, Node<Actors, string> *ptr);

//asks user which field they want to sort the tree on
void sortTree(BSTree<Actors, string> *tree);

//traverses entire actor tree, places each node into newTree which is keyed on strings
void sortTreeString(Node<Actors, string> *ptr, BSTree<Actors, string> *newTree);

//traverses entire actor tree, places each node into newTree which is keyed on year
void sortTreeInt(Node<Actors, string> *ptr, BSTree<Actors, int> *newTree);

//checks if tree is empty, if not passes Node pointer to printInOrderInt
void printTreeInt(BSTree<Actors, int> *newTree);

//prints entire tree in order, keyed on ints
void printInOrderInt(Node<Actors, int> * leaf);

//driver function for complete search
//asks user what kind of complete search they want to peform
//calls function to match the type of search
void completeSearch(BSTree<Actors, string> *tree, vector<Actors> &v);

//key determines what kind of input to get from the user
//then the key and string value are passed into overloaded completeSearchString function
void completeSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key);

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order because tree is not sorted by award or movie name
void completeSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, string value, Node<Actors, string> * leaf, int key);

//obtain name to search for from user and passes name and vector into searchName function
void completeSearchName(BSTree<Actors, string> *tree, vector<Actors> &v);

//obtain year value from user and passes that value and vector into searchYear function
void completeSearchInt(BSTree<Actors, string> *tree, vector<Actors> &v);

//searches tree for matching year and places it in vector if found
void searchYear(BSTree<Actors, string> *tree, vector<Actors> &v, int value, Node<Actors, string> * leaf);

//searches tree for matching name and if found adds it to vector
void searchName(BSTree<Actors, string> *tree, vector<Actors> &v, string value, Node<Actors, string> * leaf);

//dispalys contents of vector which stores search results
void displayVector(vector<Actors> v);

//prints updated actor/actress tree to new csv file
void writeToFile(BSTree<Actors, string> *tree, Node<Actors, string> * leaf);

//prints the first info line for new csv fle
void infoLine();

//aks user for the name of the record they want to delete
//searches for record, if found deletes first occurance of node
void deleteRecord(BSTree<Actors, string> *tree);

//checks if results from search are > 5, if yes asks user if they want to search the results
void checkResults(vector<Actors> v);

//presents user with a menu choice for which field to search results by
void searchResults(vector<Actors> v);

//overloaded searchResults function
//once user chooses their option in the menu, that key is passed here to determine which field to search
void searchResults(vector<Actors> v, int key);

//driver function for partial search
//asks user what kind of partial search they want to peform
//calls function to match the type of search
void partialSearch(BSTree<Actors, string> *tree, vector<Actors> &v);

//key determines what kind of input to get from the user
//then the key and string value are passed into overloaded partialSearchString function
void partialSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key);

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order because tree is not sorted by award or movie name
void partialSearchString(BSTree<Actors, string> *tree, vector<Actors> &v, int key, string value, Node<Actors, string> * leaf);

#endif
