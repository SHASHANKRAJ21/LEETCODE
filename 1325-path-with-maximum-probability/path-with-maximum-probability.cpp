class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        // Step 1: Create an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double prob = succProb[i];
            graph[a].push_back({b, prob});
            graph[b].push_back({a, prob});
        }

        // Step 2: Use a priority queue to store the maximum probability path
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        // Step 3: Process the queue
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            // If we reached the end node, return the probability
            if (node == end_node) {
                return prob;
            }

            // Traverse neighbors
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;

                // If we find a path with a higher probability, update and push
                // to the queue
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        // Step 4: If end_node is unreachable
        return 0.0;
    }
};