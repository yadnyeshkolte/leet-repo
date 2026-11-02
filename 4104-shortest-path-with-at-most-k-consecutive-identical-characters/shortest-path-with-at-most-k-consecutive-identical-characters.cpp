class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1){
            return 0;
        }
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        int INF = 1e9;
        vector<vector<int>> dist (n,vector<int>(k+1,INF));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            vector<int> current = pq.top();
            pq.pop();
            int d = current[0];
            int u = current[1];
            int count = current[2];

            if(d>dist[u][count]){
                continue;
            }
            if(u==n-1){
                return d;
            }
            for(auto& neigh: adj[u]){
                int v = neigh.first;
                int w = neigh.second;

                int next_count;
                if(labels[u]==labels[v]){
                    next_count = count+1;
                }
                else{
                    next_count=1;
                }
                if(next_count<=k){
                    if(d+w<dist[v][next_count]){
                        dist[v][next_count] = d+w;
                        pq.push({dist[v][next_count], v, next_count});
                    }
                }
            }
        }
        return -1;
    }
};