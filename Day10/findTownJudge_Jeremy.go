package main

// Not working lol

// to import third party packages from github:
// run "go get [github link]" in terminal
import (
	"fmt"

	"github.com/golang-collections/collections"
	"github.com/golang-collections/collections/set"
)

func findJudge(N int, trust [][]int) int {
	// edge cases
	if N == 0 {
		return -1
	} else if N == 1 && len(trust) == 0 {
		return 1
	}

	peopleWhoTrusts := make(map[int][]int)
	peopleWhomThisTrusts := make(map[int][]int)
	s := set.New()

	for _, pair := range trust {
		peopleWhoTrusts[pair[1]] = append(peopleWhoTrusts[pair[1]], pair[0])
		peopleWhomThisTrusts[pair[0]] = append(peopleWhomThisTrusts[pair[0]], pair[1])
		s.Insert(pair[1])
		s.Insert(pair[0])
	}

	collections.GetRange(Collection(s), 0, s.Len())
	for i := 0; i < s.Len(); i++ {
		if len(peopleWhomThisTrusts[s[i]]) == 0 {
			if len(peopleWhoTrusts[s[i]]) == N-1 {
				return s[i]
			}
		}
	}

	return 0
}

func main() {
	fmt.Println("Hello")
	set.New()
}
