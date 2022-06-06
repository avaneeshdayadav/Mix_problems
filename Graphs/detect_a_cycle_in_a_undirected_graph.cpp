#include <bits/stdc++.h>
using namespace std;

// Problem link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    bool dfs(vector<int> adj[], vector<int> &vis, int currNode, int parent)
    {
        if(vis[currNode] == 0)
        {
            // cout<<"CurrNOde "<<currNode<<" is not visited so visiting now."<<endl;
            vis[currNode] = 1;
            
            for(int i=0; i<adj[currNode].size(); i++)
            {
                if(vis[adj[currNode][i]] == 1 && parent != adj[currNode][i])
                {
                    // cout<<"Cycle detected, as node "<<adj[currNode][i]<<" was visited and its not equal to parent "<<parent<<endl;
                    return true;
                }
                    
                if(vis[adj[currNode][i]] == 0)
                {
                    if(dfs(adj, vis, adj[currNode][i], currNode))
                    {
                        // cout<<"Cycle detected for node "<<adj[currNode][i]<<endl;
                        return true;
                    }
                }
                    
            }
        }
        
        // cout<<"No cycle was detected at node "<<currNode<<" having parent "<<parent<<endl;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                // cout<<"NOde "<<i<<" is not visited so going to visit now. It has parent -1"<<endl;
                if(dfs(adj, vis, i, -1))
                    return true;
            }
                
        }
          
        // cout<<endl<<"Printing vis "<<endl;  
        // for(int i=0;i<vis.size();i++)
        //     cout<<vis[i]<<" ";
        // cout<<endl;
        return false;                
        
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}