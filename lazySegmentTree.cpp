const int N = 2e5 + 5;
static int M;

int Data[N];

class lazySegmentTree{
  public:
    vector <int> seg;
    vector <int> lazy;
    int dummy, dummyLazy;

    lazySegmentTree(int n, int dummy, int dummyLazy) {
      M = n;
      this->dummy = dummy;
      this->dummyLazy = dummyLazy;
      seg.resize(4*n+1, dummy);
      lazy.resize(4*n+1, dummyLazy);
    }
    
    void push(int node, int s, int e) {
     
    }

    int merge(int x, int y) {
        
    }

    void build(int node = 1, int s = 1, int e = M) {
      if(s == e) {
        seg[node] = Data[s];
        return;
      }
      int m = (s + e) / 2;
      build(2*node, s, m);
      build(2*node+1, m+1, e);
      seg[node] = merge(seg[2*node], seg[2*node+1]);
    }

    void update(int l, int r, int val, int node = 1, int s = 1, int e = M) {
      push(node, s, e);
      if(s > r || e < l) return;
      if(s == e) {
        
        return;
      }
      if(s >= l && e <= r) {
       
        return;
      }
      int m = (s+e) / 2;
      update(l, r, val, 2*node, s, m);
      update(l, r, val, 2*node+1, m+1, e);
      seg[node] = merge(seg[2*node], seg[2*node+1]);
    }

    int query(int l, int r, int node = 1, int s = 1, int e = M) {
      if(l > r) return 0;
      push(node, s, e);
      if(s > r || e < l) return dummy;
      if(s >= l && e <= r) return seg[node];
      int m = (s+e) / 2;
      return merge(query(l, r, 2*node, s, m), query(l, r, 2*node+1, m+1, e));
    }
};


/*
 initialize -> lazySegmentTree s(n, dummy value, dummyLazy value)
 update = s.update(l, r, value)
 query = s.query(l, r)
 build = s.build()
*/
