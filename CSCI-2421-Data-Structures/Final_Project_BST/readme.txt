*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSCI 2421
*  Due Date  :  May 2 2018
*  Final Project
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

	This program utilizes the templated BSTree class to read in two csv files into two 
separate binary search trees. A binary search tree utilizing Actor structs is read in from 
actor-actress.csv and placed into a binary search tree sorted on the actor's name. A  
separate binary search tree utilizing Picture structs is read in from pictures.csv. Both
binary search trees utilize a specific struct for their information, as well as the 
templated Node class, where each Node contains data of templated DATATYPE, a KEYTYPE key,
and a left, right, and parent Node pointer. 
	Once the data from the csv files is read in, the user is prompted with a main menu 
containing three options, 1 enter the actor/actress database, 2 enter the pictures 
database, or 3 exit the program. Once in either database, they both have the same options
the user can choose from, 1 add a record, 2 search for an actor/picture by name and modify
the fields, 3 search for an actor/picture and delete the record, 4 sort and print the 
database by any sortable field, 5 do a complete search on any searchable field, 6 do a 
partial search on any searchable field, 7 write the updated database to a new csv file, 8 
print the updated database, 9 return to main menu, and 10 exit program. 
	Each database is a binary search tree of either Actor or Picture nodes, both sorted on
the string value of their name. All the functionality within the database mentioned above 
involves manipulating/searching/printing the binary search tree in some way. 
	Some clarification on each option's functionality:
		- option 1: info is obtained from the user and added to the already existing 
		binary search tree
		
		- option 2: search for record based on actor/picture name and modify fields, the 
		user can modify any field and the data of that record will be changed. If a record
		name has more than one occurrence, only the first occurrence will be changed. If 
		the user wishes to alter the record's name, all the record's info will be copied, 
		then the node will be deleted and added again with the new name, since the tree is
		sorted by name.
		
		- option 3: search for the record based on actor/picture name and delete the
		record, if a record name has more than one occurrence, only the first occurrence 
		will be deleted
		
		- option 4: the user can sort the info from the existing tree into a new tree and
		the new tree is printed in order. Note this doesn't change the existing tree or
		the database, it only sorts the data into a new tree that may be keyed on a 
		string, int, or double value.
		
		- option 5: a complete search on any searchable field. What the user enters must
		match exactly the value, for example searching "Brad" would not return results for
		Brad Pitt, etc. If the search is found it is placed into a vector of Actor/Picture
		structs, and if there are 5 or less results, all their info is printed, if there
		are more than 5 results, the user has the option to re-search the results or just
		display the results.
		
		- option 6: partial search on any searchable field. Search just has to contain an
		instance of the search, for example "Brad" would turn up all Brad Pitt results as
		well as any other actors with Brad in their name, searching "1" on a picture 
		rating would yield any result with 1 in it, such as 1.0, 9.1, 7.1, etc. If a 
		record is found, it is placed into a vector of Actor/Picture structs, and if there
		are less than 5 records all the records are displayed, if there are more than 5 
		records, the user has the option to re-search the results or simply display the
		results.
		
		- option 7: write the updated database/tree to a new csv file. Whatever changes
		have been made to the database will be sent to the new csv file, including adding,
		deleting, modifying records etc.
		
		- option 8: print the updated database. The binary search tree is printed in 
		order, keyed on name, in alphabetical order.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program instantiates an actor BS tree pointer, a 
   Picture BS tree pointer, loads both trees with info from csv files, and passes both 
   trees into the mainMenu function.

Name:  functions.h
   Contains the definition for the loadTree, loadPictureTree, and mainMenu functions.

Name: functions.cpp
   Defines the loadTree, loadPictureTree, and mainMenu functions. loadTree loads a BS tree
   of Actor Nodes from actor-actress.csv, loadPictureTree loads a BS tree of Picture Nodes
   from pictures.csv, mainMenu prompts the user with 3 options, 1 enter actor database, 2
   enter picture database, 3 exit program.
   
Name: BSTree.h
    Contains the definition for the templated BSTree class.

Name: BSTree.hpp
    Defines and implements the templated BSTree class. The destructor, clear, delete node, 
    add node, search, and print functions are all defined. 
    
Name: Node.h
	Contains the definition of the templated Node class and the Actors struct and the
	Pictures struct. The Node class contains data of templated DATATYPE, as well as 
	templated key of KEYTYPE, a left, right, and parent pointer.

Name: pictureDatabase.h
	Contains the definition for the picture database functions.

Name: pictureDatabase.cpp
	Defines and implements all the functionality within the picture data base. Functions 
	are defined for adding a record, deleting a record, modifying a record, print tree,
	sorting tree, complete search, partial search, and writing tree to new csv file.

Name: actorDatabase.h
	Contains the definition for the actor database functions.

Name: actorDatabase.cpp
	Defines and implements all the functionality within the actor data base. Functions 
	are defined for adding a record, deleting a record, modifying a record, print tree,
	sorting tree, complete search, partial search, and writing tree to new csv file.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
