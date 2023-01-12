class Solution {
public:
    vector<int> dfs(vector<vector<int>>&g,string &s,vector<int>&vis,int val,vector<int> &a){
		//We have a temp vector to keep the account of char in the sub trees
        vector<int>temp(26);
		//Making the visited node true or marking it visited
        vis[val]=1;
		
		//Now we start Traversing the neighboring nodes of the val node.
        for(int neig:g[val]){
		//We will call dfs only for the node which are not visited
            if(!vis[neig]){
                vector<int> child= dfs(g,s,vis,neig,a);
				
				//adding the label to the temp vector
                temp[s[neig]-'a']++;
				
				//adding the labels of all the subtree labels
                for(int i=0;i<26;i++){
                    temp[i]+=child[i];
                }
            }
        }
		//Finally adding temp value to the ans vector.
        a[val]+=temp[s[val]-'a']+1;
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        vector<vector<int>>g(n);
		//First step is to convert the edges into the graph
		//so as given undirected graph so we have made 2d vector for graph
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
		//Second step is to make the visited vector 
		//inorder to keep the count of the node that has been visited.
        vector<int>vis(n),ans(n),temp(26);
        dfs(g,labels,vis,0,ans);
        return ans;
    }

};