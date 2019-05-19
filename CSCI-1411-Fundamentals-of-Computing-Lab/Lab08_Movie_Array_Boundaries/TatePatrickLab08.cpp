/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 08
 - Description: This program reads in movie data from a txt file, stores that info in an array of
 structs, and allows the user to add movies to the array and also display the contents of the array.
 The program prevents the user from entering elements into the array out of bounds. The MAXSIZE is
 set to 100, so the user is prevented from entering the 101st element. The user is able to search
 the list for a specific movie title, and the user also has the option of sorting the movie list by
 title alphabetically.
 - Lab Partner: Prin
 - Status: successfully compiles and runs
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Movies
{
    string title;
    int releaseYear;
    int runningTime;    //in minutes
    int rating;      //as a percent out of 100
};

void listMovies(Movies movieArray[], int &currentSize);//display contents of Movies array
Movies newMovie();
bool addMovie(Movies movieToAdd, Movies movieArray[], int &currentSize, const int MAXSIZE);
void showFile(Movies movieArray[]);//read in movies from list document
void searchList(Movies movieArray[], int numElems, string value);//search for movie
void sortMovieTitle(Movies movieArray[], int currentSize);//bubble sort
void swap(int &a, int &b);//used in sort function
void swap(string &a, string &b);//used in sort function

int currentSize = 0;

int main() {
    
    
    const int MAXSIZE = 100;    //maximum number of movies in the array
    
    Movies movie1;
    Movies movieArray[MAXSIZE];
    string temp;//variable to hold what movie title the user wants to search for
    
    int userChoice = 0;
    bool done = false;
    while (! done) {
        cout << "1. Read in movies from the file.\n";
        cout << "2. Add movies.\n";
        cout << "3. List movies.\n";
        cout << "4. Search movie list by movie title.\n";
        cout << "5. Sort movies by movie title.\n";
        cout << "6. exit.\n";
        cin  >> userChoice;
        
        switch (userChoice) {
            case 1:
                //read in data from movielist.txt file
                showFile(movieArray);
                break;
                
            case 2:
                //add a movie to the array as long as array has space
                if (currentSize < MAXSIZE) {
                    movie1 = newMovie();
                    addMovie(movie1, movieArray, currentSize, MAXSIZE);
                }
                else
                    cout << "Sorry your list is full. No more can be added.\n";
                break;
                
            case 3:
                //display movies on the list
                listMovies (movieArray, currentSize);
                break;
                
            case 4:
                //search for movies by title
                cout << "Enter the movie you are looking for.\n";
                cout << "Make sure to enter the whole title.\n";
                cin.ignore();
                getline(cin, temp);
                
                searchList(movieArray, currentSize, temp);
                
                break;
                
            case 5:
                //sort movie array and display the new sorted order
                sortMovieTitle(movieArray, currentSize);
                listMovies (movieArray, currentSize);
                break;
                
            case 6:
                exit(0);
                break;
                
            default:
                cout << "Please enter a valid value.\n";
                break;
        }//switch
    }//while
    
    return 0;
}

void listMovies(Movies movieArray[], int &currentSize){
    
    for (int i = 0; i < currentSize; i++) {
        cout << "Movie " << i + 1 << endl;
        cout << "Title: " << movieArray[i].title << endl;
        cout << "Release Year: " << movieArray[i].releaseYear << endl;
        cout << "Running time in minutes: " << movieArray[i].runningTime << endl;
        cout << "Rating: " << movieArray[i].rating << "%" << endl << endl;
    }
}

Movies newMovie(){
    
    Movies temp;
    cout << "Enter the movie name.\n";
    cin.ignore();
    getline(cin, temp.title);
    cout << "Now enter the movie release year.\n";
    cin  >> temp.releaseYear;
    cout << "Now enter the running time in minues.\n";
    cin  >> temp.runningTime;
    cout << "Now enter the rating as a whole number out of 100.\n";
    cin  >> temp.rating;
    
    return temp;
}

bool addMovie(Movies movieToAdd, Movies movieArray[], int &currentSize, const int MAXSIZE){
    currentSize++;
    if (currentSize <= MAXSIZE) {
        movieArray[currentSize - 1] = movieToAdd;
        return true;
    }
    else
        return false;
}

//this function will read in the data from the file into the array of movie structs
void showFile(Movies movieArray[]){
    
    ifstream inFile;    //input file variable to hold movielist.txt info
    
    //get file info
    inFile.open("movielist.txt");
    
    int i = 0;  //set counter to determine currentSize
    while (inFile.good()) {
        
        //get movie list and put into struct array
        getline(inFile, movieArray[i].title);
        inFile >> movieArray[i].releaseYear;
        inFile >> movieArray[i].runningTime;
        inFile >> movieArray[i].rating;
        
        i++;
        inFile.ignore();
    }//while
    
    currentSize = i;
    
    inFile.close();
    
    //display movie list
    for (int j =0; j < currentSize; j++) {
        cout << "Movie " << j+1 << endl;
        cout << "Title: " << movieArray[j].title << endl;
        cout << "Release Year: " << movieArray[j].releaseYear << endl;
        cout << "Running time in minutes: " << movieArray[j].runningTime << endl;
        cout << "Rating: " << movieArray[j].rating << "%" << endl << endl;
    }//for
}

//linear search
void searchList(Movies movieArray[], int numElems, string value){
    
    int index = 0;  //used as subscript to search array
    bool found = false; //flag to indicate if the value was found
    
    while (index < numElems) {
        if (movieArray[index].title == value) {
            found = true;
            cout << endl << "We found the movie title: " << movieArray[index].title << endl;
            cout << "It is at position " << index + 1 << " in the list.\n";
            cout << "Its release year " << movieArray[index].releaseYear << " .\n";
            cout << "Its running time is " << movieArray[index].runningTime << " minutes.\n";
            cout << "Its rating is " << movieArray[index].rating << "%.\n" << endl;
        }
        index++;
    }//while
    
    //display message if movie wasn't found
    if (found == false) {
        cout << "Sorry we could not find the movie " << value << ".\n" << endl;
    }
}

//bubble sort
void sortMovieTitle(Movies movieArray[], int currentSize)
{
    int maxElement;
    int index;
    
    for (maxElement = (currentSize - 1); maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (movieArray[index].title > movieArray[index + 1].title) {
                swap(movieArray[index].title, movieArray[index + 1].title);
                swap(movieArray[index].releaseYear, movieArray[index + 1].releaseYear);
                swap(movieArray[index].runningTime, movieArray[index + 1].runningTime);
                swap(movieArray[index].rating, movieArray[index + 1].rating);
            }//if
        }//for
    }//for
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}


