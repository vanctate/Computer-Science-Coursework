/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

#include "functions.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //instantiate BS Tree of Actors and load info from actors.csv file
    BSTree<Actors, string> *tree = new BSTree<Actors, string>;
    loadTree(tree);
    
    //instantiate BS Tree of Pictures and load info from pictures.csv file
    BSTree<Pictures, string> *movieTree = new BSTree<Pictures, string>;
    loadPictureTree(movieTree);
    
    //call main menu prompting using to enter either Actor or Picture database
    mainMenu(tree, movieTree);
   
    return 0;
}
