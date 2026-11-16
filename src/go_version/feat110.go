package main

type TreeNode struct{
	Val int
	Left *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	var dfs func(*TreeNode) int
	dfs = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		l, r := dfs(node.Left), dfs(node.Right)
		if l == -1 || r == -1 || l-r > 1 || r-l > 1 {
			return -1
		}
		return max(l, r) + 1
	}
	return dfs(root) != -1
}
