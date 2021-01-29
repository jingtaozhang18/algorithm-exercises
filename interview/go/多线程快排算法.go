package main

import (
	"fmt"
	"math/rand"
	"time"
)

// 交换数组中的两元素
func swap(a *[]int, i int, j int) {
	(*a)[i], (*a)[j] = (*a)[j], (*a)[i]
}

func qsort(a *[]int, left int, right int) {
	// 闭区间
	if right <= left {
		return
	}
	idx := left
	pivot := (*a)[left]
	swap(a, left, right) // 移动到最右侧
	for i := left; i < right; i++ {
		if (*a)[i] < pivot {
			swap(a, i, idx)
			idx++
		}
	}
	swap(a, idx, right)
	go qsort(a, left, idx-1)
	go qsort(a, idx+1, right)
}

// 并行排序
func ConcurrentSort(a *[]int, left int, right int, chanSend chan int) {
	// 闭区间
	if (right - left) < 10000 { // 减少创建的数量
		qsort(a, left, right)
		chanSend <- 0
		return
	}
	idx := left
	pivot := (*a)[left]
	swap(a, left, right) // 移动到最右侧
	for i := left; i < right; i++ {
		if (*a)[i] < pivot {
			swap(a, i, idx)
			idx++
		}
	}
	swap(a, idx, right)
	chanReceive := make(chan int)
	go ConcurrentSort(a, left, idx-1, chanReceive)
	go ConcurrentSort(a, idx+1, right, chanReceive)
	<-chanReceive
	<-chanReceive
	chanSend <- 0
}

func getTestArr() []int {
	rand.Seed(time.Now().UnixNano())
	numRand := 100000000
	testArr := make([]int, numRand)
	for i := 0; i < numRand; i++ {
		testArr[i] = rand.Intn(numRand * 5)
	}
	return testArr
}

func main() {
	testArr3 := getTestArr()
	chanWait := make(chan int)
	start := time.Now()
	go ConcurrentSort(&testArr3, 0, len(testArr3)-1, chanWait)
	<-chanWait
	fmt.Printf("多线程快排消耗时间：%s\n", time.Since(start))
	start = time.Now()
	testArr3 = getTestArr()
	qsort(&testArr3, 0, len(testArr3)-1)
	fmt.Printf("单线程快排消耗时间：%s\n", time.Since(start))
}
