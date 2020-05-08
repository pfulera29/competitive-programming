

const int N = 1e5 + 5;
int curInd, pos[N], heavy[N], sub[N], head[N];

void decompose(int root, int p, int h) {
    pos[root] = ++curInd;
    head[root] = h;

    if(heavy[root] != -1) decompose(heavy[root], root, h);
    for(auto i : adj[root]) {
        if(i == p || heavy[root] == i) continue;
        decompose(i, root, i);
    }
}

void dfs(int root, int p) {
    sub[root] = 1;
    int mex = 0, nxt = -1;
    for(auto i : adj[root]) {
        if(i == p) continue;
        dfs(i, root);
        sub[root] += sub[i];
        if(sub[i] > mex) {
            mex = sub[i]; nxt = i;
        }
    }
    heavy[root] = nxt;
}
