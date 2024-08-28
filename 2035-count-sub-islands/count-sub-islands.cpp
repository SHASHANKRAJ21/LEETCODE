class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int subIslandCount = 0;

        // Helper function for DFS traversal
        auto dfs = [&](int r, int c, auto&& dfs) -> bool {
            // If out of bounds or water, return true (base case)
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid2[r][c] == 0) {
                return true;
            }

            // If the current cell in grid2 is land and the corresponding cell
            // in grid1 is water, it's not a sub-island
            if (grid2[r][c] == 1 && grid1[r][c] == 0) {
                return false;
            }

            // Mark the current cell in grid2 as visited by setting it to 0
            // (water)
            grid2[r][c] = 0;

            // Perform DFS in all 4 directions
            bool up = dfs(r - 1, c, dfs);
            bool down = dfs(r + 1, c, dfs);
            bool left = dfs(r, c - 1, dfs);
            bool right = dfs(r, c + 1, dfs);

            // Return true only if all directions are part of a sub-island
            return up && down && left && right;
        };

        // Iterate over all cells in grid2
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we find a land cell in grid2, start a DFS
                if (grid2[r][c] == 1) {
                    // If the island starting from (r, c) is a sub-island,
                    // increment the count
                    if (dfs(r, c, dfs)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};