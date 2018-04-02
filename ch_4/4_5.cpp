#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left_child;
  Node *right_child;

  // constructor
  Node(int x) {
    data = x;
    left_child = NULL;
    right_child = NULL;
  }
};

Node* create_minimal_BST(vector<int> arr, int low, int high)
{
    if (low > high) {
        return NULL;
    }
    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    node->left_child = create_minimal_BST(arr, low, mid - 1);
    node->right_child = create_minimal_BST(arr, mid + 1, high);

    return node;
}

Node *create_minimal_BST(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;
    return create_minimal_BST(arr, 0, ((int)arr.size()) - 1);
}


void preOrder(Node *node)
{
  if (node == NULL) {
    return;
  } else {
    cout << node->data << " ";
    preOrder(node->left_child);
    preOrder(node->right_child);
  }
}

bool validateBST(Node* root, int min, int max)
{
  if (root == NULL) {
    return true;
  }

  if (root->data < min || root->data > max) {
    return false;
  }

  return validateBST(root->left_child, min, root->data - 1) && validateBST(root->right_child, root->data + 1, max);
}

bool validateBST(Node* root)
{
  return validateBST(root, -2e9, 2e9);
}

int main()
{

  //vector<int> array = {1, 2, 3, 4, 5, 6, 7};
  vector<int> array = {1, 7, 3, 4, 5, 6, 2};

  cout << "the implementation of 4_5.cpp" << endl;

  Node *root = create_minimal_BST(array);
  preOrder(root);

  cout << "is BST? " << validateBST(root) << endl;
 
  cout << endl;

  return 0;
}
