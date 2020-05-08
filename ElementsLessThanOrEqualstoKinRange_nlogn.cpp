/* 
   basic idea is time at which we process query with value x then only elements less than equals to x
   (greater than equals to x) should be updated in bit
   process queries in increasing or decreasing order
*/

struct query {
   int l, r, pos, val;
};

bool greater(query p1, query p2) {
   if(p1.val != p2.val) return (p1.val > p2.val);
   return p1.l > p2.l;
}

bool smaller(query p1, query p2) {
   if(p1.val != p2.val) return p1.val < p2.val;
   return p1.l > p2.l;
}

void update(int *bit, int n, int ind){
  while(ind <= n){
    bit[ind]++; ind += (ind&(-ind));
  }
}

int query(int *bit, int ind){
  int res = 0;
  while(ind){
    res += bit[ind]; (ind -= (ind&(-ind)));
  }
  return res;
}

int give(int *bit, int l, int r){
  int res = (query(bit, r)-query(bit, l-1));
  return res;
}


