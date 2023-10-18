class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> childToParent;

        for(int i=0; i<n; i++){
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC!=-1){
                adjList[i].push_back(leftC);
                if(childToParent.find(leftC)!=childToParent.end()){
                    return false;
                }
                childToParent[leftC] = i;
            }

            if(rightC!=-1){
                adjList[i].push_back(rightC);
                if(childToParent.find(rightC)!=childToParent.end()){
                    return false;
                }
                childToParent[rightC] = i;
            }
        }
        cout<<"1\n";
        int root = -1;

        for(int i =0; i<n; i++){

            if(childToParent.find(i) == childToParent.end()){
                if(root != -1) return false;
                root  = i;
            }
        }
        cout<<"2\n";
        if(root==-1) return false;
        cout<<"3\n";

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
        cout<<"4\n";
        return count == n;
        
    }
};