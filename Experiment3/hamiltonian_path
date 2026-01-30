#include<iostream>
#include<vector>
using namespace std;



class Solution {
  public:
    virtual bool dfs(int i, int n, vector<vector<int>> &adj, vector<bool> &visited,
    vector<int> &store)
     visited[i]=true;
        store.push_back(i);
        
        if(store.size()==n)
            return true;
            for(int x:adj[i]){
                if(!visited[x]){
          if(dfs(x, n, adj, visited, store))
                  return true;
                    
                }
            }
             visited[i] = false;
        store.pop_back();
        return false;
        
        }
 virtual bool check(int n, int m, vector<vector<int>> edges) {
      vector<vector<int>> adj(n+1);
      for(auto &v: edges){
        adj[v[0]].push_back(v[1]);    
        adj[v[1]].push_back(v[0]);    
      }
      
      for(int i=1;i<=n;i++){
          vector<bool> visited(n+1, false);
          vector<int> store;
          
          if(dfs(i, n, adj, visited, store))
            return true;
          
      }
      return false;
      
    }
 };
    
