package main

import "fmt"

func main() {
	fruits := []string{"Apple", "Mango", "Pear"}
	fmt.Print()
	fmt.Println(fruits)
	fruits = append(fruits, "Banana")
	fmt.Println(fruits)
	fmt.Print()
}
