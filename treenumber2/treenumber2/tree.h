#pragma once

struct Node
{
	int data;
	Node *parent, *left, *right;
};

typedef Node *PNode;

class Tree
{
private:
	PNode head;
public:
	Tree() : head(NULL) {}
	void insert(int n);
	Tree(int n);
	PNode findn(int n);
	PNode gethead();
	PNode min(PNode x);
	PNode max(PNode x);
	void show(PNode x);
	void deleten(int n);
	void preorder(PNode root);
	void postorder(PNode root);
	void inorder(PNode root);
	void deletetree(PNode x);
};
