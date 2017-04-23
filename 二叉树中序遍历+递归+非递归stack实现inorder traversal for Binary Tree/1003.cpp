#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode() { left = right = NULL; }
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)) {
	if (root != NULL) {
		inorder_recursive(root->left,visit);
		visit(root->elem);
		inorder_recursive(root->right,visit);
	}
}

template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)){
	stack<BinaryNode<T> *> p;
	BinaryNode<T>* r = root;
	BinaryNode<T>* r2;
	if (root != NULL) {
	while (r != NULL) {
		p.push(r);
		r = r->left;
	}
	do  {
			r = p.top();
			visit(r->elem);
			p.pop();
			if (r->right != NULL) {
				p.push(r->right);
				r = r->right;
				r = r->left;
				while (r != NULL) {
					p.push(r);
					r = r->left;				
				}
			}
	} while (!p.empty());
	}
}

template <typename T>
void view(T &x) {
    cout << x << " ";
}

int main() {
    BinaryNode<int> **node = new BinaryNode<int>*[10];
    for (int i = 0; i < 10; i++)  node[i] = new BinaryNode<int>(i);
    node[4]->left = node[2];
    node[4]->right = node[7];
    node[2]->left = node[1];
    node[2]->right = node[3];
    inorder(node[4], view);
    cout << endl;
    inorder_recursive(node[4], view);
}
