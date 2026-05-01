use std::io;
use std::io::Write;

fn main() {
    print!("This is a program to calculate the factorial of a given number.\n");
    let mut num: String = String::new();
    let num: i32 = loop {
        num.clear();
        print!("\nEnter the number: ");
        io::stdout()
            .flush()
            .expect("Error: Could not flush stdout.\n");
        io::stdin()
            .read_line(&mut num)
            .expect("Error: Could not read input.\n");
        match num.trim().parse::<i32>() {
            Ok(num) => break num,
            Err(_) => {
                print!("Not a number! Please try again.\n");
            }
        }
    };

    if num == 0 || num == 1 {
        print!("\nThe factorial of {} is 1.\n\n", num);
        return;
    } else if num > 1 {
        let input: u128 = num as u128;
        let mut factorial: u128 = 1;
        for j in 1..=input {
            factorial *= j;
        }
        print!("\nThe factorial of {} is {}.\n\n", num, factorial);
    } else {
        print!("\nFactorials of negative numbers do not exist!\n\n");
    }
}
