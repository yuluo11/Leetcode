//较于cpp没有引用可以直接用闭包即可
package main

type TreeNode struct{
	Val int
	Left TreeNode*
	Right TreeNode*
}

func diameterOfBinaryTree(root *TreeNode) *TreeNode {
	best := 0

	var dfs func(node *TreeNode) int
	dfs = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		l := dfs(node.Left)
		r := dfs(node.Right)

		best = max(best, l+r)   
		return max(l, r) + 1   
	}

	dfs(root)
	return best
}
