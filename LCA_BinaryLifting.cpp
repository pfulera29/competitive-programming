const int N = 1e5 + 5;
const int L = 20;

vector <int> adj[N];
int in[N], out[N], lift[N][L];
int timer;

void dfs(int root, int p) {
    in[root] = ++timer;
    lift[root][0] = p;
    for(int i = 1; i < L; i++) {
       lift[root][i] = lift[lift[root][i-1]][i-1]; 
    }
    for(auto i : adj[root]) {
         if(i != p) {
             dfs(i, root);
         }
    }
    out[root] = timer;
}

bool self(int p, int c) {
    return (in[c] >= in[p] && in[c] <= out[p]);
}

int LCA(int x, int y) {
    if(self(x, y)) return x;
    if(self(y, x)) return y;

    for(int i = L-1; i >= 0; i--) {
        if(!self(lift[x][i], y)) {
             x = lift[x][i];
        } 
    }
    return lift[x][0];
}
