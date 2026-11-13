package main

type TreeNode struct{
	Val int
	Left *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
  		return [][]int{}
 	}

	result := [][]int{}
 	queue := []*TreeNode{root}
 	isReverse := false

 	for len(queue) > 0 {
  		levelSize := len(queue)
  		level := make([]int, 0, levelSize)
	
		for i := 0; i < levelSize; i++ {
   			node := queue[0]
   			queue = queue[1:]

   			level = append(level, node.Val)

   			if node.Left != nil {
    			queue = append(queue, node.Left)
   			}

   			if node.Right != nil {
    			queue = append(queue, node.Right)
   			}
			
  		}
		if (isReverse){
			reverse(level)
		}
		result=append(result,level)
		isReverse=!isReverse
	}
	return result
}

func reverse(nums []int) {
	left, right := 0, len(nums)-1

 	for left < right {
  		nums[left], nums[right] = nums[right], nums[left]
  		left++
  		right--
 	}
}