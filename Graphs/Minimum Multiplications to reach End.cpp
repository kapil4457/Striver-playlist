//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {

        // {node, steps}
        queue<pair<int, int>> q;
        q.push({start, 0});

        // taking 1 to 1e5 as the nodes
        vector<int> dist(1e5, 1e9);
        dist[start] = 0;

        // x > 1e5 => mod(x) < 1e5
        // eg mod(1e5 + 7) = 7

        int mod = 1e5;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                // mod to keep number in range (1, 1e5)
                int num = (it * node) % mod;
                if (steps + 1 < dist[num])
                {
                    // if better soltuion possible
                    dist[num] = steps + 1;
                    // target reached
                    if (num == end)
                        return steps + 1;
                    // dijakstra
                    q.push({num, steps + 1});
                }
            }
        }
        // imposible to get target
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends