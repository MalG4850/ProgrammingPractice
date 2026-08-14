package main

import (
	"fmt"
)

func ExtractFrame(samples []int, frameSize int) ([]int, []int) {
	if len(samples) < frameSize {
		return samples, nil
	}
	frame := samples[:frameSize]
	remaining := samples[frameSize:]
	return frame, remaining
}

func main() {
	var samples []int
	var temp, size int

	fmt.Println("Enter 10 integers for a sample audio bit stream mock:")
	for i := 0; i < 10; i++ {
		fmt.Printf("Sample %d: ", i+1)
		fmt.Scan(&temp)
		samples = append(samples, temp)
	}

	fmt.Print("\nWhat frame size do you want? ")
	fmt.Scan(&size)

	fmt.Printf("\n--- Processing Stream (Total items: %d) ---\n", len(samples))

	for len(samples) >= size {
		var frame []int
		frame, samples = ExtractFrame(samples, size)
		fmt.Printf("Extracted Frame: %v\n", frame)
	}

	fmt.Printf("Remaining in buffer: %v\n", samples)
}
