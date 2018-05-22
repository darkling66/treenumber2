// treenumber2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "tree.h"

int main()
{
	Tree f;
	for (int i = 1; i <= 10; i++) {
		f.insert(i);
	}
	cout << "Tree:" << endl;
	PNode  head = f.gethead();
	f.show(head);
	cout << endl << "Max = " << (f.max(head))->data << ", min = " << (f.min(head))->data << ";" << endl << endl;
	int n;
	cout << "Enter n: ";
	cin >> n;
	if (f.findn(n) != NULL) {
		cout << endl << "This element is in tree" << endl << endl;
	}
	else {
		cout << endl << "This element doesn't exist" << endl << endl;
	}
	f.preorder(head);
	puts("");
	f.postorder(head);
	puts("");
	f.inorder(head);
	puts("");
	f.deletetree(head);
	system("pause");
}