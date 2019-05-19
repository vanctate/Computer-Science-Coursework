/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */


import java.beans.Customizer;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Store {

    private String name;
    private ArrayList<Department> departments;
    private ArrayList<Customer> customers;

    public Store(){
        this.name = "";
        this.departments = new ArrayList<Department>();
        this.customers = new ArrayList<Customer>();
    }

    // **********************
    // getters
    public String getName() {
        return name;
    }
    public ArrayList<Department> getDepartments(){
        return this.departments;
    }
    public ArrayList<Customer> getCustomer(){
        return this.customers;
    }


    // **********************
    // setters
    public void setName(String name) {
        this.name = name;
    }

    // customer entering the store is added to the Store's arrayList of customers
    public void enter(Customer customer){
        customers.add(customer);
    }

    // scan arrayList of customers and remove customer whose name matches
    public void exit(Customer c){
        for(Customer customer : this.customers){
            if(c.getName().equals(customer.getName())){
                this.customers.remove(customer);
            }
        }
    }


    public void addDepartment(Department dpt){
        // add the department to the store
        this.departments.add(dpt);


    }

    public void save(String outFile) throws IOException {

        PrintWriter out = new PrintWriter(new FileWriter(outFile));

        // scan through each department
        for (Department d : this.departments)
        {
            out.println("Department :" + d.getName());

            // print all the department's customers
            out.println("Department Customers: " );
            // scan through each department's customer list
            for(Customer c : d.getCustomers())
            {
                out.println(c.getName());
            }
        }
        out.close();
    }


}
