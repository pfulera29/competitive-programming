// suffix link of first character is always root

struct Vertex {
  int next[K];
  int link, value = 0;
  Vertex() {
    fill(begin(next), end(next), 0);
    link = 0; value = 0;
  }
};

vector<Vertex> t(1);

void addString(string const& s, int x) {
  int v = 0;
  for(char ch : s) {
    int c = ch - 'a';
    if(t[v].next[c] == 0) {
      t[v].next[c] = t.size();
      t.emplace_back();
    }
    v = t[v].next[c];
  }
  t[v].value += x;
}

int go(int v, char ch) {
  int c = ch - 'a';
  return t[v].next[c];
} 

void prepareLinks() {
  queue <int> Q;
  for(int c = 0; c < K; c ++) {
    int y = t[0].next[c];
    if(y) Q.push(y);
  }

  while(!Q.empty()) {
    auto x = Q.front();
    Q.pop();
    for(int i = 0; i < K; i++) {
      int y = t[x].next[i];
      if(y) {
        t[y].link = t[t[x].link].next[i];
        t[y].value += t[t[y].link].value;
        Q.push(y);
      } 
      else t[x].next[i] = t[t[x].link].next[i];
    } 
  }

}
