//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        if(A[0][0] == 0 || A[X][Y]==0){
            return -1;
        }
        
     queue<pair<pair<int, int>, int>>pq;

        
        pq.push({{0,0} , 0});
        int ans = INT_MAX;
        
        vector<vector<int>>vis(N,vector<int>(M,0));
        while(!pq.empty()){
            pair<int,int>ref = pq.front().first;
            int dist = pq.front().second;
            int x = ref.first;
            int y = ref.second;
            pq.pop();
            
            if(dist >= ans || vis[x][y]==1){
                continue;
            }
            
            vis[x][y] = 1;
            
            if(x==X  && y==Y){
                ans = min(ans , dist);
            }
            
            if(x+1 < N && A[x+1][y]==1 && vis[x+1][y]==0){
                pq.push({{x+1 , y} , dist+1});
            }
            
            if(y+1 < M && A[x][y+1]==1 && vis[x][y+1]==0){
                pq.push({{x,y+1} , dist+1});
            }
            
            if(x-1 >=0 && A[x-1][y]==1 && vis[x-1][y]==0){
                pq.push({{x-1,y} , dist+1});
                
            }
            
            if(y-1 >=0 && A[x][y-1]==1 && vis[x][y-1]==0){
                pq.push({{x,y-1} , dist+1});
            }
            
        }
        
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends