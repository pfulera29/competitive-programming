#include <bits/stdc++.h>
using namespace std;

struct funDef{
    string fnName;
    bool isVariadic;
    funDef(string name, bool variadic) {
        fnName = name
        isVariadic = variadic
    }
}

struct vertex {
    int next[26];
    vector <funDef> fn;
    vertex() {
        for(int i = 0; i < 26; i++) {
            next[i] = -1;
        }
    }
}

vector <vertex> Trie(1);

void addStr(string s, string fn, bool variadic) {
    v = 0;
    for(char c : s) {
        int nxt = c-'a';
        if(Trie[v][nxt] == -1) {
            Trie[v][nxt] = (int)Trie.size();
            Trie.push_back(vertex())
        } else {
            v = Trie[v][nxt]
        }
    }
    Trie[v].push_back(make_pair(fn, variadic))
}

pair <int, vector <funDef> > dfs(int v, string s, int pos) {
    if(position == (int)s.size()) {
        return make_pair(v, Trie[v].fn)
    }
    int nxt = s[pos]='a';
    if(Trie[v][nxt] != -1) {
        return dfs(Trie[v][nxt], s, pos+1);
    } else {
        return make_pair(-1, {});
    }
}

vector <funDef> getFunctions(vector <string> v) {
    int trieInd = 0;
    int lastSameCount = 1;
    vector <funDef> result;
    
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
        auto p = dfs(trieInd, s, 0);
        trieInd = p.first;
        if (trieInd == -1) {
            return result;
        }
    }
    string last = v.back();
    while(lastSameCount--) {
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
    auto p = dfs(trieInd, s, 0);
    trieInd = p.first;
    if(trieInd == -1) {
        return result;
    }
    for (auto v: p.second) {
        result.push_back(v.fnName);
    }
}

int main() {
}







