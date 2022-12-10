//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 

{

    public:

    //Function to find a Mother Vertex in the Graph.

    void DFS(vector<int> adj[],vector<bool> &visited,int &count,int i){

        visited[i]=true;

        count++;

        for(int u:adj[i]){

            if(visited[u]==false)

                DFS(adj,visited,count,u);

        }

    }

 int findMotherVertex(int V, vector<int>adj[])

 {

     

     for(int i=0;i<V;i++){

         vector<bool> visited(V,false);

         int count=0;

         DFS(adj,visited,count,i);

         if(count==V)

             return i;

     }

     return -1;

     // Code here

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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends