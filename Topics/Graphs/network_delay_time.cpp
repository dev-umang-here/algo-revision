/*
    Problem: Network Delay Time
    Approach: Dijkstra's Algorithm
    Time Complexity: O(E log V)
    Space Complexity: O(V)
    where V is the number of vertices and E is the number of edges

    Using Dijkstra's Algorithm to find the shortest path from the source node to all other nodes.
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            int src = time[0];
            int dest = time[1];
            int dist = time[2];
            adj[src].push_back({dest, dist});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        unordered_set<int> visited; // set for track visited nodes
        int delays = 0;
        while (!pq.empty()) {
            auto [dist1, node] = pq.top();
            cout<<dist1<<" "<<node<<" "<<delays<<endl;
            pq.pop();
            if(visited.count(node))continue;
            delays = max(delays, dist1);

            visited.insert(node); // this change the whole game because if you are making node visited then you are only making the choice that is available at that time
            for (auto [dest, dist2] : adj[node]) {
                if (!visited.count(dest)) {
                    pq.push({dist1 + dist2, dest});
                }
            }
        }
        if (visited.size() != n)
            return -1;
        return delays;
    }
};
