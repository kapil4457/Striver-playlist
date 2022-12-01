//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	
	//Using Dijkstra's Algorithm : (Gives TLE,but is  correct) 
    // int minimumCostPath(vector<vector<int>>& grid) 
    // {
    //     // Code here
    //     int n = grid.size();
    //     priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>>  , greater<pair<pair<int,int> , int>>>pq;
        
        
    //     pq.push({{0,0} ,grid[0][0] });
        
    //     int ans = INT_MAX;
    //     while(!pq.empty()){
    //     pair<int,int>temp = pq.top().first;
    //     int weight = pq.top().second;
    //     int x = temp.first;
    //     int y = temp.second;
        
    //     if(x == n-1  && y == n-1){
    //         ans = min(ans , weight);
    //     }
    //     pq.pop();
        
    //     if(x+1 < n ){
    //         pq.push({{x+1 , y} , weight+grid[x+1][y]});
    //     }
        
    //     if(y+1 < n){
            
    //         pq.push({{x , y+1} , weight+grid[x][y+1]});
    //     }
        
        
        
        
    //     }
        
        
    //     return ans;
    // }
    
    
    // Using Dynamic Programming 
    
      //Tabulation
      
//     int minSumPath(int n, int m, vector<vector<int> > &matrix){
//     vector<vector<int> > dp(n,vector<int>(m,0));
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m; j++){
//             if(i==0 && j==0) dp[i][j] = matrix[i][j];
//             else{
                
//                 int up = matrix[i][j];
//                 if(i>0) up += dp[i-1][j];
//                 else up += 1e9;
                
//                 int left = matrix[i][j];
//                 if(j>0) left+=dp[i][j-1];
//                 else left += 1e9;
                
//                 dp[i][j] = min(up,left);
//             }
//         }
//     }
    
//     return dp[n-1][m-1];
    
// }


//     int minimumCostPath(vector<vector<int>>& grid) {
//         int n = grid.size();
//         return minSumPath(n,n,grid);
//     }
    
    
    
    // GFG Way : (Accepts this)
    int minimumCostPath(vector<vector<int>> &grid){

        set<vector<int>> p;

        int dx[] = {-1,1,0,0};

        int dy[] = {0,0,1,-1};                          

        p.insert({grid[0][0],0,0});             

        int n = grid.size(),m = grid[0].size();

        vector<vector<int>> cost(n,vector<int>(m,1e8));

        cost[0][0] = grid[0][0];

        while(!p.empty()){

            auto t = p.begin();

            int a = (*t)[0], b = (*t)[1], c = (*t)[2];

            p.erase(t);

            for(int i=0;i<4;i++){

                int x = b+dx[i], y = c+dy[i];

                if(x<0 || y<0 || x>=n || y>=m){

                    continue;

                }

                if(cost[x][y] == 1e8){

                    cost[x][y] = a+grid[x][y];        

                    vector<int> v = {cost[x][y],x,y};

                    p.insert(v);

                }

            }

        }

        return cost[n-1][m-1];

    }
    
    
    
    

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends