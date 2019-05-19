/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#ifndef pictureDatabase_h
#define pictureDatabase_h

#include <vector>
#include "BSTree.h"
#include "BSTree.hpp"
#include "Node.h"

//displays the main menu within the pictures database
void picturseMenu(BSTree<Pictures, string> *tree);

//checks if tree is empty, if not empty passes root pointer to printInOrder function
void printPictureTree(BSTree<Pictures, string> *tree);

//prints the entire tree in order keyed on strings
void printInOrder(Node<Pictures, string> * leaf);

//picture info is obtained from user and added to the picture tree
void addRecord(BSTree<Pictures, string> *tree);

//search for picture and if found, modify fields
void modifyRecord(BSTree<Pictures, string> *tree);

//asks user which field they want to modify
void modifyField(BSTree<Pictures, string> *tree, Node<Pictures, string> * leaf);

//gets values from user about which field to modify
//key determines which field to obtain info for
//name has special circumstance since it is a key for the bst
void getInfo(BSTree<Pictures, string> *tree, int key, Node<Pictures, string> *leaf);

//driver function for complete search
//asks user what kind of complete search they want to peform
//calls function to match the type of search
void completeSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v);

//key determines what kind of input to get from the user
//then the key and string value are passed into overloaded completeSearchString function
void completeSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key);

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchString(BSTree<Pictures, string> *tree, vector<Pictures> &v, string value, Node<Pictures, string> * leaf, int key);

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchInt(BSTree<Pictures, string> *tree, vector<Pictures> &v, int value, Node<Pictures, string> * leaf, int key);

//key deterines which string to search for, either award name or movie name
//search traverses entire tree in order
//if searched value is a match, it is added to the vector of Picture structs
void completeSearchDouble(BSTree<Pictures, string> *tree, vector<Pictures> &v, double value, Node<Pictures, string> * leaf, int key);

//driver function for partial search
//asks user what kind of partial search they want to peform
//calls function to match the type of search
void partialSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v);

//gets value from user on the field they want to partial search on
void partialSearch(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key);

//searches entire tree in order to find an occurance of searched value
//if searched value is found it is placed in vector of Picture structs
void partialSearchString(BSTree<Pictures, string> *tree, vector<Pictures> &v, int key, string value, Node<Pictures, string> * leaf);

//prints the first info line for new csv fle
void infoLinePicture();

//prints updated actor/actress tree to new csv file
void writeToFile(BSTree<Pictures, string> *tree, Node<Pictures, string> * leaf);

//if results from search are < 5 they are printed, if > 5 user can re-search results or print all
void checkResults(vector<Pictures> v);

//dispalys contents of vector which stores search results
void displayVector(vector<Pictures> v);

//presents user with a menu choice for which field to search results by
void searchResults(vector<Pictures> v);

//overloaded searchResults function
//once user chooses their option in the menu, that key is passed here to determine which field to search
void searchResults(vector<Pictures> v, int key);

//aks user for the name of the picture they want to delete
//searches for record, if found deletes node
void deleteRecord(BSTree<Pictures, string> *tree);

//asks user which field they want to sort the tree on
void sortTree(BSTree<Pictures, string> *tree);

//traverses entire picture tree, places each node into newTree which is keyed on strings
void sortTreeString(Node<Pictures, string> *ptr, BSTree<Pictures, string> *newTree, int key);

//traverses entire picture tree, places each node into newTree which is keyed on ints
void sortTreeInt(Node<Pictures, string> *ptr, BSTree<Pictures, int> *newTree, int key);

//checks if bs tree is empty, if not passes Node pointer to printInOrderInt
void printTreeInt(BSTree<Pictures, int> *newTree);

//prints bst in order keyed by int
void printInOrderInt(Node<Pictures, int> * leaf);

//traverses entire picture tree, places each node into newTree which is keyed on double
void sortTreeDouble(Node<Pictures, string> *ptr, BSTree<Pictures, double> *newTree);

//checks if bst is empty, if not sends Node pointer to printInOrderDouble
void printTreeDouble(BSTree<Pictures, double> *newTree);

//prints bst in order keyed by double
void printInOrderDouble(Node<Pictures, double> * leaf);

#endif /* pictureDatabase_h */
