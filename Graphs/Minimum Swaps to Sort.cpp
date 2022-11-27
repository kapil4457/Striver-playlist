//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    map<int,int>ref;
	    for(int i =0 ; i < n ; i ++){
	        ref[nums[i]] = i;
	    }
	    
	    
	    vector<int>temp = nums;
	    sort(temp.begin() ,temp.end());
	    int count = 0;
	    int i =0;
	    
	    while(i<n){
	        if(temp[i]!=nums[i]){
	            int idx = ref[temp[i]];
	            
	            int t = nums[i];
	            nums[i] = nums[idx];
	            ref[nums[i]] = i;
	            nums[idx] = t;
	            ref[nums[idx]] = idx;
	            count++;
	            
	        }
	        if(nums[i] = temp[i]){
	            i++;
	        }
	    }
	    
	    
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends