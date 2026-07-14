package main

import "fmt"

func divide(x, y float64) (float64, bool) {
	if y == 0 {
		fmt.Print("\nSorry, can't divide by zero!\n\n")
		return 0, false
	}
	return x / y, true
}

func main() {
	var x, y float64
	fmt.Print("\nThis is a program for division.\n\n")
	fmt.Print("Enter the 2 numbers, dividend and divisor: ")
	fmt.Scan(&x, &y)
	result, success := divide(x, y)
	if success {
		fmt.Printf("Result: %v\n\n", result)
	}
}
