package main

import "fmt"

var n int
var arr [4]int
var dp [4][4000 + 5]int

func memoryReset(data *[4][4000 + 5]int, value int) {

	for outer := 0; outer < len(data); outer++ {

		data[outer][0] = value
		for inner := 1; inner < len(data[outer]); inner *= 2 {
			copy(data[outer][inner:], data[outer][:inner])
			//data[outer][inner] = value
		}
	}
}

func solve(pos, remain int) int {

	if pos > 2 || remain < 0 {
		return 0
	}

	if remain == 0 {
		return 1
	}

	if dp[pos][remain] != -1 {
		return dp[pos][remain]
	}

	a := solve(pos, remain-arr[pos])
	if a > 0 {
		a += 1
	}

	b := solve(pos+1, remain-arr[pos])
	if b > 0 {
		b += 1
	}
	c := solve(pos+1, remain)

	var result int
	if a > b {
		result = a
	} else {
		result = b
	}

	if result < c {
		result = c
	}

	dp[pos][remain] = result

	return dp[pos][remain]
}

func main() {

	memoryReset(&dp, -1)

	fmt.Scanf("%d %d %d %d", &n, &arr[0], &arr[1], &arr[2])

	fmt.Println(solve(0, n) - 1)

}
