package main

type TreeNode struct{
	Val int
	Left TreeNode*
	Right TreeNode*
}

func findSecondMinimumValue(root *TreeNode) int {
	return dfs(root, root.Val)
}

func dfs(node *TreeNode, minVal int) int {
	if node.Val > minVal {
		return node.Val
	}
	if node.Left == nil {
		return -1
	}

	l := dfs(node.Left, minVal)
	r := dfs(node.Right, minVal)

	if l == -1 {
		return r
	}
	if r == -1 {
		return l
	}
	return min(l, r)
}
