package main

import "fmt"

func checkSys(tempPtr *int, memPtr *int) {
	isHealthy := true

	if *tempPtr > 80 {
		fmt.Println("Warning: High CPU Temp! Resetting to lower temp.")
		*tempPtr = 50
		isHealthy = false
	}

	if *memPtr > 90 {
		fmt.Println("Warning: High memory usage! Resetting to lower usage.")
		*memPtr = 40
		isHealthy = false
	}

	if isHealthy {
		fmt.Println("System is healthy.")
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
