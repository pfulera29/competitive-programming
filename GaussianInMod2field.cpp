const int MAXLOG = 34;

struct basis {
  int base[MAXLOG];

  void clear() {
   for(int i = MAXLOG - 1; i >= 0; i--) base[i] = 0;
  }

  void prepare(int val) {
    for(int i = MAXLOG - 1; i >= 0; i--) {
      if((val >> i) & 1) {
      if(!base[i]) { base[i] = val; return; }
      else val ^= base[i];
    }
  } 
 }

 int size() {
   int c = 0;
   for(int i = 0; i < MAXLOG; i++) c += (bool)(base[i]);
   return c;
 }

 int max_xor() {
  int res = 0;
  for(int i = MAXLOG - 1; i >= 0; i--)
    if(!((res >> i) & 1) && base[i]) res ^= base[i];
  return res;
 }

 bool possible(int val) {
   for(int i = MAXLOG - 1; i >= 0; i--)
    if(((val >> i) & 1) && base[i]) val ^= base[i];
   return (val == 0);
 }
};
