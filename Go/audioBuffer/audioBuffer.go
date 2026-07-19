package main

import (
	"fmt"
)

type AudioBuffer struct {
	TrackName   string
	Capacity    int
	CurrentSize int
}

func (a *AudioBuffer) LoadData(bytesToLoad int) {
	if a.CurrentSize+bytesToLoad > a.Capacity {
		a.CurrentSize = a.Capacity
		fmt.Print("Buffer Overflow: Cap reached!")
	} else {
		a.CurrentSize += bytesToLoad
		fmt.Printf("\n%v bytes loaded into the buffer.", bytesToLoad)
	}
}

func (a *AudioBuffer) Clear() {
	a.CurrentSize = 0
	fmt.Print("\nBuffer purge complete.\n\n")
}

func NewAudioBuffer(name string, cap int) *AudioBuffer {
	return &AudioBuffer{
		TrackName:   name,
		Capacity:    cap,
		CurrentSize: 0,
	}
}

func main() {
	playerBuffer := NewAudioBuffer("Lo-Fi Beats", 2048)
	var input int

	fmt.Print("\nHow much data (in bytes) do you want to load?\n\nThere is already 500 bytes of preloaded data: ")
	fmt.Scan(&input)

	playerBuffer.LoadData(input)

	fmt.Printf("\n\nCurrent Size is: %v", playerBuffer.CurrentSize)
	playerBuffer.Clear()
}
