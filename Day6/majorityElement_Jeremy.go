package main

import "fmt"

// O(n)
func majorityElement(nums []int) int {
	// init map
	var m = make(map[int]int)

	// for each loop which is always enumeration??
	for _, num := range nums {
		// golang's map is a default dict
		m[num]++
		if m[num] > len(nums)/2 {
			return num
		}
	}
	return 0
}

func main() {
	fmt.Println("Hello")
}
