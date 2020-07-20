/*
 Using Pointers(efficient/less memory)
*/

const int K = 26;

struct Vertex {
 Vertex * next[K]; int cnt = 0;
 Vertex() {
  for(int i = 0; i < K; i++) {
    next[i] = NULL;
  }
 }
};

void insert(string const& s, Vertex * h) {
 Vertex * v = h;
 for(char ch : s) {
  int c = ch - 'a';
    if(v->next[c] == NULL) {
     v->next[c] = new Vertex();
    }
    v = v->next[c]; 
    v->cnt++;
 }
}

void remove(string const& s, Vertex * h) {
 Vertex * v = h;
 for(char ch : s) {
  int c = ch - 'a';
  v = v->next[c];
  v->cnt--;
 }
}


/*
 without pointers
*/ 

const int K = 26;

struct Vertex {
  int next[K], cnt = 0;
  bool leaf = false;
  Vertex() {
    fill(begin(next), end(next), -1);
  }
};

vector<Vertex> Trie(1);

void addstr(string const& s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (Trie[v].next[c] == -1) {
      Trie[v].next[c] = Trie.size();
      Trie.emplace_back();
    }
    v = Trie[v].next[c];
    Trie[v].cnt++;
  }
  Trie[v].leaf = true;
}

void remove(string const& s) {
  int v = 0
  for(char ch : s) {
    int c = ch - 'a';
    v = Trie[v].next(c);
    Trie[v].cnt--;
  }
}






