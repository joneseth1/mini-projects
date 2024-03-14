package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	file, err := os.Open("numbers.txt")
	if err != nil {
		fmt.Println("Can't open file: ", err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner((file))

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)
	}

	fmt.Println("TEST")
}
