#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* search(Node* root, int key)
{
	if (root == nullptr || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);

	return search(root->left, key);
}

Node* addNode(Node* root, int key) {

    if (root==nullptr) {
		Node* newNode = new Node;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->key = key;
		return newNode;
    }
    if (key < root->key) {
        root->left = addNode(root->left, key);
    }
    else {
        root->right = addNode(root->right, key);
    }
    return root;
}

bool searchNode(Node* root, int key) {
	while (root != nullptr && root->key != key)
	{
		if (key > root->key) {
			root = root->right;
		}
		else {
			root = root->left;
		}
}
	if (root == nullptr) return false;
	else if (root->key = key) return true;
	else return true;
}


Node* findMin(Node* node)
{
	Node* current = node;
	while (current != nullptr && current->left != nullptr) current = current->left;
	return current;
}

int findMinInt(Node* node)
{
	if (node == nullptr) return 0;
	while (node->left != nullptr) node = node->left;
	return node->key;
}


int findMaxInt(Node* node)
{
	if (node == nullptr) return 0;
	Node* current = node;
	while (current->right != nullptr) current = current->right;
	return current->key;
}

 Node* deleteNode(Node* root, int key)
{
	if (root == nullptr)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		if (root->left == nullptr and root->right == nullptr)
			return nullptr;


		else if (root->left == nullptr) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == nullptr) {
			struct Node* temp = root->left;
			free(root);
			return temp;
		}

		 Node* temp = findMin(root->right);


		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}



int main()
{
	Node* root = nullptr;
	int quit = 0;
	char command;
	while (quit == 0) {
		cin >> command;
		switch (command) {
		case '+': {
			int data, key;
			cin >> data;
			root=addNode(root, data);
			break;
		}
		case '-': {
			int key;
			cin >> key;
			root=deleteNode(root, key);
			break;
		}
		case '?': {
			int key;
			cin >> key;
			cout << searchNode(root, key) << endl;
			break;
		}
		case 'm': {
			cout << findMinInt(root) << endl;
			break;
		}
		case 'M': {
			cout << findMaxInt(root) << endl;
			break;
		}
		case 'q': {
			while (root != nullptr) {
				root= deleteNode(root, findMaxInt(root));
			}
			quit = 1;
		}
		}
	}
	return 0;
}