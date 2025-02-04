#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

class Bst {
  Node *root;

  // Function to find the minimum node in the right subtree
  Node* find_min(Node* subroot){
    while (subroot->left) {
      subroot = subroot->left;
    }
    return subroot;
  }

  void _delete_node(Node *&subroot, int key){
    if (!subroot) return; // Base case: node not found

    // Find the node to delete
    if (key == subroot->data) {
      // Case 1: No children (leaf node)
      if (!subroot->left && !subroot->right) {
        delete subroot;
        subroot = nullptr;
      }
      // Case 2: Only right child
      else if (!subroot->left) {
        Node* temp = subroot;
        subroot = subroot->right;
        delete temp;
      }
      // Case 3: Only left child
      else if (!subroot->right) {
        Node* temp = subroot;
        subroot = subroot->left;
        delete temp;
      }
      // Case 4: Two children
      else {
        Node* successor = find_min(subroot->right); // Find the in-order successor
        subroot->data = successor->data; // Replace data with the successor's data
        _delete_node(subroot->right, successor->data); // Delete the successor
      }
    }
    // Search for the node recursively
    else if (key < subroot->data) {
      _delete_node(subroot->left, key);
    } else {
      _delete_node(subroot->right, key);
    }
  }

  bool _search(Node *subroot, int key) {
    if (!subroot) return false; // Base case: key not found
    if (key == subroot->data) return true; // Key found
    if (key < subroot->data) 
      return _search(subroot->left, key); // Search left subtree
    return _search(subroot->right, key); // Search right subtree
  }

  void _print(Node *subroot) {
    if (!subroot) {
      return;
    } else {
      _print(subroot->left);
      cout << subroot->data << " ";
      _print(subroot->right);
    }
  }
  
  void _insert(Node *&subroot, int x) {
    if (!subroot) { // if(root == nullptr)
      subroot = new Node(x);
    } else {
      if (x < subroot->data) {
        _insert(subroot->left, x);
      } else {
        _insert(subroot->right, x);
      }
    }
  }

public:
  Bst() { root = nullptr; }
  void insert(int x) { _insert(root, x); }
  bool search(int key) { return _search(root, key); }
  void print() { _print(root); }
  void delete_node(int key) { _delete_node(root, key); } // Added semicolon
};

int main() {
  Bst tree;
  tree.insert(11);
  tree.insert(13);
  tree.insert(5);
  tree.insert(7);
  tree.insert(17);
  
  cout << "BST contents: ";
  tree.print(); // Print the tree
  cout << endl;

  // Search for a key
  int key = 7;
  if (tree.search(key))
    cout << "Found " << key << " in BST." << endl;
  else
    cout << key << " not found in BST." << endl;

  // Delete a node
  tree.delete_node(7);
  cout << "After deleting 7: ";
  tree.print(); // Print the tree again after deletion
  cout << endl;

  return 0;
}
