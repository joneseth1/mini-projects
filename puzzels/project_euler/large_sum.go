package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	file, err := os.Open("numbers.txt")
	if err != nil {
		fmt.Println("Can't open file: ", err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	var numbers []int

	for scanner.Scan() {
		line := scanner.Text()
		number, err := strconv.Atoi(line)
		if err != nil {
			fmt.Println("Error converting line to integer:", err)
			continue
		}

		numbers = append(numbers, number)
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error readding file: ", err)
	}
}
