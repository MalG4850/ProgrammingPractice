package main

import "fmt"

func main() {
	ageMap := make(map[string]int)
	ageMap["Alice"] = 25
	ageMap["Bob"] = 30
	fmt.Println(ageMap["Alice"])
}
