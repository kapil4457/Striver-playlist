
// Time Complexity : n*m*log(n*m) +  n*m*4
// Space Complexity : O(N *M)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, vector<pair<int, int>> &vec, int i0, int j0)
    {
        vis[i][j] = 1;
        vec.push_back({i - i0, j - j0});

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(grid, vis, nrow, ncol, vec, i0, j0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    vector<pair<int, int>> temp;
                    dfs(grid, vis, i, j, temp, i, j);
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends