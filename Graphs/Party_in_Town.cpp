//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &mat){
        // code here
        vector<int>dis(N+1 , INT_MAX);
        vector<int>adj[N];
        
        // Here we create  an adjacency list
        for(int i =0 ; i < mat.size() ; i ++){
          
             adj[mat[i][0]].push_back(mat[i][1]);
             adj[mat[i][1]].push_back(mat[i][0]);
            
        }
        
        
        
        // do bfs and store the distance of each element in a vector
        // the median distance is the answer
        
        vector<int>vis(N+1,0);
        queue<int>q;
        dis[1]=0;
        vis[1]=1;
       q.push(1);
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            vis[node]=1;
            
            for(auto it : adj[node]){
                if(!vis[it] || dis[node]+1 < dis[it]){
                    q.push(it);
                    dis[it]= min(dis[node]+1 , dis[it]);
                    
                    
                }
            }
        }
        
        sort(dis.begin() , dis.end());
        vector<int>non_duplicate;
        non_duplicate.push_back(dis[1]);
        for(int i =2; i <=N ; i++){
            int temp = non_duplicate.size();
            if(dis[i]!= non_duplicate[temp-1]){
                non_duplicate.push_back(dis[i]);
            }
        }
        
        
        int t = non_duplicate.size()/2;
        return non_duplicate[t];
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends