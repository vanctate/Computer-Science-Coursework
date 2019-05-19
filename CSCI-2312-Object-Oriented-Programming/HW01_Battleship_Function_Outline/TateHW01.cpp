/*
  Patrick Tate
  HW01
  CSCI 2312
*/

//Create User's Grid
  //Parameters: array
  //Return Value: none
  /* Start with empty 10x10 two dimensional array
    For each ship
        enter column and row of starting location
        enter whether the ship will be horizontal or vertical
        check to make sure ship placement doesn't run out of array bound
   */
   /* Test Plan: check starting position (column, row) and add ship's size, either 5 squares, 4 squares, two 3 squares, and one 2 square, if the starting position plus the ship's                                      size is greater than the last element in the 2D array, print an error message. Must also test to see if location is already occupied, set one char value equal to open and one char value equal to occupied, must make sure not just the starting location is open but also all adjacent spaces. If any position of the ship is equivalent to an occupied value, print an error message and prompt user to enter new location.

//Create Computer's Grid
    //Parameters: array
    //Return Value: none
    /* Start with an empty two dimensional array
        For each ship
            use a random number to determine row and column starting position
            use modulus to determine vertical or horizontal, for example if randomNum%2 == 0 then place ship horizontal
            check to make sure ship placement doesn't run out of array bound
    */
    /* Test Plan: similar checks to the user's grid, if the starting position of the ship plus the ship's size is greater than the last element, print error message and recursively call function until ship is in legal position. Must also test to see if location is already occupied, set one char value equal to open and one char value equal to occupied, must make sure not just the starting location is open but also all adjacent spaces. If any position of the ship is equivalent to an occupied value, print an error message and and continue function until legal position is obtained. */

//Copy each player's array to hold their guesses, hits and misses
     //Parameters: one player's array
     //Return Type: array
     /* Copy each players array to include ship locations and vacant spots, label as opposite players guess grid */
     /* Test Plan: to ensure the copied grid is the exact same as the original, I will print the copied array next to the original to ensure they are the same. */

//Play Game
      //Parameters: both players arrays
      //Return Type: none
      /*
            For player1, prompt guess by asking for column/row
                if guess is equivalent to occupied spot, tell them they got a hit and increment score counter by 1, since the total number of squares occupied by a player's ships is
                17, once the player's score counter reaches 17 announce they have won.
                if guess isn't a hit, place an empty marker in their guess array and inform them their hit missed.
            For player2 the same logic follows, function will run until one player's score count equals 17.
      */
      /* Test Plan: first test with a small one dimensional array and print a message for every hit and miss, then test on a small 2D array 2x2 and 3x3. Testing will involve checking the value at the desired element, for example 2 char values, one for open, one for occupied, if arr[i] == occupied then print "hit." */


//Print Array
       //Parameters: array
       //Return Type: none
       /*
            For each row
                For each column
                print the element's value, which will show either open space, or occupied by a specific ship
       */
       /* Test Plan: create a smaller array either 2x2 or 3x3 and print predetermined values it specific element locations. Once a smaller array is printed accurately, the same logic will apply to a larger array. */

//Array Boundary Checking
        //Paramters: array
        //Return Type: bool
        /*
            Take column and row info from user to determine starting location within matrix, and direction of ship (left/right horizontal or up/down vertical).
            First check to see if starting location is empty, if yes then continue, if no tell user they must select another spot.
            Add the ship's total size to the starting point to determine if ship would be out of bounds. For example, in a 10x10 matrix, if the user selects row 10 column 10 for a 5 square ship, 10+5 would be out of bounds for a vertical placement down or a horizontal placement to the right, but the user could do a horizontal placement left or a vertical placement up.
            If the ship placement is in bounds, the last check is if any of the adjacent elements are occupied. If occupied, tell user and prompt new entry.
         */
         /* Test Plan: create a smaller array of 3x3, and try inserting a 2 element sized value out of bounds, this would be done by adding 2 to the begining point, for example if you tried to place a ship at row 3 column 3 in a right horizontal direction, then element 3 + 2 = 5 and would be greater than array MAXSIZE, but a left horizontal would be acceptable if it's open because element 3 - 2 = 1, and it could also be placed upward vertical because the math is the same for that direction. */
