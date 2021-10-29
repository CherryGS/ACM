#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

bool vis[1001][1001];
int t1;
void cacu(cint x, cint num) {
    string s;
    int r = 1;
    int s1 = 0;
    int s2 = 0;
    for(int i=1; i<=x; i++) {
        vis[i][r] ^= 1;
        if(vis[i][r]) { s += '0'; ++s1; }
        else { s += '1'; ++r; ++s2; }
    }
    // if(s1 == 2) { cout << num-t1 << endl; t1 = num; }
    // t1 = num;
    cout << s2 << endl;
    // cout << s << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 10;
    int r = (1<<n);
    for(int i=1; i<=r; i++) {
        cacu(n, i);
    }
    return 0;
}