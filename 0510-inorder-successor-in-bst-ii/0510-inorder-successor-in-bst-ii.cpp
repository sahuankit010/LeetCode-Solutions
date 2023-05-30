/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        
        // down portion
        
        if(node-> right){
            node = node -> right;
            
            while(node->left){
                node = node->left;
            }
            return node;
        }
        
        // upper portion
        while(node->parent && node->parent->right == node){
            node = node->parent;
        }
        return node -> parent;
        
    }
};