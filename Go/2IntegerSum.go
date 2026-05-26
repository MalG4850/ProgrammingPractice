package main

import "fmt"

func main() {
	var n1, n2 float64
	fmt.Print("\nEnter 2 numbers to see their sum: ")
	fmt.Scan(&n1, &n2)
	fmt.Printf("\nThe sum of %v and %v is %v.\n\n", n1, n2, n1+n2)
}
