//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Disjoint{
    vector<int>parent , rank,size;
    public :
    
     Disjoint(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        
        for(int i =0 ; i <= n ; i ++){
            parent[i]=i;
            rank[i]=i;
        }
    }
    
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node] = findUParent(parent[node]);
    }
    
    
    void unionByRank(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v)
            return;
        
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
    private:
    bool isValid(int adjr , int adjc , int n , int m){
        if(adjr >=0 && adjr<n && adjc>=0 && adjc<m){
            return true;
        }
        
        return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjoint ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt =0;
        vector<int>ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] =1;
            cnt++;
            
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            
            for(int i =0 ; i < 4; i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                
                if(isValid(adjr , adjc,n,m)){
                    if(vis[adjr][adjc]){
                        int nodeNo = row * m  + col;
                        int adjNodeNo = adjr * m + adjc;
                        if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                            cnt--;
                            ds.unionByRank(nodeNo , adjNodeNo);
                        }
                    }
                }
            }
            
            
            
            ans.push_back(cnt);
            
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends