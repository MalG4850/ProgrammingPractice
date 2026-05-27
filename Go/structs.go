package main

import "fmt"

type Rectangle struct {
	Width  float64
	Height float64
}

func (r Rectangle) Area() float64 {
	return r.Width * r.Height
}

func main() {
	var h, w float64
	fmt.Print("\nThis is a program to calculate the area of a rectangle.\n\n")
	fmt.Print("Enter the height of the rectangle: ")
	fmt.Scan(&h)
	fmt.Print("\nEnter the width of the rectangle: ")
	fmt.Scan(&w)
	r1 := Rectangle{Width: w, Height: h}
	fmt.Printf("\nThe area of the given rectangle is %v units.\n\n", r1.Area())
}
