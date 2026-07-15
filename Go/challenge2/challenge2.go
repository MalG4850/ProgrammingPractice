package main

import (
	"fmt"
)

func checkSys(tempPtr *int, memPtr *int) {
	if *tempPtr > 80 {
		fmt.Print("\nWarning: High CPU Temp! Resetting to lower temp.\n\n")
		*tempPtr = 50
	}

	if *memPtr > 90 {
		fmt.Print("\nWarning: High memory usage! Resetting to lower usage.\n\n")
		*memPtr = 40
	} else {
		fmt.Print("\nSystem is healthy.\n\n")
	}
}

func main() {
	cpuTemp := 45
	memUsage := 60

	checkSys(&cpuTemp, &memUsage)

	cpuTemp = 85
	memUsage = 95

	checkSys(&cpuTemp, &memUsage)
}
