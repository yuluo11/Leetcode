package main

type TreeNode struct{
	Val int
	Left TreeNode*
	Right TreeNode*
}
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	var isSame func(a, b *TreeNode) bool
	isSame = func(a, b *TreeNode) bool {
		if a == nil && b == nil {
			return true
		}
		if a == nil || b == nil {
			return false
		}
		if a.Val != b.Val {
			return false
		}
		return isSame(a.Left, b.Left) && isSame(a.Right, b.Right)
	}

	var dfs func(node *TreeNode) bool
	dfs = func(node *TreeNode) bool {
		if node == nil {
			return false
		}
		if isSame(node, subRoot) {
			return true
		}
		return dfs(node.Left) || dfs(node.Right)
	}

	return dfs(root)
}
