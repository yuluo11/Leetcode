package main

type Node struct {
    Val int
	Left *Node
    Right *Node
	Next *Node
}

func rightSideView(root *TreeNode) []int {
	res := []int{}

	var dfs func(node *TreeNode, depth int)
	dfs = func(node *TreeNode, depth int) {
		if node == nil {
			return
		}
		if depth == len(res) {
			res = append(res, node.Val)
		}
		dfs(node.Right, depth+1)   
		dfs(node.Left, depth+1)    
	}

	dfs(root, 0)
	return res
}
