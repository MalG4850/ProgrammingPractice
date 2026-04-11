use std::io;
use std::io::Write;

fn main() {
    let mut num1: String = String::new();
    let mut num2: String = String::new();

    let num1: i32 = loop {
        num1.clear();
        print!("Enter the 1st number: ");
        io::stdout()
            .flush()
            .expect("Error: Could not flush stdout.\n");
        io::stdin()
            .read_line(&mut num1)
            .expect("Error: Could not read input.\n");
        match num1.trim().parse::<i32>() {
            Ok(num) => break num,
            Err(_) => {
                println!("Not a Number! Please try again.\n");
            }
        }
    };

    let num2: i32 = loop {
        num2.clear();
        print!("Enter the 2nd number: ");
        io::stdout()
            .flush()
            .expect("Error: Could not flush stdout.\n");
        io::stdin()
            .read_line(&mut num2)
            .expect("Error: Could not read input.\n");
        match num2.trim().parse::<i32>() {
            Ok(num) => break num,
            Err(_) => {
                println!("Not a Number! Please try again.\n");
            }
        }
    };

    println!("The addition of {} and {} is {}.", num1, num2, num1 + num2);
}
