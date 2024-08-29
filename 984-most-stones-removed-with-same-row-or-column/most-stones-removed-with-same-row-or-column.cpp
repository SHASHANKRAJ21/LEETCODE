class Solution {
public:
    void dfs(int i, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < stones.size(); ++j) {
            // If stone j is not visited and it shares row or column with stone
            // i
            if (!visited[j] && (stones[i][0] == stones[j][0] ||
                                stones[i][1] == stones[j][1])) {
                dfs(j, stones, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int numOfComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, stones, visited);
                ++numOfComponents; // Found a new connected component
            }
        }

        // The number of stones that can be removed is total stones - number of
        // components
        return n - numOfComponents;
    }
};