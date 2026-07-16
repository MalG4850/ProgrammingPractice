package main

import (
	"fmt"
)

type AudioBuffer struct {
	trackName   string
	capacity    int
	currentSize int
}

func (a *AudioBuffer) LoadData(bytesToLoad int) {
	if bytesToLoad > a.capacity {
		a.currentSize = a.capacity
		fmt.Print("Buffer Overflow: Cap reached!")
	} else {
		a.currentSize += bytesToLoad
		fmt.Printf("\n%v bytes loaded into the buffer.", bytesToLoad)
	}
}

func (a *AudioBuffer) Clear() {
	a.currentSize = 0
	fmt.Print("\nBuffer purge complete.\n\n")
}

func main() {
	playerBuffer := AudioBuffer{trackName: "Lo-Fi Beats", capacity: 2048, currentSize: 500}
	var input int

	fmt.Print("\nHow much data (in bytes) do you want to load?\n\nThere is already 500 bytes of preloaded data: ")
	fmt.Scan(&input)

	playerBuffer.LoadData(input)

	fmt.Printf("\n\nCurrent Size is: %v", playerBuffer.currentSize)
	playerBuffer.Clear()
}
