import java.util.Scanner;

public class libManSys {
    Scanner input = new Scanner(System.in);
    Book[] books = new Book[100];
    int count = 0;

    public void addBook() {
        Book b = new Book();
        System.out.print("Enter Book ID: ");
        b.id = input.nextInt();
        input.nextLine();

        System.out.print("Enter Book Name: ");
        b.title = input.nextLine();

        System.out.print("Enter Author Name: ");
        b.author = input.nextLine();

        System.out.print("Enter Quantity: ");
        b.quantity = input.nextInt();
        input.nextLine();

        System.out.print("Enter Price: ");
        b.price = input.nextInt();
        input.nextLine();

        System.out.print("Enter Pages: ");
        b.pages = input.nextInt();
        input.nextLine();

        books[count] = b;
        count++;
        System.out.println("Book added successfully!");
    }

    public void deleteBook() {
        System.out.print("Enter Book ID to delete: ");
        int id = input.nextInt();
        input.nextLine();

        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }
                books[count - 1] = null;
                count--;
                found = true;
                System.out.println("Book deleted successfully!");
                break;
            }
        }
        if (!found) {
            System.out.println("Book Not Found");
        }
    }

    public void updateBook() {
        System.out.print("Enter Book ID to update: ");
        int id = input.nextInt();
        input.nextLine();

        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                System.out.print("Enter new Book Name: ");
                books[i].title = input.nextLine();

                System.out.print("Enter new Author Name: ");
                books[i].author = input.nextLine();

                System.out.print("Enter new Quantity: ");
                books[i].quantity = input.nextInt();
                input.nextLine();

                System.out.print("Enter new Price: ");
                books[i].price = input.nextInt();
                input.nextLine();

                System.out.print("Enter new Pages: ");
                books[i].pages = input.nextInt();
                input.nextLine();

                System.out.println("Book updated successfully!");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Book Not Found");
        }
    }

    public void searchBook() {
        System.out.print("Enter Book ID to search: ");
        int id = input.nextInt();
        input.nextLine();

        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                System.out.println("Book ID: " + books[i].id);
                System.out.println("Book Name: " + books[i].title);
                System.out.println("Author: " + books[i].author);
                System.out.println("Quantity: " + books[i].quantity);
                System.out.println("Price: " + books[i].price);
                System.out.println("Pages: " + books[i].pages);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Book Not Found");
        }
    }

    public void returnBook() {
        System.out.print("Enter Book ID to return: ");
        int id = input.nextInt();
        input.nextLine();
        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                books[i].quantity++;
                System.out.println("Book returned successfully! Quantity increased to " + books[i].quantity);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Book Not Found");
        }
    }

    public void displayBooks() {
        if (count == 0) {
            System.out.println("No books available");
            return;
        }
        System.out.println("Book ID\tBook Name\tAuthor\tQuantity\tPrice\tPages");
        for (int i = 0; i < count; i++) {
            System.out.println(books[i].id + "\t" + books[i].title + "\t" + books[i].author + "\t" + books[i].quantity + "\t" + books[i].price + "\t" + books[i].pages);
        }
    }

    public void menu() {
        while (true) {
            System.out.println("\n\n========== LIBRARY MANAGEMENT SYSTEM ==========");
            System.out.println("1. Add Book");
            System.out.println("2. Delete Book");
            System.out.println("3. Update Book");
            System.out.println("4. Search Book");
            System.out.println("5. Return Book");
            System.out.println("6. Display Books");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            int choice = input.nextInt();
            input.nextLine();

            switch (choice) {
                case 1: addBook(); break;
                case 2: deleteBook(); break;
                case 3: updateBook(); break;
                case 4: searchBook(); break;
                case 5: returnBook(); break;
                case 6: displayBooks(); break;
                case 7: System.out.println("Exiting..."); return;
                default: System.out.println("Invalid choice!");
            }
        }
    }
}
