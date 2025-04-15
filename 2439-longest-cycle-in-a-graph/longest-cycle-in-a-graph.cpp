class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visitTime(n, -1); // Node visited at which time step
        int maxCycle = -1;
        int time = 0; // Global time counter

        for (int i = 0; i < n; ++i) {
            if (visitTime[i] != -1) continue;

            int startTime = time;
            int current = i;

            // Traverse this path
            while (current != -1 && visitTime[current] == -1) {
                visitTime[current] = time++;
                current = edges[current];
            }

            // If we found a cycle starting within this path
            if (current != -1 && visitTime[current] >= startTime) {
                maxCycle = max(maxCycle, time - visitTime[current]);
            }
        }

        return maxCycle;
    }
};
