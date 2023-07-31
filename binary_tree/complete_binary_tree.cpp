#include <iostream>
#include <list>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Function to check if a given binary tree is complete or not
bool isComplete(Node* root)
{
	// return if the tree is empty
	if (root == nullptr) {
		return true;
	}

	// create an empty queue and enqueue the root node
	list<Node*> queue;
	queue.push_back(root);

	// pointer to store the current node
	Node* front = nullptr;

	// flag to mark the end of full nodes
	bool flag = false;

	// loop till queue is empty
	while (queue.size())
	{
		// dequeue front node
		front = queue.front();
		queue.pop_front();

		// if we have encountered a non-full node before and the current node
		// is not a leaf, a tree cannot be complete
		if (flag && (front->left || front->right)) {
			return false;
		}

		// if the left child is empty and the right child exists,
		// a tree cannot be complete
		if (front->left == nullptr && front->right) {
			return false;
		}

		// if the left child exists, enqueue it
		if (front->left) {
			queue.push_back(front->left);
		}
		// if the current node is a non-full node, set the flag to true
		else {
			flag = true;
		}


		// if the right child exists, enqueue it
		if (front->right) {
			queue.push_back(front->right);
		}
		// if the current node is a non-full node, set the flag to true
		else {
			flag = true;
		}
	}

	return true;
}

int main()
{
	/* Construct the following tree
			  1
		   /    \
		  2      3
		 / \    / \
		4   5  6   7
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	if (isComplete(root)) {
		cout << "Complete binary tree";
	}
	else {
		cout << "Not a complete binary tree";
	}

	return 0;
}