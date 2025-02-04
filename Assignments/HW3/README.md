# Binary Search Tree (BST) - delete_node Method

This README explains the implementation of the `delete_node` method in a Binary Search Tree (BST) data structure. The method is responsible for deleting a node from the BST while maintaining its properties.

## Overview of the `delete_node` Method

The `delete_node` method handles three different cases when deleting a node in a BST:
1. **Node with no children** (leaf node).
2. **Node with one child** (either left or right child).
3. **Node with two children**.

The key principle is to ensure the tree remains valid after a node is deleted by preserving the BST property (i.e., all left descendants are smaller and all right descendants are larger).

### 1. Node with No Children (Leaf Node)
If the node to be deleted has no children (i.e., it's a leaf node), we simply delete the node and set the corresponding pointer in the parent to `nullptr`.

- **Action**: The node is deleted and its pointer is set to `nullptr` (indicating no child).
  
### 2. Node with One Child
If the node to be deleted has only one child, we bypass the node by updating the parent's pointer to point to the single child.

- **Action**: The parent node's pointer is updated to the child node, and the node to be deleted is removed from memory.

### 3. Node with Two Children
If the node to be deleted has two children, we cannot simply remove the node because doing so would disrupt the structure of the tree. Instead, we replace the node with a suitable candidate that preserves the BST property.

- **In-order Successor**: The most appropriate candidate for replacement is the **in-order successor** (the smallest node in the right subtree).
  
  - The in-order successor is the leftmost node in the right subtree of the node to be deleted.
  - We replace the value of the node to be deleted with the value of its in-order successor.
  - After replacing the node’s value, we must recursively delete the in-order successor, which will be a node with one or zero children, simplifying the problem to one of the previous cases.
 
### How `find_min` Helps in Finding the In-Order Successor
When you're deleting a node from the BST that has two children, the in-order successor is the smallest node in the right subtree of the node you're deleting. The reason the right subtree contains the in-order successor is that the right subtree holds all values greater than the current node’s value, and the smallest of those values will be the in-order successor.

