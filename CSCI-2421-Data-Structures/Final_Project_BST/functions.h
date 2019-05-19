/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#ifndef functions_h
#define functions_h
#include "actorDatabase.h"
#include "pictureDatabase.h"
#include <string>
#include <iostream>
#include <fstream>

//loads bst with actor-actress.csv
void loadTree(BSTree<Actors, string> *tree);

//loads bst with pictures.csv
void loadPictureTree(BSTree<Pictures, string> *tree);

//the first menu the user encounters
//3 options, 1 enter actor database, 2 enter pictures database, 3 exit
void mainMenu(BSTree<Actors, string> *actorTree, BSTree<Pictures, string> *pictureTree);

#endif
