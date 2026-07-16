package main

import "fmt"

func pointerSwap(a *int, b *int) {
	*a = *a ^ *b
	*b = *a ^ *b
	*a = *a ^ *b
}

func main() {
	buffer1 := 1024
	buffer2 := 2048

	fmt.Printf("\nBuffer 1: %v, Buffer 2: %v\n\n", buffer1, buffer2)

	pointerSwap(&buffer1, &buffer2)

	fmt.Printf("After swapping....\nBuffer 1: %v, Buffer 2: %v\n\n", buffer1, buffer2)
}
