//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public :
  vector<int>parent;
   vector<int>rank;
   int findpar(int node){
       if(node==parent[node]){
           return node;
       }
       return parent[node]=findpar(parent[node]);
   }
   void disunion(int u,int v){
       u=findpar(u);
       v=findpar(v);
       if(rank[u]<rank[v]){
           parent[u]=v;
       }
       else if(rank[u]>rank[v]){
           parent[v]=u;
       }
       else{
           parent[u]=v;
           rank[v]++;
       }
   }
int detectCycle(int V, vector<int>adj[])
{
    // Code here
    parent.resize(V);
    rank.resize(V,0);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    for(int i=0;i<V;i++){
      for(auto it:adj[i]){
          if(parent[it]==parent[i] and i<it){
              return 1;
          }
          else{
              disunion(i,it);
          }
      }
    }
    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends