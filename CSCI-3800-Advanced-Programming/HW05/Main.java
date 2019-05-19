/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

import java.awt.print.Book;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.*;

public class Main {



    //write customer object to file
    public static void writeToFileAndRead(Customer c) throws IOException {

        File aFile = new File("customerObject.ser"); //File to store the object


        c.setName("Van Tate");
        Item dvd = new Item();
        dvd.setPrice(99.99);
        Item[] wish = new Item[1];
        wish[0] = dvd;
        WishList cWish = new WishList(wish);
        c.setWishList(cWish);


        // *******************  WRITING  *************
        System.out.println("Serializing Person:\n"+c.getName());


        ObjectOutputStream oos;

        try {
            //Opening Stream to save objects to file.
            oos = new ObjectOutputStream( new FileOutputStream(aFile) );

            oos.writeObject( c ); // write the object
            oos.close(); //After writing the object the output stream must be closed.
        }
        catch (NullPointerException e){ e.printStackTrace();} catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Object Saved to File: "+ aFile.getAbsolutePath());


        // *********************************

        System.out.println("Reading Object from File: " + aFile.toString());
        ObjectInputStream ios=null;
        try{
            //Open Object Input File Stream from aFile to read objects
            ios = new ObjectInputStream(new FileInputStream(aFile));

            Customer readInstance = (Customer) ios.readObject(); //Read Object from File

            System.out.println("De-serialized Customer:\n"+readInstance);
        }
        catch (ClassNotFoundException e){ e.printStackTrace();}
        finally{
            assert ios != null;
            ios.close();    //After processing the object (or cast error) the input stream must be closed.
        }

    }



    public static void main(String[] args) throws IOException {

        Scanner reader = new Scanner(System.in);

        Item[] itemList = new Item[100];

        //create store
        Store store = new Store();

        //create department
        BookDepartment bookDepartment = BookDepartment.instance();
        MusicDepartment musicDepartment = MusicDepartment.instance();
        VideoDepartment videoDepartment = VideoDepartment.instance();
        SoftwareDepartment softwareDepartment = SoftwareDepartment.instance();

        store.addDepartment(bookDepartment);
        store.addDepartment(musicDepartment);
        store.addDepartment(videoDepartment);

        Item book1 = new Item();
        Item book2 = new Item();
        Item book3 = new Item();

        book1.setName("Dragon Lance");
        book1.setPrice(6);
        book1.setItemID(101);

        book2.setName("Fight Club");
        book2.setPrice(99.99);
        book2.setItemID(102);

        book3.setName("Lord of the Rings");
        book3.setPrice(10);
        book3.setItemID(103);

        itemList[0] = book1;
        itemList[1] = book2;
        itemList[2] = book3;

        ArrayList<Item> items = new ArrayList<>();
        for(int i = 0; i < itemList.length; i++){
            items.add(itemList[i]);
        }

        boolean run = true;
        while(run) {
            System.out.println("\nMain menu");
            System.out.println("Press 1: Watch Lists");
            System.out.println("2: Print Shopping Cart");
            System.out.println("3: Visit all departments");
            System.out.println("4: Read and Write Customer object to .ser file");
            System.out.println("5: exit program");
            String option = reader.next();
            Customer customer = new Customer();

            switch (option) {
                case "1":
                    //2 new observers
                    Observer o1 = new Observer();
                    Observer o2 = new Observer();

                    o1.setName("Spike Spiegel");
                    o2.setName("Van Tate");

                    //add observers to book department
                    bookDepartment.addCustomerWatchlList(o1);
                    bookDepartment.addCustomerWatchlList(o2);

                    //add item list to book department
                    bookDepartment.setItems(items);

                    //change price
                    System.out.println("Item price before:");
                    if(items.contains(book1)){
                        System.out.println(book1.getPrice());
                        book1.setPrice(999.99);
                    }

                    System.out.println("Item price after change to $999.99:");
                    System.out.println(book1.getPrice()); //print out changed price

                    //remove observers from department
                    System.out.println("Watch list before remove:");
                    System.out.println(bookDepartment.getWatchListCustomers()); //print before remove

                    System.out.println("After removing Van Tate:");
                    bookDepartment.removeCustFromWatchList(o2);
                    System.out.println(bookDepartment.getWatchListCustomers()); //print after remove

                    //second time to change price
                    System.out.println("Item price before:");
                    if(items.contains(book2)){
                        System.out.println(book2.getPrice());
                        book1.setPrice(100.99);
                    } //price before

                    System.out.println("Item price after change to 100.99:");
                    System.out.println(book2.getPrice());
                    break;
                case "2": //display shopping cart
                    Customer c = new Customer();

                    System.out.println("Customer shopping cart before:");

                    ShoppingCart s = new ShoppingCart(itemList);
                    System.out.println("Shopping cart: ");
                    //add items to shopping cart
                    s.addItem(book1);
                    s.addItem(book2);
                    s.addItem(book3);
                    //add 3 items to customer shopping cart
                    c.setShoppingCart(s);
                    //print customer shopping cart
                    System.out.println("Customer shopping cart after:");
                    c.getShoppingCart();
                    break;
                case "3":
                    //add software department to the store
                    System.out.println("First add Software Department:");
                    store.addDepartment(softwareDepartment); //add first time
                    System.out.println("Second add Software Department:");
                    store.addDepartment(softwareDepartment); //add second time
                    //print departments list
                    System.out.println("All Departments in the store:");
                    store.getDepartments();
                    break;

                case "4":
                    writeToFileAndRead(customer);
                    break;


                case "5":
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid input. Please enter again.");
                    break;
            }

        }



    }
}

