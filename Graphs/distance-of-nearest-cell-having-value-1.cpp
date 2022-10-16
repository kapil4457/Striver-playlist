// Time Complexity : O(N*M)
// Space Coomplexity : O(N*M)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 1e5));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                    vis[nrow][ncol] == 0)
                {
                    ans[nrow][ncol] = min(ans[nrow][ncol], ans[row][col] + 1);
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends