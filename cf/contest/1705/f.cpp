#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
char bs[200200];

int query() {
    for(int i=0; i<n; i++) { cout << bs[i]; }
    cout << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}

void solve(cint T) {
    vector<int> id;
    cin >> n;
    for(int i=0; i<n; i++) { bs[i] = 'T'; id.push_back(i); }
    random_shuffle(id.begin(), id.end());
    int lst = query();
    char st[2] = {'T', 'F'};
    if(lst < n/2) {
        for(int i=0; i<n; i++) { bs[i] = 'F'; }
        lst = query();
        swap(st[0], st[1]);
    }
    if(lst == n) { return; }
    for(int i=0; i<n; i++) {
        bs[id[i]] = st[1];
        int now = query();
        if(now == n) { return; }
        if(now < lst) { bs[id[i]] = st[0]; }
        ++lst;
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}