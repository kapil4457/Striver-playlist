//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool isValid(int i,int j,int row,int col) {
        if(i<0||j<0||i>=row||j>=col) return false;
        
        else return true;
    }
    
    vector<vector<int>> dirs={{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,1}};
    
    bool dfs(int i,int j,vector<vector<char>>& grid,string word,int row,int col){
        for(int k=0;k<8;k++)
        {
            int ni = i;
            int nj = j;
            int len=0;
            while(isValid(ni,nj,row,col) && grid[ni][nj]==word[len]) {
                ni+=dirs[k][0];
                nj+=dirs[k][1];
                len++;
            }
            if(len==word.length()) return true;
        }
        return false;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int row = grid.size();
	    int col = grid[0].size();
	    vector<vector<int>> ans;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(dfs(i,j,grid,word,row,col) && grid[i][j]==word[0]) ans.push_back({i,j});
	        }
	    }
	    
	    return ans;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}
// } Driver Code Ends