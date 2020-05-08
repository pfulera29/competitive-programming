typedef long long int ll;
#define int long long

const int mod = 1e9 + 7;
const int mex = 1e5 + 0;
int fact[mex+5], inv[mex+5];

int toPower(int a, int p){
    int res = 1;
    while (p){
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x){ 
    return toPower(x, mod - 2); 
}

int add(int a, int b) {
    a %= mod; b %= mod;
    return ((a + b) % mod);
}

int sub(int a, int b) {
    a %= mod; b %= mod;
    return  ((a - b + mod) % mod);
}

int mul(int a, int b) {
    a %= mod; b %= mod;
    return ((a * b) % mod);
}

void initialize(){
    inv[0] = Inv(fact[0]);fact[0] = inv[0] = 1;
    
    for(int i = 1; i <= mex; i++){
        fact[i] = (ll(i) * fact[i - 1]) % mod;
        inv[i] = Inv(fact[i]);
    }
}

int C(int n, int k){
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fact[n]) * inv[k] % mod * inv[n - k] % mod;                 
}
