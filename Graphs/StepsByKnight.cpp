//DFS won't work here

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
 	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    
	    if(x1==x2 && y1==y2){
	        return 0;
	    }
	    
	    int matrix[1001][1001];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            matrix[i][j]=0;
	        }
	    }
	    queue<pair<int,int>> q;
	    q.push({x1-1,y1-1});
	    while(!q.empty()){
	        auto node=q.front();
	        q.pop();
	        int i=node.first;
	        int j=node.second;
	        
	        if((i+1)>=0 && (i+1)<n && (j+2)>=0 &&(j+2)<n && (matrix[i+1][j+2]==0)){
	            matrix[i+1][j+2]=matrix[i][j]+1;
	            q.push({i+1,j+2});
	        }
	        if((i-2)>=0 && (i-2)<n && (j+1)>=0 && (j+1)<n && matrix[i-2][j+1]==0){
	            matrix[i-2][j+1]=matrix[i][j]+1;
	            q.push({i-2,j+1});
	        }
	        //check
	         if((i-1)>=0 && (i-1)<n && (j+2)>=0 && (j+2)<n && matrix[i-1][j+2]==0){
	            matrix[i-1][j+2]=matrix[i][j]+1;
	            q.push({i-1,j+2});
	        }
	         if((i+2)>=0 && (i+2)<n && (j+1)>=0 && (j+1)<n && matrix[i+2][j+1]==0){
	            matrix[i+2][j+1]=matrix[i][j]+1;
	            q.push({i+2,j+1});
	        }
	         if((i-1)>=0 && (i-1)<n && (j-2)>=0 && (j-2)<n && matrix[i-1][j-2]==0){
	            matrix[i-1][j-2]=matrix[i][j]+1;
	            q.push({i-1,j-2});
	        }
	         if((i+1)>=0 && (i+1)<n && (j-2)>=0 && (j-2)<n && matrix[i+1][j-2]==0){
	            matrix[i+1][j-2]=matrix[i][j]+1;
	            q.push({i+1,j-2});
	        }
	         if((i-2)>=0 && (i-2)<n && (j-1)>=0 && (j-1)<n && matrix[i-2][j-1]==0){
	            matrix[i-2][j-1]=matrix[i][j]+1;
	            q.push({i-2,j-1});
	        }
	         if((i+2)>=0 && (i+2)<n && (j-1)>=0 && (j-1)<n && matrix[i+2][j-1]==0){
	            matrix[i+2][j-1]=matrix[i][j]+1;
	            q.push({i+2,j-1});
	        }
	        
	    }
	    return matrix[x2-1][y2-1];
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends