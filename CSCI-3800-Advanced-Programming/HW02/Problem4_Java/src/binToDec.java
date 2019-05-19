/*
    Patrick Tate
    CSCI 3800
    HW02 - Problem 4
    This program prompts the user for a binary number and prints the equivalent decimal value.
    If the user enters any numeric value other than 0/1, or any non numeric value, the program
    tells the user to only enter valid binary values and quits.
 */

import java.util.Scanner;

public class binToDec {
    public static void main(String[] args){

        // obtain a binary string from the user
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a binary number:");
        String binaryString = input.nextLine();

        // convert string to an array so each element can be accessed
        String[] binArray = binaryString.split("");

        // var to hold the value of the decimal value as it is calculated
        double decimalTotal = 0.0;

        // loop through the array calculating the decimal value of each bit
        for(int i = binArray.length - 1; i >= 0; i--){

            // check for incorrect bits (only bit values of 1/0 accepted)
            try {
                int temp = Integer.parseInt(binArray[i]);
                if ((temp < 0) || (temp > 1)) {
                    System.out.println("Only enter valid binary values (0/1)");
                    System.exit(0);
                }
                else {
                    // calculate the value of each bit
                    decimalTotal += (Integer.parseInt(binArray[i]) * (Math.pow(2.0,binArray.length - i - 1)));
                }
            }
            catch (NumberFormatException e) {
                System.out.println("This is not a valid number");
                System.exit(0);
            }
        }// for

        System.out.println("The decimal equivalent of " + binaryString + " is: " + decimalTotal);

    }
}
