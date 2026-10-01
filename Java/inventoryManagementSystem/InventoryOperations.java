import java.util.*;

public class InventoryOperations {

    // -------- Collection based operations --------
    public void addInventory(Collection<Product> inventory, Product product) {
        inventory.add(product);
        System.out.println("Product added.");
    }

    public void deleteInventory(Collection<Product> inventory, long id) {
        Iterator<Product> it = inventory.iterator();
        boolean found = false;
        while (it.hasNext()) {
            if (it.next().id == id) {
                it.remove();
                found = true;
                break;
            }
        }
        System.out.println(found ? "Product removed." : "Product not found.");
    }

    public void updateInventory(Collection<Product> inventory, long id, Product updated) {
        for (Product p : inventory) {
            if (p.id == id) {
                p.name = updated.name;
                p.category = updated.category;
                p.price = updated.price;
                p.quantity = updated.quantity;
                System.out.println("Product updated.");
                return;
            }
        }
        System.out.println("Product not found.");
    }

    public void checkDuplicates(Collection<Product> inventory) {
        Set<String> seen = new HashSet<>();
        boolean any = false;
        for (Product p : inventory) {
            String key = p.name.toLowerCase() + "#" + p.category;
            if (!seen.add(key)) {
                System.out.println("Duplicate found: " + p);
                any = true;
            }
        }
        if (!any) System.out.println("No duplicates.");
    }

    public void defaultDisplay(Collection<Product> inventory) {
        if (inventory.isEmpty()) {
            System.out.println("Inventory empty.");
            return;
        }
        for (Product p : inventory) {
            System.out.print(p);
        }
    }

    public void iterativeDisplay(Collection<Product> inventory) {
        if (inventory.isEmpty()) {
            System.out.println("Inventory empty.");
            return;
        }
        Iterator<Product> it = inventory.iterator();
        while (it.hasNext()) {
            System.out.print(it.next());
        }
    }

    // -------- Map (HashMap) specific operations --------
    public void addInventory(Map<Long, Product> inventory, Product product) {
        if (inventory.containsKey(product.id)) {
            System.out.println("Product with this ID already exists.");
        } else {
            inventory.put(product.id, product);
            System.out.println("Product added.");
        }
    }

    public void deleteInventory(Map<Long, Product> inventory, long id) {
        if (inventory.remove(id) != null) {
            System.out.println("Product removed.");
        } else {
            System.out.println("Product not found.");
        }
    }

    public void updateInventory(Map<Long, Product> inventory, long id, Product updated) {
        if (inventory.containsKey(id)) {
            inventory.put(id, updated);
            System.out.println("Product updated.");
        } else {
            System.out.println("Product not found.");
        }
    }

    public void checkDuplicates(Map<Long, Product> inventory) {
        Set<String> seen = new HashSet<>();
        boolean any = false;
        for (Product p : inventory.values()) {
            String key = p.name.toLowerCase() + "#" + p.category;
            if (!seen.add(key)) {
                System.out.println("Duplicate found: " + p);
                any = true;
            }
        }
        if (!any) System.out.println("No duplicates.");
    }

    public void defaultDisplay(Map<Long, Product> inventory) {
        if (inventory.isEmpty()) {
            System.out.println("Inventory empty.");
            return;
        }
        for (Product p : inventory.values()) {
            System.out.print(p);
        }
    }

    public void iterativeDisplay(Map<Long, Product> inventory) {
        if (inventory.isEmpty()) {
            System.out.println("Inventory empty.");
            return;
        }
        Iterator<Product> it = inventory.values().iterator();
        while (it.hasNext()) {
            System.out.print(it.next());
        }
    }
}
