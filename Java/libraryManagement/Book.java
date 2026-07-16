public class Book {
    String title, author;
    int price, quantity, id, pages;

    @Override
    public String toString() {
        return "Book [title = " + title + ", author = " + author + ", price = " + price + ", quantity = " + quantity + "]";
    }
}
