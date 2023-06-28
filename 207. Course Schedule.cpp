class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indeg(N,0);
        for(int i = 0 ; i < N ; i++)
        {
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < indeg.size() ; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> sol;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            sol.push_back(node);
            for(auto it : adj[node])
            {
                indeg[it]--;
                if(indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(sol.size() == N)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
