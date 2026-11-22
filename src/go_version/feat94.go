package main

type TreeNode struct{
	Val int
	Left *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	st := []*TreeNode{}
	cur := root

	for cur != nil || len(st) > 0 {
		
		for cur != nil {
			st = append(st, cur)
			cur = cur.Left
		}

		
		cur = st[len(st)-1]
		st[:len(st)-1]=nil;//底层的数组还存在，GC不会回收它，所以这里要=nil
		st = st[:len(st)-1]
		res = append(res, cur.Val)

		cur = cur.Right
	}

	return res
}
