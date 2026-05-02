use std::io::{self, Write};

fn main() {
    print!("This is a program to find the largest number in a given set of numbers.\n");
    let mut numbers: Vec<i32> = vec![];
    let mut input: String = String::new();

    loop {
        input.clear();
        print!("\nDo you want to add a number? [y/n]: ");
        io::stdout()
            .flush()
            .expect("Error: Could not flush stdout.\n");
        io::stdin()
            .read_line(&mut input)
            .expect("Error: Could not read input.\n");
        let choice = input.trim().to_lowercase();

        if choice == "n" {
            break;
        } else if choice == "y" {
            loop {
                input.clear();
                print!("Enter the number: ");
                io::stdout()
                    .flush()
                    .expect("Error: Could not flush stdout.\n");
                io::stdin()
                    .read_line(&mut input)
                    .expect("Error: Could not read input.\n");

                match input.trim().parse::<i32>() {
                    Ok(num) => {
                        numbers.push(num);
                        break;
                    }
                    Err(_) => {
                        print!("Not a Number! Please try again.\n");
                    }
                }
            }
        } else {
            print!("Please Enter [y/n]: ");
        }
    }

    if numbers.is_empty() {
        print!("You didn't enter any numbers! Please restart the program.\n\n");
        return;
    } else {
        /*  Array Logic according to C++
        let mut max: i32 = numbers[0];
        for i in 0..numbers.len() {
            if max < numbers[i] {
                max = numbers[i];
            } else {
                continue;
            }
        } */

        // This is the Rust way to do it
        let max = numbers.iter().max().unwrap();
        print!("The largest number of the given list is: {}.\n\n", max);
    }
}
