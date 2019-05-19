/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

import java.util.ArrayList;
import java.util.List;
public abstract class Department {

    private String name;
    private long departmentID;
    private ArrayList<Item> items;
    private ArrayList<Customer> customers;
    private ArrayList<Observer> watchListCustomers;


    public ArrayList<Customer> getCustomers(){
        return this.customers;
    }

    public ArrayList<Observer> getWatchListCustomers(){
        return this.watchListCustomers;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public long getDepartmentID() {
        return departmentID;
    }
    public void setDepartmentID(long departmentID) {
        this.departmentID = departmentID;
    }

    // add customer to the department
    public void addCustomer(Customer c){
        this.customers.add(c);
    }
    public void addCustomerWatchlList(Observer customer){
        this.watchListCustomers.add(customer);
    }
    public void removeCustomer(Customer c){
        if(this.customers.contains(c)){
            this.customers.remove(c);
        }
    }
    public void removeCustFromWatchList(Observer c){
        if(this.watchListCustomers.contains(c)){
            this.watchListCustomers.remove(c);
        }
    }

    public void enter(Customer customer){
        this.customers.add(customer);
    }

    public void exit (Customer customer){
        if(this.customers.contains(customer)){
            this.customers.remove(customer);
        }
    }
    public ArrayList<Item> getItems() {
        return this.items;
    }
    public void setItems(ArrayList<Item> items) {
        this.items = items;
    }
    public void notifyCustomers() {
        for (Item i : items) {
            if (i.getOnSale()) {
                for(Observer obs : this.watchListCustomers)
                    obs.update(i);
            }
        }
    }
}

