package main

import "fmt"

func main() {
	print("\n")
	for i := 0; i < 10; i++ {
		fmt.Printf("%v ", i+1)
	}
	print("\n\n")
}
