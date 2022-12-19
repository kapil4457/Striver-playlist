//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void precompute();
int helpSanta(int n, int m, vector<vector<int>> &g);

int main(){
	int t;cin>>t;
	precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		cout << helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends


// GFG way
void precompute(){
	int a = 0;
}
int kprime(int k){
    vector<int> arr(1000005,1);
    for(int i = 2 ; i < 1000005 ; i ++){
        if(arr[i] == 1){
            k--;
            if(k  == 0)
                return i;
            int j = 2;
            while(i * j < 1000005){
                arr[i * j] = 0;
                j++;
            }
        }
    }
}
void helper(vector<vector<int>> &adj,int i,vector<int> &vis,int &ds){ 
    vis[i] = 1;
    ds++;
    for(int j : adj[i]){
        if(vis[j] == 0)
        {
            helper(adj,j,vis,ds);
            
        }
    }
}
int helpSanta(int n, int m, vector<vector<int>> &g){
    vector<int> vis(n  + 1, 0);
    vector<int> adj[n + 1];
    int k = INT_MIN;
    if(m == 0) return -1;
    for(int i = 1; i <= n ; i ++){
        if(vis[i] == 0){
            int ds =0;
            helper(g,i,vis,ds);
            k= max(k,ds);
        }
    }
    return kprime(k);
}









// My way :

//   vector<bool>isPrime;
// //Union by size



// class DisjointSet{
//     public :
//     vector<int>parent , size;
//     DisjointSet(int n){
//         parent.resize(n+1);
//         size.resize(n+1,1);
        
        
//         for(int i =1 ; i <=n ; i++){
//             parent[i]=i;
//         }
//     }
    
    
    
//     int findParent(int a){
//         if(parent[a]==a)return a;
//         return parent[a] = findParent(parent[a]);
//     }
    
    
//     void unionBySize(int u , int v){
//         int ulp_u = findParent(u);
//         int ulp_v = findParent(v);
        
//         if(ulp_u == ulp_v){
//             return;
//         }
        
//         if(size[ulp_u] > size[ulp_v]){
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }else{
//               parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//     }
// };



// int findPrime( int m){
    
//     int cnt =0;
    
//     for(int i =2 ; i <= 1e5+7 ;i++ ){
//         if(isPrime[i]=true){
//             cnt++;
//         }
        
//         if(cnt==m){
//             return i;
//         }
//     }
// }

// void precompute(){
//      isPrime.resize(1e5+7,1);
//     isPrime[0]=isPrime[1]=false;
    
//     for(int i =2 ; i <= 1e5+7 ; i ++){
//         if(isPrime[i]==true){
//             for(int j = 2*i ; j <=1e5+7 ; j+=i ){
//                 isPrime[j]=false;
//             }
//         }
//     }
// }
// int helpSanta(int n, int m, vector<vector<int>> &g){
//     // Code here

//     DisjointSet ds(n);
    
//     for(int  i =0 ; i < m ; i ++){
//         ds.unionBySize(g[i][0] , g[i][1]);
//     }
    
    
//     int maxi = INT_MIN;
    
//     for(int i = 1 ; i <=n ; i ++){
//         maxi = max(maxi , ds.size[i]);
//     }
    
    
//     return findPrime(maxi);
    
    
// }