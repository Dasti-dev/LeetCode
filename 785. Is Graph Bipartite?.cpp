class Solution {
public:
    bool ans=1;
    vector<int> color;
    void bfs(int i, vector<vector<int>>& graph){
        queue<int> q;
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(int j: graph[k]){
                int c=color[j];
                int c_k=color[k];
                if (c==-1){
                    color[j]=(c_k+1)&1;
                    q.push(j);
                }
                else if( c==c_k){
                    ans=0;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.assign(n, -1);
        for (int i=0; i<n; i++)
            if (color[i]==-1)
                bfs(i, graph);
        return ans;
    }
};
