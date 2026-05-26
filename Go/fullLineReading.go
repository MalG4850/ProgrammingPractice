package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Print("\nEnter some text to see it echo back: ")

	if scanner.Scan() {
		input := scanner.Text()
		fmt.Printf("\nYou Typed: %v\n\n", input)
	}
}
