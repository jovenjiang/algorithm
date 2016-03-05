//Given a m x n grid filled with non-negative numbers, find a path
// from top left to bottom right which minimizes the sum of all
// numbers along its path.
//
//Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int path[m][n];
        path[0][0]=grid[0][0];
        
        for(int i=1;i<m;++i)
            path[i][0]=path[i-1][0]+grid[i][0];
        for(int i=1;i<n;++i)
            path[0][i]=path[0][i-1]+grid[0][i];
            
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                path[i][j]=min(path[i-1][j],path[i][j-1])+grid[i][j];
        
        return path[m-1][n-1];
    }
};
