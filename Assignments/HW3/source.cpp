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

  Node* find_min(Node* subtroot, int key){
    while(subtroot->left){
      subtroot = subtroot->left;
    }
    return subtroot;
  }

  void _delete_node(Node *&subroot, int key){
    if(!subroot){return;}
    if(key == subroot->data){
      if (subroot->right == nullptr && subroot->left == nullptr){
        delete subroot;
      }
      if(!subroot->left){
        Node* temp = subroot;
        subroot = subroot->right;
        delete temp;
      }
      if(!subroot->right){
        Node* temp = subroot;
        subroot = subroot->left;
        delete temp;
      }
      else{
        Node* successor = find_min(subroot, key);
        subroot->data = successor->data;
        _delete_node(successor->right, successor->data );

       }

    }
    if (key > subroot->data){
      _delete_node(subroot->right, key);
    }
    if (key < subroot->data){
      _delete_node(subroot->left, key);
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
  bool search(int key) { return _search(root, key);}
  void print() { _print(root); }
  void delete_node(int key) {}
};

int main() {
  Bst tree;
  tree.insert(11);
  tree.insert(13);
  tree.insert(5);
  tree.insert(7);
  tree.insert(17);
  tree.print();

  int key = 7;
  if (tree.search(key))
    cout << "Found " << key << " in BST." << endl;
  else
    cout << key << " not found in BST." << endl;

  return 0;
}