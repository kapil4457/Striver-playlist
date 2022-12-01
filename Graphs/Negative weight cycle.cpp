//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
         vector<int>dist(V,1e8);
         dist[S] = 0;
        for(int i=0 ; i < V-1 ; i ++){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
        
        
        
        // Checking the negative cycles
        for(auto it: edges){
              int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    return {-1};
                }
            
        }
        
        return dist;
    }
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>temp = bellman_ford(n,edges , 0);
	    
	    if(temp[0]==-1){
	        return 1;
	    }else{
	        return 0;
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends