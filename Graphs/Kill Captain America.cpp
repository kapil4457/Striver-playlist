//{ Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

// } Driver Code Ends



class Solution{
public:
  void dfs(vector<int>adj[],vector<int>&vis,int u)
   {
       if(vis[u])
       return ;
       
       vis[u]=1;
       for(auto v:adj[u])
       {
           if(!vis[v])
           dfs(adj,vis,v);
       }
   }
   int captainAmerica(int n, int m, vector<vector<int>> &edge)
   {
      vector<int>adj[n+1];
      vector<int>g[n+1]; // orginal graph
      
      for(int i=0;i<m;i++)
      {
          adj[edge[i][1]].push_back(edge[i][0]); // transpose graph
      }
      
      int mother=-1;
      vector<int>vis(n+1,0);
      
      for(int i=1;i<=n;i++)
      {
          if(!vis[i])
          {
              dfs(adj,vis,i);
              mother=i; // consider last vertex to be mother vertex
          }
      }
      
      fill(vis.begin(),vis.end(),0);
      
      dfs(adj,vis,mother); // if the last vertex is mother all nodes should be vis in one dfs only
      
      for(int i=1;i<=n;i++)
      if(!vis[i])
      return 0;
      
      for(int i=0;i<m;i++)
      {
          g[edge[i][0]].push_back(edge[i][1]);
      }
      
      queue<int>q;
      int ans=1;
      q.push(mother);
      fill(vis.begin(),vis.end(),0);
      
      while(!q.empty())
      {
          auto u=q.front();
          q.pop();
          
          vis[u]=true;
          
          for(auto v:g[u])
          {
              if(!vis[v])
              {
                  q.push(v);
                  ans++;
              }
          }
      }
      
      return ans;
      
   } 
};

//{ Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}
// } Driver Code Ends