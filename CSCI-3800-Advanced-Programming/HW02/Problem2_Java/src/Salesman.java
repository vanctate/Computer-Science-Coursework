/*
    Patrick Tate
    CSCI 3800
    HW 02 - Problem 2

    This file defines a Salesman class that contains member variables totalWeeklySales, totalCommission,
    COMMISSIONRATE, and BASECOMMISSION. A Salesman receives a base commision of $200/week + 9% of
    their total sales.

    The main function at the bottom prompts the user for how many items they sold this week and the value
    of each item, sums all items and instantiates a Salesman object with the given values. The Salesman
    object then calls the function calculateCommission and print's their values for the week.
 */

import java.util.Scanner;

public class Salesman {
    private double totalWeeklySales;
    private double totalCommission;
    private static final double COMMISSIONRATE = 0.09;
    private static final double BASECOMMISSION = 200.00;

    public Salesman(double totalWeeklySales){
        this.totalWeeklySales = totalWeeklySales;
    }

    // get
    public double getTotalWeeklySales(){
        return this.totalWeeklySales;}

    public double getTotalCommission() {
        return totalCommission;
    }

    // set
    public void setTotalWeeklySales(double totalWeeklySales) {
        this.totalWeeklySales = totalWeeklySales;
    }

    public void setTotalCommission(double totalCommission) {
        this.totalCommission = totalCommission;
    }

    // calculate salesman's total commission
    public void calculateCommission(){
        this.totalCommission = this.BASECOMMISSION + (this.COMMISSIONRATE * this.totalWeeklySales);
    }

    // print salesman's info
    public void printSalesman(){
        double rateAsPercent = this.COMMISSIONRATE * 100;
        System.out.printf("Total weekly sales: $%.2f %n", + this.totalWeeklySales);
        System.out.println("Commission rate: " + rateAsPercent + "% of total sales.");
        System.out.printf("Base commission amount: $%.2f %n", + this.BASECOMMISSION);
        System.out.printf("Total commission this week: $%.2f %n", + this.totalCommission);
    }

    public static void main(String[] args){
        double runningTotal = 0.0;

        // obtain the total number of sales from the user
        Scanner input = new Scanner(System.in);
        System.out.println("Enter how many sales you had this week:");
        int numOfSales = input.nextInt();

        //run loop for total sales to sum each one
        int count = 0;
        while (count < numOfSales){
            System.out.println("Enter the value for sale " + (count + 1));
            Scanner in = new Scanner(System.in);
            runningTotal += in.nextDouble();
            count++;
        }//while

        Salesman temp = new Salesman(runningTotal);
        temp.calculateCommission();
        temp.printSalesman();
    }//main

}
