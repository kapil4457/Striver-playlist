//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


// BFS

    public:
    
vector<vector<int> > findDistance(vector<vector<char> >& grid, int rows, int cols) { 
    vector<vector<int> > ans(rows, vector<int> (cols, 0));
    
    queue<int> q;
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(grid[i][j] == 'O') {
                ans[i][j] = INT_MAX;
            }
            else if(grid[i][j] == 'W')
                ans[i][j] = -1;
            else if(grid[i][j] == 'B') {
                ans[i][j] = 0;
                q.push(i * cols + j);
            }
        }
    }
    
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    
    
    int level = 0;
    
    while(!q.empty()) {
        int size = q.size();
        
        while(size--) {
            int curCell = q.front();
            q.pop();
            
            int curCellX = curCell / cols;
            int curCellY = curCell % cols;
            
            for(int k = 0; k < dirs.size(); ++k) {
                int nextCellX = curCellX + dirs[k][0];
                int nextCellY = curCellY + dirs[k][1];
                
                if(nextCellX >= 0 && nextCellX < rows && nextCellY >= 0 && nextCellY < cols && ans[nextCellX][nextCellY] == INT_MAX) {
                    ans[nextCellX][nextCellY] = level + 1;
                    q.push(nextCellX * cols + nextCellY);
                }
            }
            
        }
        ++level;
    }
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(ans[i][j] == INT_MAX)
                ans[i][j] = -1;
        }
    }
    
    return ans;
} 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends