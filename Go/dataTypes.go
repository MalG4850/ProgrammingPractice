package main

import "fmt"

func main() {
	var i int = 2
	var f float64 = 3.1415
	var b bool = true
	var s string = "StringUsage"

	fmt.Printf("%T: %v\n", i, i)
	fmt.Printf("%T: %v\n", f, f)
	fmt.Printf("%T: %v\n", b, b)
	fmt.Printf("%T: %v\n", s, s)
}
