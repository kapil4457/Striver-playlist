//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
   int bfs(int source,int sink,vector<vector<int>> &g,int n,vector<int> &parent)
    {
        queue<pair<int,int>> q;
        vector<bool> vis(n,0);
        q.push({source, INT_MAX});
        vis[source]=1;
        
        while(!q.empty())
        {
            source=q.front().first;
            int cap=q.front().second;
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                if(g[source][i] && !vis[i])
                {
                    parent[i]=source;
                    
                    if(i==sink)
                        return min(cap,g[source][i]);
                        
                    q.push({i,min(cap,g[source][i])});
                    vis[i]=1;
                }
            }
        }
        return 0;
    }
    
int ford_fulkerson(int source,int sink,vector<vector<int>> &g,int n)
    {
        int flow=0;
        vector<int> parent(n,-1);
        
        int min_cap;
        while(min_cap=bfs(source,sink,g,n,parent))
        {
            flow+=min_cap;
            
            int u,v=sink;
            while(v!=source)
            {
                u=parent[v];
                g[u][v]-=min_cap;
                g[v][u]+=min_cap;
                v=u;
            }
        }
        
        return flow;
    }
    
    int findMaxFlow(int n,int m,vector<vector<int>> e)
    {
        vector<vector<int>> g(n+1,vector<int>(n+1,0));
        int i;
        
        for(i=0;i<m;i++)
        {
            g[e[i][0]][e[i][1]]+=e[i][2];
            g[e[i][1]][e[i][0]]+=e[i][2];
        }
        
        return ford_fulkerson(1,n,g,n+1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.findMaxFlow(N, M, Edges);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends