//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Bridge{
    int *low,*dis,time;
    vector<vector<int> > ans;
    public:
    Bridge(int n){
        low=new int[n];
        dis=new int[n];
        for(int i=0;i<n;i++)
            dis[i]=low[i]=0;
        time=0;
    }
    void dfs(int u,vector<int> adj[],int parent){
        dis[u]=low[u]=++time;
        for(auto v: adj[u]){
            if(!dis[v]){
                dfs(v,adj,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>dis[u]){
                    if(u<v)
                        ans.push_back({u,v});
                    else
                        ans.push_back({v,u});
                }
            }
            if(v!=parent)
                low[u] = min(low[u],dis[v]);
        }
    }
    vector<vector<int> > sol(){
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    Bridge bridges(V);
        bridges.dfs(0,adj,-1);
	    return bridges.sol();
	}
};


//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends