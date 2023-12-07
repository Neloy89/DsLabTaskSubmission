#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " -> ";
  inorder(root->right);
}

void preorder(Node* root)
{
  if (root == NULL)
    return;
  cout << root->data << " -> ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " -> ";
}

Node* createNode(int item)
{
  Node* newNode = new Node;
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertLeft(Node* root, int item)
{
  root->left = createNode(item);
  return root->left;
}

Node* insertRight(Node* root, int item)
{
  root->right = createNode(item);
  return root->right;
}

int main()
{
  Node* root = createNode(7);
  insertLeft(root, 12);
  insertRight(root, 29);
  insertLeft(root->left, 15);
  insertRight(root->left, 26);

  cout << "Inorder  \n";
  inorder(root);
  cout << "\nPreorder \n";
  preorder(root);
  cout << "\nPostorder  \n";
  postorder(root);

  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
