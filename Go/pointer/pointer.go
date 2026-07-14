package main

import "fmt"

func zero(xptr *int) {
	*xptr = 0
}

func main() {
	fmt.Print("\nThis is a program that zeroes the value of a variable using its pointer.\n\n")
	var x int = 45
	var xptr *int = &x
	fmt.Print("x = ", x)
	zero(xptr)
	fmt.Print("'Zero Function' applied to x.\n\nNow x = ", x, "\n\n")
}
