int P[N], S[N];

int froot(int x) {
    return x == P[x] ? x : (P[x] = froot(P[x]));
}

void union_(int x, int y) {
    x = froot(x), y = froot(y);
    if(x == y) return;
    if (S[x] < S[y]) swap(x, y);
    P[y] = x;
    S[x] += S[y];
}
