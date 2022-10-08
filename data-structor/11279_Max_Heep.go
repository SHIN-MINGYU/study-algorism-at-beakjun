package main

import (
	"bufio"
	"fmt"
	"os"
)

// swap function is swap arr's values between first and second arguments
func swap (arr []int, first, second int) {
	arr[first], arr[second] = arr[second], arr[first]
}


// maxHeepInsert function intert value in arr 
func maxHeepInsert(arr []int) {
	index := len(arr) -1
	if(index <= 0){
		// recursive stop point
		return
	}
	if index % 2 == 0 {
		// if parent value is greater than last value then change value
		if(arr[index] > arr[(index-2) / 2]){
			swap(arr, index, (index-2)/2)
			// recursively swap
			maxHeepInsert(arr[:((index-2) /2)+1])
		}
	}else{
		if(arr[index] > arr[(index-1) / 2]){
            swap(arr, index, (index-1)/2)
			maxHeepInsert(arr[:((index-1) /2)+1])
        }
	}
}


func maxHeapDelete(arr []int) []int{
	index := len(arr) - 1
    if(index < 0){
        return arr
    }

	arr[0] = arr[index]
	newArr :=arr[:index]
	
	if(len(newArr) <= 1){
		return newArr
	}

	parentIdx := 0;
	for {
		var left bool;
		if len(newArr) <= parentIdx*2 + 1 {
			//  the case what have compareable value
			break
		}
		if len(newArr) <= parentIdx*2+2 {
			// the case what don't have right value
			left = true
		}else{
			left = newArr[parentIdx*2 + 1] > newArr[parentIdx*2 + 2]
		}

		if left {
			// if left value is greater than right value
			if newArr[parentIdx] < newArr[parentIdx*2 + 1] {
				swap(newArr, parentIdx*2+1, parentIdx)
            	parentIdx = parentIdx*2+1
				continue
			}
		}else if !left {
			// right value is greater than left value
			if newArr[parentIdx] < newArr[parentIdx*2 + 2] {
				swap(newArr, parentIdx*2+2, parentIdx)
            	parentIdx = parentIdx*2+2
				continue
			}
		}
		break;
	}

    return newArr
}

func main() {
	w := bufio.NewWriter(os.Stdout)
	r := bufio.NewReader(os.Stdin)
	defer w.Flush()
	// the count of calculations
	var n int
	fmt.Fscanf(r,"%d", &n)
	
	// input natural number in array
	arr := []int{}
	fmt.Fscanf(r,"%d", &arr)

	for i := 0; i < n; i++ {
		// if input is natural number, input number is append to arr
		var input int
		fmt.Fscan(r,&input)
		// else if input number is 0, print biggest number in arr and delete
		if input == 0 {
			if len(arr) == 0 {
            	fmt.Fprintln(w,0)
			}else {
				fmt.Fprintln(w,arr[0]) 
				arr = maxHeapDelete(arr)
			}
			continue
        }

		arr = append(arr, input)
		maxHeepInsert(arr)

	}
}