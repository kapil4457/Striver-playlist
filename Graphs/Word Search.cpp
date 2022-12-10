//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int ans = 0;


bool isValid(int i ,int j , int r , int c){
    if(i>=0 && i < r && j >= 0 && j < c){
        return true;
    }
    return false;
}
    void dfs(vector<vector<char>>& board , int i , int  j , string word , int currIdx,vector<vector<int>>& vis){
        if(currIdx == word.length()-1 && board[i][j]==word[currIdx]){
            ans=1;
            return;
        }
        
        if(vis[i][j]){
            return;
        }
        

        vis[i][j]=1;
        
        
        int r[] = {1,-1,0,0};
        int c[] = {0,0 ,1,-1 };
        
        for(int  k =0 ; k < 4 ; k ++){
            int nr = r[k]+i;
            int nc = c[k]+j;
            if(isValid(nr,nc,board.size() , board[0].size())  && !vis[nr][nc]  && word[currIdx+1]==board[nr][nc]){
                dfs(board , nr,nc,word,currIdx+1,vis);
            }
        }
        
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0 ; i <n ;i ++ ){
            for(int j =0 ; j < m ;j ++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    dfs(board , i , j , word , 0, vis);
                }
                if(ans){
                    break;
                }
            }
            
            if(ans){
                break;
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
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends