package main

type Node struct {
    Val int
	Left *Node
    Right *Node
	Next *Node
}

func connect(root *Node) *Node {
	head :=root	
	while(head!=nil){
		var dummpy Node
		tail:=&dummpy
		for(cur *Node=head;cur!=nil;cur=cur.Next){
			if cur.Left!=nil{
				tail.Next=cur.Left
				tail=cur.Left
			}
			if cur.Right!=nil{
				tail.Next=cur.Right
				tail=cur.Right
			}
			tail.Next=nil
			head=dummpy.Next
		}
	}
	return root

}