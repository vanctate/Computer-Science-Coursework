/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */


import java.io.Serializable;
import java.util.Arrays;
import java.util.Iterator;
import java.util.function.Consumer;

public abstract class ItemList implements Iterable<Item>, Serializable
{
    private Item[] items;
    private int capacity;
    private int size;

    public ItemList() {
        this.items = new Item[100];
        this.capacity = 100;
        this.size = 0;

    }

    public ItemList(int cap) {
        this.items = new Item[cap];
        this.capacity = cap;
        this.size = 0;
    }

    public ItemList(Item[] items) {
        this.items = items;
    }

    public Item[] getItems() {
        return items;
    }

    public void setItems(Item[] items) {
        this.items = items;
    }

    public boolean addItem(Item newItem)
    {
        if (size == capacity) {
            System.out.println("List full");
            return false;
        }
        for (Item i : this)
        {
            if (newItem.getName().equals(i.getName())) {
                System.out.println("Item already present");
                return false;
            }
        }

        items[size] = newItem;
        return true;
    }

    public void removeItem(Item existingItem)
    {
        ItemIterator it = this.iterator();
        if (it.currentItem.getName().equals(existingItem.getName()))
        {
            it.remove();
        }
        while (it.hasNext()) {
            if (it.currentItem.getName().equals(existingItem.getName()))
            {
                it.remove();
                System.out.println("Item removed");
                return;
            }
            it.next();
        }
        System.out.println("Not found");
        return;
    }

    @Override
    public ItemIterator iterator()
    {
        return new ItemIterator(this);
    }

    @Override
    public String toString() {
        String s = "Item Name\tItem ID\tPrice\tDept No.\n";
        for (Item i : items)
        {
            s += i.toString();
            s += "\n";
        }
        return s;
    }
}
