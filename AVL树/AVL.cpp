#include<cstdio>
#include<iostream>

using namespace std;

typedef struct Node* Tree;
typedef struct Node* Node_t;

struct Node{
 Node_t left;
 Node_t right;
 int height;
 int data;
};

int Height(Node_t node) {
 if (node == NULL) return 0;
 return node->height;
}
Node_t NewNode(int x) {
	Node_t k=new Node;
	k->left=NULL;
	k->right=NULL;
	k->height=1;
	k->data=x;
	return k;
}
int Max(int x,int y) {
	if (x>y) return x;
	return y;
}
Node_t RightRotate(Node_t a) {
	Node_t b = a->left;
	a->left = b->right;
	b->right = a;
	a->height = Max(Height(a->left), Height(a->right)) +1;
	b->height = Max(Height(b->left), Height(b->right)) +1;
	return b;
}
Node_t LeftRotate(Node_t a) {
	Node_t b = a->right;
	a->right = b->left;
	b->left = a;
	a->height = Max(Height(a->left), Height(a->right)) +1;
	b->height = Max(Height(b->left), Height(b->right)) +1;
	return b;
}
Node_t LeftRightRotate(Node_t a) {
	a->left = LeftRotate(a->left);
	return RightRotate(a);
}
Node_t RightLeftRotate(Node_t a) {
	a->right = RightRotate(a->right);
	return LeftRotate(a);
}
Node_t Insert(int x,Tree t) {
	if (t==NULL) {
		t=NewNode(x);
	} else if (x<t->data) {
		t->left = Insert(x,t->left);
		if (Height(t->left)-Height(t->right) == 2) {
			if (x< t->left->data)
				t = RightRotate(t);
    		else t = LeftRightRotate(t);
			}
	} else {
		t->right = Insert(x,t->right);
		if (Height(t->right) - Height(t->left) == 2) {
			if(x > t->right->data) 
    			t = LeftRotate(t);
    		else t = RightLeftRotate(t);
		}
	}
	t->height = Max(Height(t->left), Height(t->right)) + 1;
	return t;
}
void preorder(Node_t k) {
	printf("%d ",k->data);
	if (k->left != NULL) preorder(k->left);
	if (k->right != NULL) preorder(k->right);
}
void release(Node_t k) {
	if (k->left == NULL && k->right == NULL) return;
	if (k->left != NULL) {
		release(k->left);
		delete k->left;
		k->left=NULL;
	}
	if (k->right != NULL) {
		release(k->right);
		delete k->right;
		k->right=NULL;
	}
	return;
}
int main() {
	int T;
	Node_t r=NULL;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			int v;
			scanf("%d",&v);
			r=Insert(v,r);
		}
		preorder(r);
		printf("\n");
		release(r);
		delete r;
		r=NULL;
	}
}
