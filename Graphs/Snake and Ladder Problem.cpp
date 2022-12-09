//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



//We can use BFS
class Solution{

public:

    // Do BFS for each cell.

    int minThrow(int N, int arr[]){

        

        vector<int> board(31, -1); // represent each cell in vector.

        vector<bool> vis(31, false); // visited vector.

        

        // mark the positions which wiil be reached from the particular node.

        // i.e ladders and snakes.

        for(int i =0 ; i < N*2; i+=2 ){ 

            board[arr[i]] = arr[i+1];

        }

        

        // BFS.

        queue<pair<int, int>> q; // {cell number, steps taken to reach this cell}

        q.push({1, 0});

        

        vis[1] = true;

        

        while(!q.empty()){

            

            int cell = q.front().first;

            int steps = q.front().second;

            

            q.pop();

            

            if(cell == 30){ // reached the last cell.

                return steps;

            }

            

            // iterate for the next 6 cells from the current cell.

            // also check if next 6 cells can be reached or not (i < 31);

            // each cell will require 1 step to reach.

            for(int i = cell + 1 ; i <= (cell + 6) && i < 31 ; ++i ){

                

                if(vis[i] == false){ // if not visited.

                    

                    vis[i] = true;

                    

                    if(board[i] == -1){ // No ladder or snake at this cell.

                        q.push({i , steps + 1 }); 

                        

                    }

                    else ( q.push({board[i], steps + 1 }) ); // ladder or snake at this position.

                    

                }

            }

            

            

        }

        

        return 0;

    

    

        

        

    }    
    
    
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends