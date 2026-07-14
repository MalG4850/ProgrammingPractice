package main

import "fmt"

func main() {
	var name string
	var age int32

	fmt.Print("\nEnter you name and age: ")
	fmt.Scan(&name, &age) //Reads multiple values across spaces and assigns to given variables
	fmt.Printf("\nHello %v of age %v!\n\n", name, age)
}
