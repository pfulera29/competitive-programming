const int N = 1e5 + 5;
static int M;

int Data[N];

class segmentTree{
  public:
    vector <int> seg;
    int dummy;

    segmentTree(int n, int dummy) {
      M = n;
      this->dummy = dummy;
      seg.resize(4*n+1, dummy);
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

    void update(int pos, int val, int node = 1, int s = 1, int e = M) {
      if(s == e) {
        seg[node] = val;
        seg[node] = max(0ll, seg[node]);
        return;
      }
      int m = (s+e) / 2;
      if(pos <= m) update(pos, val, 2*node, s, m);
      else update(pos, val, 2*node+1, m+1, e);
      
      seg[node] = merge(seg[2*node], seg[2*node+1]);
    }

    int query(int l, int r, int node = 1, int s = 1, int e = M) {
      if(s > r || e < l) return dummy;
      if(s >= l && e <= r) return seg[node];
      int m = (s+e) / 2;
      return merge(query(l, r, 2*node, s, m), query(l, r, 2*node+1, m+1, e));
    }
};


/*
 initialize -> segmentTree s(n, dummy value)
 update = s.update(position, value)
 query = s.query(l, r)
 build = s.build()
*/
