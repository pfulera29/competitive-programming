/*
 only when mod is prime
 nCr mod p (for large n , r and small p ~ 10^6)
*/

void base_p(int n, int p, vector <int> &v) {                                
  while(n) {
    v.push_back(n%p);
    n /= p;
  }
}

int lucas(int n, int r, int p){                                              
  vector <int> N, R;
  base_p(n, p, N); base_p(r, p, R);
  if(R.size() > N.size()) 
    return 0LL;
  
  int size = sz(N), ans = 1;
  for(int i = 0; i < size; i++) {
    if(R[i] > N[i]) return 0LL;
    ans = mul(ans, C(N[i], R[i]));          // C is nCr function
  }
  return ans;
}
