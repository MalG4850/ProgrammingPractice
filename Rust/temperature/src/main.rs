use std::io;
use std::io::Write;

fn main() {
    print!("This is a program to calculate Temperature from °C to °F and vice-versa.\n\n");
    let mut ch: String = String::new();
    let ch: i8 = loop {
        ch.clear();
        print!("1. °C to °F\n2. °F to °C\n3. Exit\n\nEnter your choice: ");
        io::stdout()
            .flush()
            .expect("Error: Could not flush stdout.\n\n");
        io::stdin().read_line(&mut ch).unwrap();
        match ch.trim().parse::<i8>() {
            Ok(num) => break num,
            Err(_) => {
                print!("Not a number! Please try again.\n\n");
            }
        }
    };

    if ch == 1 {
        print!("Enter the temperature in °C: ");
        let mut c_temp: String = String::new();
        let c_temp: i16 = loop {
            c_temp.clear();
            io::stdout()
                .flush()
                .expect("Error: Could not flush stdout.\n\n");
            io::stdin()
                .read_line(&mut c_temp)
                .expect("Error: Could not read input.\n\n");
            match c_temp.trim().parse::<i16>() {
                Ok(num) => break num,
                Err(_) => {
                    print!("Not a number! Please try again.\n\n");
                }
            }
        };
        let f_temp: i16 = (c_temp * 9 / 5) + 32;
        print!("{}°C is {}°F.\n\n", c_temp, f_temp);
    } else if ch == 2 {
        print!("Enter the temperature in °F: ");
        let mut f_temp: String = String::new();
        let f_temp: i16 = loop {
            f_temp.clear();
            io::stdout()
                .flush()
                .expect("Error: Could not flush stdout.\n\n");
            io::stdin()
                .read_line(&mut f_temp)
                .expect("Error: Could not read input.\n\n");
            match f_temp.trim().parse::<i16>() {
                Ok(num) => break num,
                Err(_) => {
                    print!("Not a number! Please try again.\n\n");
                }
            }
        };
        let c_temp: i16 = (f_temp - 32) * 5 / 9;
        print!("{}°F is {}°C.\n\n", f_temp, c_temp);
    }
}
