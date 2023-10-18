#include <bits/stdc++.h>
using namespace std;

struct funDef{
    string fnName;
    bool isVariadic;
    vector<string> args;
    funDef(string name, bool variadic, vector<string> a) {
        fnName = name;
        isVariadic = variadic;
        args = a;
    }
};

struct vertex {
    int next[26];
    vector <funDef> fn;
    vertex() {
        for(int i = 0; i < 26; i++) {
            next[i] = -1;
        }
    }
};

vector <vertex> Trie(1);

void addStr(string s, funDef fn) {
  int v = 0;
  for(char c : s) {
      int nxt = c-'a';
      if(Trie[v].next[nxt] == -1) {
          Trie[v].next[nxt] = (int)Trie.size();
          Trie.push_back(vertex());
      } 
      v = Trie[v].next[nxt];
  }
  Trie[v].fn.push_back(fn);
}

pair <int, vector <funDef> > dfs(int v, string s, int pos) {
    if(pos == (int)s.size()) {
      return make_pair(v, Trie[v].fn);
    }
    int nxt = s[pos]-'a';
    if(Trie[v].next[nxt] != -1) {
      return dfs(Trie[v].next[nxt], s, pos+1);
    } else {
      vector <funDef> temp;
      return make_pair(-1, temp);
    }
}

vector <string> getFunctions(vector <string> v) {
    int trieInd = 0;
    int lastSameCount = 1;
    vector <string> result;
    
    while((int)v.size() > 1) {
        int n = (int)v.size();
        if(v.back() == v[n-2]) {
            v.pop_back();
            lastSameCount += 1;
        } else {
            break;
        }
    }
    for(int i = 0; i < (int)v.size()-1; i++) {
        auto s = v[i];
        auto p = dfs(trieInd, s, 0);
        trieInd = p.first;
        if (trieInd == -1) {
            return result;
        }
    }
    string last = v.back();
    while(lastSameCount > 1) {
        lastSameCount -= 1;
        auto s = v.back();
        auto p = dfs(trieInd, s, 0);
        trieInd = p.first;
        if(trieInd == -1) {
            return result;
        }
        for (auto v: p.second) {
            if(v.isVariadic) {
                result.push_back(v.fnName);
            }
        }
    }
    auto s = v.back();
    auto p = dfs(trieInd, s, 0);
    trieInd = p.first;
    if(trieInd == -1) {
        return result;
    }
    for (auto v: p.second) {
        result.push_back(v.fnName);
    }
    return result;
}

void add_str_2(funDef fn) {
  string s = "";
  for (auto i : fn.args) {
      s += i;
  }
  addStr(s, fn);
}

void findMatches(vector <string> v) {
    auto s = getFunctions(v);
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
  funDef A("A", false, {"string", "integer", "integer"});
  funDef B("B", true, {"string", "integer"});
  funDef C("C", true, {"integer"});
  funDef D("D", true, {"integer", "integer"});
  funDef E("E", false, {"integer", "integer", "integer"});
  funDef F("F", false, {"string"});
  funDef G("G", false, {"integer"});
  add_str_2(A);
  add_str_2(B);
  add_str_2(C);
  add_str_2(D);
  add_str_2(E);
  add_str_2(F);
  add_str_2(G);
  vector <string> v = {"string"};
  findMatches(v);

  v = {"integer"};
  findMatches(v);
  v = {"integer", "integer", "integer", "integer"};
  findMatches(v);
  v = {"integer", "integer", "integer"};
  findMatches(v);
  v = {"string", "integer", "integer", "integer"};
  findMatches(v);
  v = {"string", "integer", "integer"};
  findMatches(v);
}







