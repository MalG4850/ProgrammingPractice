package main

import "fmt"

func main() {
	// Declaration
	capitalMapping := make(map[string]string)
	var input string

	// Assigning a few values
	capitalMapping["India"] = "New Delhi"
	capitalMapping["Brazil"] = "Brasilia"

	fmt.Print("\nEnter a country to see its capital: ")
	fmt.Scan(&input)

	capital, exists := capitalMapping[input]
	if exists {
		fmt.Printf("\nThe Capital of %v is %v.\n\n", input, capital)
	} else {
		fmt.Printf("\nSorry, could not find the capital of %v.\n\n", input)
	}
}
