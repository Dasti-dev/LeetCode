class Solution {
private:
        bool dfs(int start , vector<vector<int>> &graph , vector<int> &vis , vector<int> &pathVis , vector<int> &safe , int n)
        {
            vis[start] = 1;
            pathVis[start] = 1;
            safe[start] = 0;
            for(auto it : graph[start])
            {
                if(!vis[it])
                {
                    if(dfs(it,graph,vis,pathVis,safe,n) == true)
                    {
                        safe[start] = 0;
                        return true;
                    }
                }
                else if(pathVis[it])
                {
                    safe[start] = 0;
                    return true;
                }
            }
            safe[start] = 1;
            pathVis[start] = 0;
            return false;
        }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> sol;
        vector<int> safe(n,0);
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,safe,n);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(safe[i] == 1)
            sol.push_back(i);
        }
        return sol;
    }
};
