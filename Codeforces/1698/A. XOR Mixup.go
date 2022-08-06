package main

import (
	"fmt"
)

func solve() {
	var n, i, sum, x int
	var numbers []int

	fmt.Scanf("%d", &n)

	sum = 0

	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &x)
		numbers = append(numbers, x)
		sum ^= x
	}

	for i = 0; i < n; i++ {
		if (sum ^ numbers[i]) == numbers[i] {
			fmt.Printf("%d\n", numbers[i])
			return
		}
	}
}

func main() {

	// os.Stdin, _ := os.OpenFile("in.txt", os.O_RDONLY, 0666)

	var test int
	fmt.Scanf("%d", &test)

	for test > 0 {
		test--
		solve()
	}
}
