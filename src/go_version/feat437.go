//这里用的hash表
package main

type TreeNode struct{
	Val int
	Left TreeNode*
	Right TreeNode*
}

func pathSum(root *TreeNode, targetSum int) int {
	seen := map[int64]int{0: 1} 
	count := 0
	target := int64(targetSum)

	var dfs func(node *TreeNode, pre int64)
	dfs = func(node *TreeNode, pre int64) {
		if node == nil {
			return
		}

		pre += int64(node.Val)
		count += seen[pre-target] 
		seen[pre]++               

		dfs(node.Left, pre)
		dfs(node.Right, pre)

		seen[pre]-- 
	}

	dfs(root, 0)
	return count
}