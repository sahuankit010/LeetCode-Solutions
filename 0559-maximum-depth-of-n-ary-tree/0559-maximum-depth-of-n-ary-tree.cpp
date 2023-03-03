/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
//     int getHeight(Node *curr){
//         if(curr == nullptr) return 0;
//         for(int i=0; i<curr.)
        
//     }
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int max_Depth = 0;
        for (int i=0; i<root->children.size(); i++){
            max_Depth = max(max_Depth, maxDepth(root->children[i]));
        }
        return max_Depth + 1;
    }
};