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

  bool _search(Node *subroot, int key){
    if (!subroot) {return false;} 
    if (key == subroot->data){return true;}
    if (key < subroot->data){
        return _search(subroot->left, key);
    }
    return _search(subroot->right, key);
    }
    

public:
  Bst() { root = nullptr; }
  void insert(int x) { _insert(root, x); }
  bool search(int key) { _search(root, key); }
  void print() { _print(root); }
};

int main() {
  Bst tree;
  tree.insert(11);
  tree.insert(13);
  tree.insert(5);
  tree.insert(7);
  tree.insert(17);
  tree.print();

  tree.search(7);
}