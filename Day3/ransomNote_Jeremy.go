package main

import "fmt"

func canConstruct(ransomNote string, magazine string) bool {
	// make a dictionary
	m := make(map[rune]int)
	for _, c := range magazine {
		m[c]++ // golang's map has a default dict behavior
	}

	// this kind of for loop returns index, char (rune)
	for _, c := range ransomNote {
		if m[c] == 0 {
			return false
		} else {
			m[c]--
		}
	}

	return true
}

func main() {
	fmt.Println("A")
}
