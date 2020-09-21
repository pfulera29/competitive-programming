class DSU {
 public:
 	vector <int> P, S;

 	DSU(int n) {
 		P.resize(n+2);
 		S.resize(n+2);
 		for(int i = 0; i <= n; i++) {
 		  P[i] = i;
 		  S[i] = 1;
 		}
 	}
 	
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
};
