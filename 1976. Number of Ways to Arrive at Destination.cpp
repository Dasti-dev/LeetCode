class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long int,long long int>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long int> dist(n,LONG_MAX);
        vector<long long int> path(n,0);
        path[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long long int time = pq.top().first;
            long long int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                long long int pos = it.first;
                long long int extra = it.second;
                if(time + extra < dist[pos])
                {
                    dist[pos] = time + extra;
                    path[pos] = path[node];
                    pq.push({time+extra , pos});
                }
                else if(time + extra == dist[pos])
                {
                    path[pos] = ((path[pos] % 1000000007 + path[node]) % 1000000007) % 1000000007;
                }
            }
        }
        return path[n-1]%(1000000007);
    }
};
