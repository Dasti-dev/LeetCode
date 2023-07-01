class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        for(auto it : flights)
        {
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to,price});
        }
        q.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty())
        {
            int stops = q.front().first;
            int source = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k)
            continue;
            for(auto it : adj[source])
            {
                int adjN = it.first;
                int ecost = it.second;
                if( ecost+cost < dist[adjN] && stops <= k)
                {
                    dist[adjN] = ecost+cost;
                    q.push({stops+1,{adjN,cost+ecost}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};
