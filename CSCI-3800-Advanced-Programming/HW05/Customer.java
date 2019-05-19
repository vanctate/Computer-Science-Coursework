/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

import java.util.List;

public class Customer {

    protected String name;
    protected WishList wishList;
    protected ShoppingCart shoppingCart;
    protected Department department;

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {

        return name;
    }

    public Department getDepartment() {

        return department;
    }

    public ShoppingCart getShoppingCart() {

        return shoppingCart;
    }

    public void setDepartment(Department department) {

        this.department = department;
    }

    public void setShoppingCart(ShoppingCart shoppingCart) {

        this.shoppingCart = shoppingCart;
    }

    public void setWishList(WishList wishList) {

        this.wishList = wishList;
    }

    public WishList getWishList() {

        return wishList;
    }
    public String toString() {

        return "Customer{" +"name='" + name + '}';
    }

}

