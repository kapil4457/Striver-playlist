//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends
class Solution{
    public:
   int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code here
        
        vector<vector<int>> graph(n);
        unordered_map<int, int> mp;
        vector<int> indegree(n,0);
        
        // create the graph from dependency list
        for(int i = 0; i < dependency.size(); ++i) {
            graph[dependency[i].first].push_back(dependency[i].second);
        }
        
        // create the map with the duration values for each node 
        for(int i = 0; i < n; ++i) {
            mp[i] = duration[i];   
        }
        
        // Find the node with indegree 0
        for(int i = 0; i < n; ++i) {
            for(auto& x: graph[i]) {
                indegree[x]++;
            }
        }
        
        
        // Kahn's Algorithm
        
        queue<int> q;
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        int wt = INT_MIN;
        
        while(!q.empty()) {
            
            int frontNode = q.front();
            q.pop();
            count++;

            wt = max(wt, mp[frontNode]);
            
            for(auto& x : graph[frontNode]) {
                
                indegree[x]--;
                
                mp[x] = max(mp[x], duration[x]+mp[frontNode]);
                wt = max(wt, mp[x]);
                
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        
        if(count == n) return wt;
        else return -1;
        
    }
};

// 0  1         2
// 3  4         3
// 2            3
// 5            2







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends