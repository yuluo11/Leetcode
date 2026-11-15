type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	type item struct {
		node  *TreeNode
		depth int
	}

	q := []item{{root, 1}}

	for len(q) > 0 {
		cur := q[0]
		q = q[1:] 

		if cur.node.Left == nil && cur.node.Right == nil {
			return cur.depth
		}

		if cur.node.Left != nil {
			q = append(q, item{cur.node.Left, cur.depth + 1})
		}
		if cur.node.Right != nil {
			q = append(q, item{cur.node.Right, cur.depth + 1})
		}
	}

	return 0 
}
