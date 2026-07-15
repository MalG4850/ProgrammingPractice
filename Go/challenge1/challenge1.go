package main

import "fmt"

func burnFuel(fuelPtr *int, amt int) {
	*fuelPtr -= amt
}

func main() {
	fuel := 100
	fmt.Print("\nFuel value:", fuel, "\n")
	burnFuel(&fuel, 30)

	fmt.Print("Fuel value after burning:", fuel, "\n\n")
}
