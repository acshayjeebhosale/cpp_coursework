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

// Function to print level order traversal of a given binary tree
void levelOrderTraversal(Node* root)
{
	// base case
	if (root == nullptr) {
		return;
	}

	// create an empty queue and enqueue the root node
	list<Node*> queue;
	queue.push_back(root);

	// pointer to store the current node
	Node* curr = nullptr;

	// loop till queue is empty
	while (queue.size())
	{
		// process each node in the queue and enqueue their
		// non-empty left and right child
		curr = queue.front();
		queue.pop_front();

		cout << curr->key << " ";

		if (curr->left) {
			queue.push_back(curr->left);
		}

		if (curr->right) {
			queue.push_back(curr->right);
		}
	}
}

int main()
{
	Node* root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	levelOrderTraversal(root);

	return 0;
}