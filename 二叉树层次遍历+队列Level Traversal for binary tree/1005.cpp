#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
	queue<BinaryNode<T>*> q;
	if (root != NULL) {
		BinaryNode<T>* r;
		q.push(root);
		while(!q.empty()) {
			r = q.front();
			visit(r->elem);
			if (r->left != NULL) q.push(r->left);
			if (r->right != NULL) q.push(r->right);
			q.pop();
		} 
	}
}
