#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node
{
  int data;
  Node* left;
  Node* right;
};

// Function to perform an inorder traversal of the binary tree
void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);  // Visit left subtree
  cout << root->data << " -> ";  // Print the current node
  inorder(root->right); // Visit right subtree
}

// Function to perform a preorder traversal of the binary tree
void preorder(Node* root)
{
  if (root == NULL)
    return;
  cout << root->data << " -> ";  // Print the current node
  preorder(root->left); // Visit left subtree
  preorder(root->right); // Visit right subtree
}

// Function to perform a postorder traversal of the binary tree
void postorder(Node* root)
{
  if (root == NULL)
    return;
  postorder(root->left); // Visit left subtree
  postorder(root->right); // Visit right subtree
  cout << root->data << " -> ";  // Print the current node
}

// Function to create a new node with given data
Node* createNode(int item)
{
  Node* newNode = new Node;
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a new node as the left child of a given node
Node* insertLeft(Node* root, int item)
{
  root->left = createNode(item);
  return root->left;
}

// Function to insert a new node as the right child of a given node
Node* insertRight(Node* root, int item)
{
  root->right = createNode(item);
  return root->right;
}

int main()
{
  // Creating a binary tree
  Node* root = createNode(7);
  insertLeft(root, 12);
  insertRight(root, 29);
  insertLeft(root->left, 15);
  insertRight(root->left, 26);

  // Displaying the traversals
  cout << "Inorder traversal\n";
  inorder(root);
  cout << "\nPreorder traversal\n";
  preorder(root);
  cout << "\nPostorder traversal\n";
  postorder(root);

  // Deallocating memory (freeing nodes)
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
