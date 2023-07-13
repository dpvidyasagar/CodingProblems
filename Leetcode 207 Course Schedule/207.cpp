class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
      vector<int>adj[n];
      for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);
      }
      vector<int>indgree(n,0);
      for(int i = 0;i<n;i++){
        for(auto it:adj[i]){
          indgree[it]++;
        }
      }
      queue<int>q;
      for(int i = 0;i<n;i++){
        if(indgree[i] == 0) q.push(i);
      }
      vector<int>v;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        v.push_back(node);
        for(auto it:adj[node]){
          if(--indgree[it] == 0) q.push(it);
        }
      }
      return v.size() == n;
    }
};