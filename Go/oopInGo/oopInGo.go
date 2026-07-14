package main

import "fmt"

type Song struct {
	Title    string
	Artist   string
	Duration float64
}

func (s *Song) Display() {
	fmt.Printf("\nTitle: %v\nArtist: %v\nDuration: %v mins\n\n", s.Title, s.Artist, s.Duration)
}

func main() {
	var s1 = Song{
		Title:    "No One Sleep In Tokyo",
		Artist:   "EDO Boys",
		Duration: 5.05,
	}
	//s1.Title = "No One Sleep In Tokyo"
	//s1.Artist = "EDO Boys"
	//s1.Duration = 5.05
	s1.Display()

}
