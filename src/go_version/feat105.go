package main

type TreeNode struct{
	Val int
	Left *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
 rootIdx := 0
 return build(preorder, inorder, &rootIdx, 0, len(inorder)-1)
}

func build(
 preorder []int,
 inorder []int,
 rootIdx *int,
 left int,
 right int,
) *TreeNode {
 if left > right {
  return nil
 }

 pivot := left
 for inorder[pivot] != preorder[*rootIdx] {
  pivot++
 }

 node := &TreeNode{
  Val: preorder[*rootIdx],
 }

 *rootIdx = *rootIdx + 1

 node.Left = build(preorder, inorder, rootIdx, left, pivot-1)
 node.Right = build(preorder, inorder, rootIdx, pivot+1, right)

 return node
}