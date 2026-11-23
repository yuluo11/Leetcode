package main

type Node struct {
    Val int
	Left *Node
    Right *Node
	Next *Node
}

type BSTIterator struct {
	st []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	it := BSTIterator{}
	for root != nil {
		it.st = append(it.st, root)
		root = root.Left
	}
	return it
}

func (it *BSTIterator) Next() int {
	cur := it.st[len(it.st)-1]
	it.st = it.st[:len(it.st)-1]

	for p := cur.Right; p != nil; p = p.Left {
		it.st = append(it.st, p)
	}

	return cur.Val
}

func (it *BSTIterator) HasNext() bool {
	return len(it.st) > 0
}
