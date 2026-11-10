//递归版 遍历版见cpp
type TreeNode struct{
	Val int
	Left *TreeNode
	Right *TreeNode
}
func helper(left *TreeNode,right *TreeNode) bool{
	if left==nil ||right==nil{
		return left==right
	}
	if left.Val!=right.Val{
		return false
	}
	return helper(left.Left,right.Right)&&helper(left.Right, right.Left)
}
func isSymmetric(root *TreeNode) bool {
    return root==nil||helper(root.Left,root.Right)
}