//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
const int mod = 1e9+7;
class Solution {
 public:
   int dfs(vector<int>adj[],int src,int dst,int k,vector<vector<long long int>>& t)
   {
       if(k==0 && src==dst)
       {
           return 1;
       }
       if(k==0 && src != dst)
           return 0;
       if(k<0)
           return 0;
       if(t[src][k] != -1)
           return t[src][k];
       long long int ans = 0;
       for(auto &x : adj[src])
       {
           ans += dfs(adj,x,dst,k-1,t)%mod;
       }
       return (t[src][k] = ans % mod);
   }
int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k)
{
    // Code here
    vector<vector<long long int>>t(graph.size()+1,vector<long long int>(k+1,-1));
    vector<int>adj[graph.size()+1];
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            if(graph[i][j]==1)
            {
                adj[i].push_back(j);
            }
        }
    }
    return dfs(adj,u,v,k,t);
}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends