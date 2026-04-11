use std::io::{self, Write};

fn main() {
    println!("Professional Rust Vector Practice");
    let mut numbers: Vec<i32> = vec![];
    let mut input = String::new();

    loop {
        input.clear();
        print!("\nDo you want to add a number? [y/n]: ");
        io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input).expect("Read failed");

        let choice = input.trim().to_lowercase();

        if choice == "n" {
            break;
        } else if choice == "y" {
            // Get the number
            loop {
                input.clear();
                print!("Enter the number: ");
                io::stdout().flush().unwrap();
                io::stdin().read_line(&mut input).expect("Read failed");

                match input.trim().parse::<i32>() {
                    Ok(num) => {
                        numbers.push(num);
                        break; // Exit the "get number" loop, return to "y/n"
                    }
                    Err(_) => println!("Invalid input! Please enter a valid integer."),
                }
            }
        } else {
            println!("Please enter in [y/n].");
        }
    }

    println!("\nFinal List: {:?}", numbers); // {:?} is the debug formatter
}
