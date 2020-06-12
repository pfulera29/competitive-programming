int table[22][N];

void build(int n){
    for(int i = 1; i <= n; i++) {
      table[0][i] = data[i];
    }
    for(int i = 1; i <= 20; i++) {
       for(int j = 1; j + (1<<i) - 1 <= n; j++) {
         table[i][j] = min(table[i-1][j], table[i-1][j+(1<<(i-1))]);
        }
    }
}

int query(int l, int r) {
    int j = (int)log2(r-l+1);
    return(min(table[j][l], table[j][r-(1<<j)+1]));
}
