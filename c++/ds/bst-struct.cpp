#include <iostream>
#include <algorithm>
#include <vector>
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
	int height();
	bool checkBST(); //incomplete
	void top_view();
	void left(node *leaf);
	void right(node *leaf);
	int find_min();
	int find_max();
	void destroy_tree();


private:
	void insert(node *leaf, int data);
	bool search(node *leaf, int data);
	void inOrder(node *leaf);
	void preOrder(node *leaf);
	void postOrder(node *leaf);
	int height(node *leaf);
	bool checkBST(node *leaf, vector<int> &tree); //incomplete
	void top_view(node *leaf);
	int find_min(node *leaf);
	int find_max(node *leaf);
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

int bst::height(){
	return height(root);
}

bool bst::checkBST(){
	vector<int> tree;
	return checkBST(root, tree);
}

void bst::top_view(){
	top_view(root);
}

void bst::left(node *leaf){
	if(leaf ->left != NULL){
		left(leaf->left);
	}
	if(leaf != NULL){
		cout << leaf->data << " ";
	}
}

void bst::right(node *leaf){
	if(leaf != NULL){
		cout << leaf->data << " ";
	}
	if(leaf->right != NULL){
		right(leaf->right);
	}
}

int bst::find_min(){
	return find_min(root);
}

int bst::find_max(){
	return find_max(root);
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

int bst::height(node *leaf){
	if(leaf == NULL){
		return -1;
	}
	else{
		return max(height(leaf->left), height(leaf->right)) + 1;
	}
}

bool bst::checkBST(node *leaf, vector<int> &tree){
	bool leftCheck = true;
	bool rightCheck = true;

	if(leaf == NULL){
		return true;
	}	
	if(leaf->left){
		leftCheck = checkBST(leaf->left, tree);
	}

	if(!tree.empty() && root->data <= tree.back()){
		return false;
	}
	tree.push_back(leaf->data);

	if(leaf->right){
		rightCheck = checkBST(leaf->right, tree);
	}
	return leftCheck && rightCheck;
}

void bst::top_view(node *leaf){
	left(root);
	if(root->right != NULL){
		right(root->right); 
	}
}

int bst::find_min(node *leaf){
	if(leaf == NULL){
		cout << "Error: tree empty" << endl;
		return -1;
	}
	else if(leaf -> left == NULL){
		return leaf->data;
	}
	return find_min(leaf->left);
}

int bst::find_max(node *leaf){
	if(leaf == NULL){
		cout << "Error: tree empty" << endl;
		return -1;
	}
	else if(leaf->right == NULL){
		return leaf->data;
	}
	return find_max(leaf->right);
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
	root.insert(1);
	root.insert(4);
	root.insert(14);
	root.insert(26);
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
	cout << root.height();
	cout << endl;
	root.top_view();
	cout << endl;
	if(root.checkBST()){
		cout << "bst" << endl;
	}
	else{
		cout << "not bst" << endl;
	}

	cout << "min: " << root.find_min() << endl;
	cout << "max: " << root.find_max() << endl;

	return 0;
}