import java.util.Comparator;

enum Category {
    ELECTRONICS, GROCERIES, CLOTHING
}

public class Product implements Comparable<Product> {
    long id;
    String name;
    Category category;
    int price, quantity;

    public Product(long id, String name, Category category, int price, int quantity) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.price = price;
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return "========== Product Info ==========\n\n" +
               "ID: " + id +
               "\nName: " + name +
               "\nCategory: " + category +
               "\nPrice: " + price +
               "\nQuantity (in-stock): " + quantity + "\n\n";
    }

    @Override
    public int compareTo(Product other) {
        return Long.compare(this.id, other.id);
    }

    public static Comparator<Product> priceComparator = Comparator.comparingInt(p -> p.price);
}
