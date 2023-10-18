class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        // Create an adjacency list to represent the tree structure.
        unordered_map<int, vector<int>> adjList;
        
        // Create a mapping to track the parent of each child node.
        unordered_map<int, int> childToParent;

        // Build the adjacency list and child-to-parent mapping.
        for(int i=0; i<n; i++){
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1){
                adjList[i].push_back(leftC);
                
                // Check if a child already has a parent; return false if so.
                if(childToParent.find(leftC) != childToParent.end()){
                    return false;
                }
                
                // Update the parent for the left child.
                childToParent[leftC] = i;
            }

            if(rightC != -1){
                adjList[i].push_back(rightC);
                
                // Check if a child already has a parent; return false if so.
                if(childToParent.find(rightC) != childToParent.end()){
                    return false;
                }
                
                // Update the parent for the right child.
                childToParent[rightC] = i;
            }
        }
        
        int root = -1;

        // Find the root node of the binary tree.
        for(int i = 0; i < n; i++){

            // If a node has no parent, and we haven't found a root yet, set it as the root.
            if(childToParent.find(i) == childToParent.end()){
                if(root != -1) return false; // If we already found a root, return false.
                root = i;
            }
        }
        
        // If no root node was found, return false.
        if(root == -1) return false;
        
        // Perform a breadth-first traversal to ensure that all nodes are connected.
        vector<bool> visited(n, false);
        queue<int> q;
        
        int count = 1;
        q.push(root);
        visited[root] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &child: adjList[node]){
                if(!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                    count++;
                }
            }
        }
        
        // Check if all nodes were reached during traversal.
        return count == n;
    }
};
