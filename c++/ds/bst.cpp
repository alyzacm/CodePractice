// Implementation of Binary Search Tree
// Design from mycodeschool
// Includes:
// 	insert
// 	search
// 	height
#include <iostream>
#include <algorithm>
using namespace std;

struct BSTNode{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode* makeNode(int data){
	BSTNode *newNode = new BSTNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BSTNode* insert(BSTNode *root, int data){
	if(root == NULL){
		root = makeNode(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(BSTNode *root, int data){
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return search(root->left, data); 
	}
	else{
		return search(root->right, data);
	}
}

int height(BSTNode *root){
	if(root == NULL){
		return -1;
	}
	else{
		return max(height(root->left), height(root->right)) + 1;
	}
}

void testSearch(BSTNode *root){
	int num;
	cout << "Enter number to search for: ";
	cin >> num;

	if(search(root, num)){
		cout << "Found" << endl;
	}
	else{
		cout << "Not Found" << endl;
	}

}

void testHeight(BSTNode *root){
	cout << "Height is " << height(root) << endl;
}

int main(){
	//empty BST
	BSTNode *root = NULL;

	root = insert(root, 12);
	root = insert(root, 33);
	root = insert(root, 7);
	root = insert(root, 35);
	root = insert(root, 8);
	root = insert(root, 15);
	root = insert(root, 77);

	testSearch(root);
	testHeight(root);
	return 0;
}