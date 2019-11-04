#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// A Treap Node
struct TreapNode
{
	int data;
	int priority;
	TreapNode* left, *right;

	// Constructor
	TreapNode(int data)
	{
		this->data = data;
		this->priority = rand() % 100;
		this->left = this->right = nullptr;
	}
};

void rotateLeft(TreapNode* &root)
{
	TreapNode* R = root->right;
	TreapNode* X = root->right->left;

	// rotate
	R->left = root;
	root->right = X;

	// set new root
	root = R;
}



void rotateRight(TreapNode* &root)
{
	TreapNode* L = root->left;
	TreapNode* Y = root->left->right;

	// rotate
	L->right = root;
	root->left = Y;

	// set new root
	root = L;
}


void insertNode(TreapNode* &root, int data)
{
	// base case
	if (root == nullptr)
	{
		root = new TreapNode(data);
		return;
	}

	if (data < root->data)
	{
		insertNode(root->left, data);

	
		if (root->left != nullptr && root->left->priority > root->priority)
			rotateRight(root);
	}
	else
	{
		insertNode(root->right, data);

		
		if (root->right != nullptr && root->right->priority > root->priority)
			rotateLeft(root);
	}
}

bool searchNode(TreapNode* root, int key)
{
	// if key is not present in the key
	if (root == nullptr)
		return false;

	// if key is found
	if (root->data == key)
		return true;

	// if given key is less than the root node, search in the left subtree
	if (key < root->data)
		return searchNode(root->left, key);

	// else search in the right subtree
	return searchNode(root->right, key);
}

void deleteNode(TreapNode* &root, int key)
{
	
	if (root == nullptr)
		return;

	
	if (key < root->data)
		deleteNode(root->left, key);


	else if (key > root->data)
		deleteNode(root->right, key);


	else
	{

		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}

		// Case 2: node to be deleted has two children
		else if (root->left && root->right)
		{
			// if left child has less priority than right child
			if (root->left->priority < root->right->priority)
			{
				// call rotateLeft on root
				rotateLeft(root);

				// recursively delete the left child
				deleteNode(root->left, key);
			}
			else
			{
				// call rotateRight on root
				rotateRight(root);

				// recursively delete the right child
				deleteNode(root->right, key);
			}
		}

		// Case 3: node to be deleted has only one child
		else
		{
			// find child node
			TreapNode* child = (root->left)? root->left: root->right;
			TreapNode* curr = root;

			root = child;

			// deallocate the memory
			delete curr;
		}
	}
}
void printTreap(TreapNode *root, int space = 0, int height = 10)
{
	// Base case
	if (root == nullptr)
		return;

	// increase distance between levels
	space += height;

	// print right child first
	printTreap(root->right, space);
	cout << endl;

	// print current node after padding with spaces
	for (int i = height; i < space; i++)
		cout << ' ';
	cout << root->data << "(" << root->priority << ")\n";

	// print left child
	cout << endl;
	printTreap(root->left, space);
}

// main function
int main()
{
	// Treap keys
	int keys[] = { 5, 2, 1, 4, 9, 8, 10 };

	int n = sizeof(keys)/sizeof(int);

	// Construct a Treap
	TreapNode* root = nullptr;
	for (int key: keys)
		insertNode(root, key);

	cout << "Constructed Treap:\n\n";
	printTreap(root);

	cout << "\nDeleting node 1:\n\n";
	deleteNode(root, 1);
	printTreap(root);

	cout << "\nDeleting node 5:\n\n";
	deleteNode(root, 5);
	printTreap(root);

	cout << "\nDeleting node 9:\n\n";
	deleteNode(root, 9);
	printTreap(root);

	return 0;
}
