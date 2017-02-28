#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

class bst{
public:
	bst();
	~bst();
	
	node* makeNode(int data);
	void insert(int data);
	bool search(int data);
	void inOrder();
	void preOrder();
	void postOrder();
	void destroy_tree();

private:
	void insert(node *leaf, int data);
	bool search(node *leaf, int data);
	void inOrder(node *leaf);
	void preOrder(node *leaf);
	void postOrder(node *leaf);
	void destroy_tree(node *leaf);

	node *root;
};

bst::bst(){
	root = NULL;
}

void bst::insert(int data){
	if(root != NULL){
		insert(root, data);
	}
	else{
		root = makeNode(data);
	}
}

bool bst::search(int data){
	return search(root, data);
}

void bst::inOrder(){
	inOrder(root);
}

void bst::preOrder(){
	preOrder(root);
}

void bst::postOrder(){
	postOrder(root);
}

void bst::destroy_tree(){
	destroy_tree(root);
}

//===PUBLIC FUNCTIONS===

node* bst::makeNode(int data){
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void bst::insert(node *leaf, int data){
	if(data <= leaf->data){
		if(leaf->left != NULL){
			insert(leaf->left, data);
		}
		else{
			leaf->left = makeNode(data);
		}
	}
	else if(data > leaf->data){
		if(leaf->right != NULL){
			insert(leaf->right, data);
		}
		else{
			leaf->right = makeNode(data);
		}
	}
}

bool bst::search(node *leaf, int data){
	if(leaf == NULL){
		return false;
	}
	if(leaf->data == data){
		return true;
	}
	if(data < leaf->data){
		return search(leaf->left, data);
	}
	else{
		return search(leaf->right, data);
	}
}

void bst::inOrder(node *leaf){
	if(leaf->left != NULL){
		inOrder(leaf->left);
	}
	if(leaf != NULL){
		cout << leaf->data << " ";
	}
	if(leaf->right != NULL){
		inOrder(leaf->right);
	}
}

void bst::preOrder(node *leaf){
	if(leaf != NULL){
		cout << leaf->data << " ";
	}
	if(leaf->left != NULL){
		preOrder(leaf->left);
	}
	if(leaf->right != NULL){
		preOrder(leaf->right);
	}
}

void bst::postOrder(node *leaf){
	if(leaf->left != NULL){
		postOrder(leaf->left);
	}
	if(leaf->right != NULL){
		postOrder(leaf->right);
	}
	if(leaf != NULL){	
		cout << leaf->data << " ";
	}
}

void bst::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
		leaf = NULL;
	}
}

bst::~bst(){
	destroy_tree();
}

int main(){
	bst root; //create empty tree
	root.insert(10);
	root.insert(5);
	root.insert(15);
	root.insert(27);
	root.insert(3);
	root.insert(7);

	//test search
	// 	int number;
	// cout << "Number to search for: ";
	// cin >> number;
	// if(root.search(number)){
	// 	cout << "Found" << endl;
	// }
	// else{
	// 	cout << "Not found" << endl;
	// }

	root.inOrder();
	cout << endl;
	root.preOrder();
	cout << endl;
	root.postOrder();
	cout << endl;

	return 0;
}