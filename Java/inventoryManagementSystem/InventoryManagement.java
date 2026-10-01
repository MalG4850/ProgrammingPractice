import java.util.*;

public class InventoryManagement {
    static Scanner scanner = new Scanner(System.in);
    static InventoryOperations ops = new InventoryOperations();

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n===== SELECT DATA STRUCTURE =====");
            System.out.println("1. ArrayList");
            System.out.println("2. LinkedList");
            System.out.println("3. PriorityQueue (by price)");
            System.out.println("4. ArrayDeque");
            System.out.println("5. TreeSet");
            System.out.println("6. HashSet");
            System.out.println("7. HashMap (key = ID)");
            System.out.println("0. Exit");
            System.out.print("Choose: ");
            int structChoice = readInt();
            if (structChoice == 0) break;

            Object inventory = createStructure(structChoice);
            if (inventory == null) continue;

            while (true) {
                System.out.println("\n----- OPERATIONS -----");
                System.out.println("1. Add");
                System.out.println("2. Remove");
                System.out.println("3. Update");
                System.out.println("4. Check Duplicates");
                System.out.println("5. Display");
                System.out.println("0. Back to structure menu");
                System.out.print("Choose: ");
                int opChoice = readInt();
                if (opChoice == 0) break;

                switch (opChoice) {
                    case 1 -> addProduct(inventory);
                    case 2 -> removeProduct(inventory);
                    case 3 -> updateProduct(inventory);
                    case 4 -> checkDuplicates(inventory);
                    case 5 -> displayMenu(inventory);
                    default -> System.out.println("Invalid option.");
                }
            }
        }
        System.out.println("Goodbye!");
    }

    // -------- Structure creation --------
    private static Object createStructure(int choice) {
        return switch (choice) {
            case 1 -> new ArrayList<Product>();
            case 2 -> new LinkedList<Product>();
            case 3 -> new PriorityQueue<>(Product.priceComparator);
            case 4 -> new ArrayDeque<Product>();
            case 5 -> new TreeSet<Product>();
            case 6 -> new HashSet<Product>();
            case 7 -> new HashMap<Long, Product>();
            default -> {
                System.out.println("Invalid choice.");
                yield null;
            }
        };
    }

    // -------- Input helpers --------
    private static int readInt() {
        while (true) {
            try {
                return Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Enter a valid integer: ");
            }
        }
    }

    private static long readLong(String prompt) {
        System.out.print(prompt);
        while (true) {
            try {
                return Long.parseLong(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Enter a valid number: ");
            }
        }
    }

    private static Product readProduct() {
        long id = readLong("ID: ");
        System.out.print("Name: ");
        String name = scanner.nextLine().trim();
        Category category = readCategory();
        int price = (int) readLong("Price: ");
        int qty = (int) readLong("Quantity: ");
        return new Product(id, name, category, price, qty);
    }

    private static Category readCategory() {
        while (true) {
            System.out.print("Category (ELECTRONICS, GROCERIES, CLOTHING): ");
            String s = scanner.nextLine().trim().toUpperCase();
            try {
                return Category.valueOf(s);
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid category. Try again.");
            }
        }
    }

    // -------- Operation delegates --------
    private static void addProduct(Object inventory) {
        Product p = readProduct();
        if (inventory instanceof Collection<?> c) {
            @SuppressWarnings("unchecked")
            Collection<Product> col = (Collection<Product>) c;
            ops.addInventory(col, p);
        } else if (inventory instanceof Map<?, ?> m) {
            @SuppressWarnings("unchecked")
            Map<Long, Product> map = (Map<Long, Product>) m;
            ops.addInventory(map, p);
        }
    }

    private static void removeProduct(Object inventory) {
        long id = readLong("Enter ID to remove: ");
        if (inventory instanceof Collection<?> c) {
            @SuppressWarnings("unchecked")
            Collection<Product> col = (Collection<Product>) c;
            ops.deleteInventory(col, id);
        } else if (inventory instanceof Map<?, ?> m) {
            @SuppressWarnings("unchecked")
            Map<Long, Product> map = (Map<Long, Product>) m;
            ops.deleteInventory(map, id);
        }
    }

    private static void updateProduct(Object inventory) {
        long id = readLong("Enter ID to update: ");
        System.out.println("Enter new product details:");
        Product updated = readProduct();
        updated.id = id; // keep same ID
        if (inventory instanceof Collection<?> c) {
            @SuppressWarnings("unchecked")
            Collection<Product> col = (Collection<Product>) c;
            ops.updateInventory(col, id, updated);
        } else if (inventory instanceof Map<?, ?> m) {
            @SuppressWarnings("unchecked")
            Map<Long, Product> map = (Map<Long, Product>) m;
            ops.updateInventory(map, id, updated);
        }
    }

    private static void checkDuplicates(Object inventory) {
        if (inventory instanceof Collection<?> c) {
            @SuppressWarnings("unchecked")
            Collection<Product> col = (Collection<Product>) c;
            ops.checkDuplicates(col);
        } else if (inventory instanceof Map<?, ?> m) {
            @SuppressWarnings("unchecked")
            Map<Long, Product> map = (Map<Long, Product>) m;
            ops.checkDuplicates(map);
        }
    }

    private static void displayMenu(Object inventory) {
        System.out.println("1. Normal display");
        System.out.println("2. Iterator display");
        System.out.print("Choose: ");
        int d = readInt();
        if (d == 1) {
            if (inventory instanceof Collection<?> c) {
                @SuppressWarnings("unchecked")
                Collection<Product> col = (Collection<Product>) c;
                ops.defaultDisplay(col);
            } else if (inventory instanceof Map<?, ?> m) {
                @SuppressWarnings("unchecked")
                Map<Long, Product> map = (Map<Long, Product>) m;
                ops.defaultDisplay(map);
            }
        } else if (d == 2) {
            if (inventory instanceof Collection<?> c) {
                @SuppressWarnings("unchecked")
                Collection<Product> col = (Collection<Product>) c;
                ops.iterativeDisplay(col);
            } else if (inventory instanceof Map<?, ?> m) {
                @SuppressWarnings("unchecked")
                Map<Long, Product> map = (Map<Long, Product>) m;
                ops.iterativeDisplay(map);
            }
        } else {
            System.out.println("Invalid.");
        }
    }
}
