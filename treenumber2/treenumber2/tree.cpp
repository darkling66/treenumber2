
#include "stdafx.h"
#include "tree.h"

void Tree::insert(int n) {
	PNode z = new Node;
	PNode y = NULL;
	PNode x = head;
	z->data = n;
	while (x != NULL) {
		y = x;
		if ((z->data) < (x->data))
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		head = z;
	else
	{
		if ((z->data) < (y->data))
			y->left = z;
		else
			y->right = z;
	}
	z->left = NULL;
	z->right = NULL;
}

Tree::Tree(int n) {
	insert(n);
}

PNode Tree::findn(int n) {
	PNode x = head;
	while ((x != NULL) && (x->data != n))
		if (n < (x->data))
			x = x->left;
		else
			x = x->right;
	return x;
}

PNode Tree::gethead() {
	return head;
}

PNode Tree::min(PNode x) {
	while ((x->left) != NULL)
		x = x->left;
	return x;
}

PNode Tree::max(PNode x) {
	while ((x->right) != NULL)
		x = x->right;
	return x;
}

void Tree::show(PNode x) {
	if (x == NULL)
		return;
	show(x->left);
	cout << (x->data);
	show(x->right);
}

void Tree::deleten(int n) {
	PNode p = head;
	PNode parent = NULL;
	while ((p != NULL) && (p->data != n)) {
		parent = p;
		if (n < (p->data))
			p = p->left;
		else
			p = p->right;
	}
	if (p != NULL) {
		PNode removed = NULL;
		if ((p->left == NULL) || (p->right == NULL)) {
			PNode child = NULL;
			removed = p;
			if ((p->left) != NULL)
				child = p->left;
			else
				if ((p->right) != NULL)
					child = p->right;
			if (parent == NULL)
				head = child;
			else {
				if ((parent->left) == p)
					parent->left = child;
				else
					parent->right = child;
			}
		}
		else
		{
			PNode mleft = p->right;
			PNode mparent = p;
			while ((mleft->left) != NULL)
			{
				mparent = mleft;
				mleft = mleft->left;
			}
			p->data = mleft->data;
			removed = mleft;
			if ((mparent->left) == mleft)
				mparent->left = NULL;
			else
				mparent->right = mleft->right;
		}
		delete removed;
	}
}

void Tree::preorder(PNode x) {
	if (x == NULL)
		return;
	if (x->data)
		cout << x->data;
	preorder(x->left);
	preorder(x->right);
}

void Tree::postorder(PNode x) {
	if (x == NULL)
		return;
	postorder(x->left);
	postorder(x->right);
	if (x->data)
		cout << x->data;
}

void Tree::inorder(PNode x) {
	if (x == NULL)
		return;
	inorder(x->left);
	if (x->data)
		cout << x->data;
	inorder(x->right);
}

void Tree::deletetree(PNode x) {
	if (x != NULL) {
		deletetree(x->left);
		deletetree(x->right);
		delete x;
		x = NULL;
	}
}