const int mod = ;

int toPower(int a, int p){
    int res = 1;
    while (p){
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x){  return toPower(x, mod - 2); }
int add(int a, int b) { a %= mod; b %= mod; return ((a + b) % mod); }
int sub(int a, int b) { a %= mod; b %= mod; return  ((a - b + mod) % mod);}
int mul(int a, int b) { a %= mod; b %= mod; return ((a * b) % mod); }

struct NTT {
  int base, mod, maxb, root;
  vector<int> rv, roots, invr;
  NTT(int mo = 163577857)
      : base(1), mod(mo), rv({0, 1}), roots({0, 1}), invr({0, 1}) {
    assert(mod >= 3 && mod & 1);
    int tmp = mod - 1;
    maxb = 0;
    while(!(tmp & 1)) tmp >>= 1, ++maxb;
    root = 2;
    while(toPower(root, (mod - 1) >> 1) == 1) ++root;
    assert(toPower(root, mod - 1) == 1);
    root = toPower(root, (mod - 1) >> maxb);
  }
 
  void ensure_base(int nb) {
    if (nb <= base) return;
    rv.resize(1 << nb);
    roots.resize(1 << nb);
    invr.resize(1 << nb);
    for(int i = 0; i < (1 << nb); ++i)
      rv[i] = (rv[i >> 1] >> 1) + ((i & 1) << (nb - 1));
    assert(nb <= maxb);
    while (base < nb) {
      int z = toPower(root, 1 << (maxb - 1 - base)), invz = Inv(z);
      for (int i = 1 << (base - 1); i < (1 << base); ++i) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
        invr[i << 1] = invr[i];
        invr[(i << 1) + 1] = mul(invr[i], invz);
      }
      ++base;
    }
  }
  
  void ntt(vector<int> &a, int n, bool sg = 0) {
    assert((n & (n - 1)) == 0);
    for(int i = 0; i < n; ++i) {
      if (i < rv[i]) swap(a[i], a[rv[i]]);
    }
    for(int k = 1; k < n; k <<= 1) { 
      for(int i = 0; i < n; i += 2 * k) {
        for(int j = 0; j < k; ++j) {
          int z = mul(a[i + j + k], (sg ? roots[j + k] : invr[j + k]));
          a[i + j + k] = add(a[i + j], mod - z);
          a[i + j] = add(a[i + j], z);
        }
      }
    }
    int invn = Inv(n);
    if(sg)
      for(int i = 0; i < n; ++i) a[i] = mul(a[i], invn);
  }
  template <class T>
  vector<T> multiply(const vector<T> &a, const vector<T> &b) {
    int need = a.size() + b.size() - 1;
    int nb = 1;
    while((1 << nb) < need) ++nb;
    ensure_base(nb);
    int sz = 1 << nb;
    vector<int> fa(sz, 0), fb(sz, 0);
    for (int i = 0; i < sz; ++i) {
      if(i < a.size()) fa[i] = a[i];
      if(i < b.size()) fb[i] = b[i];
    }
    ntt(fa, sz);
    ntt(fb, sz);
    for(int i = 0; i < sz; ++i) fa[i] = mul(fa[i], fb[i]);
    ntt(fa, sz, 1);
    vector<T> res(need);
    for(int i = 0; i < need; ++i) res[i] = fa[i];
    return res;
  }
};
 
