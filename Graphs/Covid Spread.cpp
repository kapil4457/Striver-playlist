//First Way
//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
bool isValid(int nr,int nc,int r,int c){
    if(nr>=0 && nr<r   && nc>=0 && nc>c){
        return true;
    }
    
    return false;
}
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n = hospital.size();
        int m = hospital[0].size();
        int r=-1 ,c=-1;
        bool found = false;
        
        //Finding the point where to start
        for(int i =0 ; i < n ; i ++){
            for(int j =0 ;  j < m ; j ++){
                if(hospital[i][j]==2){
                    r= i;
                    c=j;
                    found = true;
                }
                
                if(found){
                    break;
                }
            }
            if(found){
                break;
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue< pair<pair<int,int> , int> , vector<pair<pair<int,int>, int> > , greater<pair<pair<int,int>, int>> > q;
        q.push({{r,c} , 0});
        
            vector<vector<int>>dis(n,vector<int>(m,0));
        
        while(!q.empty()){
            int currR = q.top().first.first;
            int currC = q.top().first.second;
            int currDis = q.top().second;
            q.pop();
            
            
            if(vis[currR][currC]){
                continue;
            }
            vis[currR][currC]=1;
            
            if(dis[currR][currC] == 0){
                
            dis[currR][currC]=currDis;
            }
            
            int ra[]= {0,0,1,-1};
            int ca[]= {1,-1,0,0};
            
            
            for(int i =0 ;i  <4 ; i ++){
                int nr = currR+ra[i];
                int nc = currC+ca[i];
                
                if(isValid(nr,nc,n,m) &&  !vis[nr][nc] && hospital[nr][nc] == 1){
                    
                    q.push({{nr,nc} , currDis+1});
                }
            }
        }
        
        
        int maxi = INT_MIN;
        for(int i =0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                maxi = max(maxi , dis[i][j]);
            }
        }
        
        
        
        return maxi;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends






//Second way

#include<bits/stdc++.h> 
using namespace std; 



class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
   int helpaterp(vector<vector<int>> hospital)
   {
       queue<pair<int,int>> q;
       int t=0;
       int count=0;
       int e=0;
       int n=hospital.size();
       int m=hospital[0].size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(hospital[i][j]==2)
               {q.push({i,j});
               count++;
               }
               if(hospital[i][j]==0)
               e++;
               
           }
       }
       if(count==n*m-e)
       return t;
       while(!q.empty())
       {
           int k=q.size();
           while(k--)
           {
               pair<int,int> p=q.front();
               q.pop();
               for(int i=0;i<4;i++)
               {
                   int a=x[i]+p.first;
                   int b=y[i]+p.second;
                   if(a>=0&&b>=0&&a<n&&b<m&&hospital[a][b]==1)
                   {
                       q.push({a,b});
                       hospital[a][b]=2;
                       count++;
                   }
               }
           }
           t++;
           if(count==n*m-e)
           return t;
       }
       return -1;
   }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends