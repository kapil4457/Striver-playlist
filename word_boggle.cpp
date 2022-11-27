#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007ll //998244353ll
#define mii map<int, int>
#define pii pair<int, int>
int power(int a,int b){int result =1; while(b>0){if(b%2) result*=a; a*=a;b/=2;} return result;}
using namespace std;


void dfs(vector<vector<int>>&vis , vector<vector<char> >& board, string str ,int idx , set<string>&ans ,int i , int j){
   
     if(vis[i][j]){
        return;
    }
   
    if(idx >= str.length()){
        ans.insert(str);
        return;
    }
    
  
    
    vis[i][j]=1;
    
    
    int arr1[] = {1,1,1,-1,-1,-1,0,0};
    int arr2[] = {0,-1,1 ,0,1,-1 , 1,-1};
    
    
    for(int k=0 ; k < 8 ; k++){
        if(i+arr1[k] <board.size() && i+arr1[k] >=0  && j+arr2[k] <board[0].size() && j+arr2[k] >=0 && board[i+arr1[k] ][ j+arr2[k] ] ==str[idx]){
            dfs(vis,board,str,idx+1,ans,i+arr1[k],j+arr2[k]);
        }
    }
}
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    int n = board.size();
	    int m = board[0].size();
	 set<string>ans;
	 for(int word = 0 ; word < dictionary.size() ; word++){
	     string str = dictionary[word];
	    vector<vector<int>>vis(n,vector<int>(m,0));
	               vector<int>found = {0};
	   for(int i=0 ; i < n ; i ++){
	       for(int j =0 ; j < m ; j ++){
	           if(!vis[i][j] && board[i][j]==str[0] && count(ans.begin() , ans.end() , str)==0){
	               dfs(vis , board,str,1,ans , i , j);
	               if(found[0]){
	                   break;
	               }
	           }
	       }
	       if(found[0]){
	           break;
	       }
	   }
	   
	   if(found[0]){
	       continue;
	   }
	 }
	 
	 
vector<string>temp;
for(auto it  : ans){
    temp.push_back(it);
}
	    return temp;
	}

int main()
{

 return 0;
}









// Second Way




//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
void dfs(int r, int c, int k, string ssf, vector<string> &ans, vector<vector<char>> &board,
    vector<vector<int>> &visited){
        
        int n = board.size(), m = board[0].size();
        if(k == ssf.size()){
            auto it2 = find(ans.begin(), ans.end(), ssf);
            if(it2 == ans.end())
                ans.push_back(ssf);
            return;
        }
        
        visited[r][c] = 1;
        vector<vector<int>> pos{{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
        
        for(int i=0; i<8; i++){
            int nr = r + pos[i][0];
            int nc = c + pos[i][1];
            
            if(nr>=0 and nc>=0 and nr<n and nc<m and !visited[nr][nc] and board[nr][nc] == ssf[k]){
               dfs(nr, nc, k+1, ssf, ans, board, visited);
            }
        }
        visited[r][c] = 0;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string> ans;
	    int n = board.size(), m = board[0].size();
	    vector<vector<int>> visited(n, vector<int>(m,0));
	    
	    for(auto x : dictionary){
	        char ch = x[0];
	        for(int i=0; i<n; i++){
    	        for(int j=0; j<m; j++){
    	            if(board[i][j] == ch){
    	                int k = 1;
    	                dfs(i, j, k, x, ans, board, visited);
    	            }
    	        }
    	    }
	    }

	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends