#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
ll node[3][300300<<4];
ll lz[3][300300<<4];
int r[4] = {0, 1, 2 ,3};

#define ls (loc<<1)
#define rs ((loc<<1)|1)

void push(cint loc, cint st, cint l, cint r) {
    int mid = (l+r) >> 1;
    lz[st][ls] += lz[st][loc];
    lz[st][rs] += lz[st][loc];
    lz[st][ls] %= mod;
    lz[st][rs] %= mod;
    node[st][ls] += lz[st][loc] * (mid-l+1);
    node[st][rs] += lz[st][loc] * (r-mid);
    node[st][ls] %= mod;
    node[st][rs] %= mod;
    lz[st][loc] = 0;
}

void update(cint l, cint r, cint dl, cint dr, cint loc, cll co, cint st) {
    if(dl <= l && dr >= r) {
        node[st][loc] = (node[st][loc] + co*(r-l+1)%mod)%mod;
        lz[st][loc] = (lz[st][loc] + co) % mod;
        return;
    }
    if(lz[loc]) push(loc, st, l, r);
    int mid = (l+r) >> 1;
    if(dl <= mid) update(l, mid, dl, dr, ls, co, st);
    if(dr >= mid+1) update(mid+1, r, dl, dr, rs, co, st);
    node[st][loc] = (node[st][ls] + node[st][rs]) % mod;
}

void upd(cint l, cint r, cint dl, cint dr, cint loc, cint st1, cint st2) {
    
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    return 0;
}