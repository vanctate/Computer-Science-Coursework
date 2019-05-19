/*
    - Patrick Tate
    - CSCI 3800
    - HW 2 - Problem 5
    - This program uses a fixed population growth rate of 1.2% (based on the World Bank's estimate) to estimate the
    population for the next 75 years, and how much it grew each year. I start with our estimated current population
    of 7.6 billion. The results are printed in a column format of "Year - Population - Increase Amount." A message
    is printed for the year when the population doubles.
 */

public class WorldPopulation {

    public static void main(String[] args) {

        // starting variables to calculate the population
        double GROWTH_RATE = 1.012; // 1.2% but used 1.012 for easy calculations
        double currentPop = 7600000000.00; // current world population estimate
        int year = 2018; // current year
        String dummy = "-"; // put into the "Increase Amount" column for the first year

        // variables for determining when the population doubles
        double firstPop = currentPop; // keep track of the current population
        double popDouble = 0.0;
        int yearDouble = 0;
        boolean first = true;

        //print column headers and the first year
        System.out.println("Year       Population           Increase Amount");
        System.out.printf("%-10d %-20f %-20s", year,currentPop,dummy);

        // estimate population for the next 75 years
        while (year < 2093) {

            // calculate the new population and how much it grew
            double previousPop = currentPop;
            currentPop = currentPop * GROWTH_RATE;
            double popGrowth = currentPop - previousPop;
            year++;

            // print the calculated values
            System.out.println();
            System.out.printf("%-10d %-20f %-20f", year,currentPop,popGrowth);

            // find when population doubles
            if (currentPop > (firstPop * 2)){
                if (first) {
                    popDouble = currentPop;
                    yearDouble = year;
                    first = false;
                }
            }

        }//while
        System.out.println();
        System.out.println();
        System.out.println("Population doubles in year " + yearDouble);

    }
}
