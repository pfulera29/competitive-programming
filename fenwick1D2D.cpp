/*
  1D
*/

int fen[N];

void update(int idx, int val) {
	while(idx <= n) {
		fen[idx] += val;
		idx += idx&-idx;
	}
}

int pref(int idx) {
	int ans = 0;
	while(idx > 0) {
		ans += fen[idx];
		idx -= idx&-idx;
	}
	return ans;
}


/*
2D
*/

const int N = 1e3 + 5;
int fre[N+1][N+1];
int max_x = N, max_y = N;

void update(int x, int y, int val) {
	while(x <= max_x) {
	  int y1 = y;
	  while(y1 <= max_y) {
	  	fen[x][y1] += val;
	  	y1 += (y1 & -y1);
	  }
	  x += (x & -x);	
	}
}

int psum(int x, int y) {
    int ans = 0;
    while(x > 0) {
      int y1 = y;
      while(y1 > 0) {
      	ans += fen[x][y1];
      	y1 -= (y1 & -y1);
      }
      x -= (x & -x);	
    }
    return ans;
}
