/* i m glad to write a note here that this technique is discovered by me in my knowledge
   because i have never seen someone using this technique to find bridges, concepts may be same but the technique is different */

const int N = 1e5 + 5;

vector <int> adj[N], G[N];
int up[N], down[N];
map <pii, int> bridge;
bool vis[N], mark[N];

void abcd(int v) {
  vis[v] = 1;
  for(auto i : adj[v]) {
    if(!vis[i]) {
      G[i].pb(v); G[v].pb(i);
      abcd(i);
    }
  }
}

void dfs(int v, int p) {
  for(auto i : G[v]) {
    if(i != p) {
      dfs(i, v);
      up[v] += up[i];
      down[v] += down[i];
    }
  }
  for(auto i : G[v]) {
    mark[i] = 1;
  }
  for(auto i : adj[v]) {
    if(!mark[i] && !vis[i]) {
      up[v]++; down[i]++;
    }
  }
  for(auto i : G[v]) {
    mark[i] = 0;
    if(i != p) {
      if(up[i] == down[i]) {
        bridge[{min(i,v),max(i,v)}] = 1;
      }    
    }
  }
  vis[v] = 1;
}
