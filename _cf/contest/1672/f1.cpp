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
int a[200200];
int to[200200];
int b[200200];
int c[200200];
vector<int> e[200200];

bool cmpa(cint x, cint y) {
    return a[x] < a[y];
}

bool cmpb(cint x, cint y) {
    return c[x] < c[y];
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { e[i].clear(); }
    for(int i=1; i<=n; i++) { to[i] = 0; }
    for(int i=1; i<=n; i++) { b[i] = 0; }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    for(int i=1; i<=n; i++) { e[a[i]].push_back(i); }
    queue<pii> q;
    for(int i=1; i<=n; i++) {
        if(e[i].size()) {
            q.push({i, e[i].size()});
        }
    }
    int lst = 0, llst = 0;
    int fst = -1;
    while(!q.empty()) {
        while(!q.empty() && q.front().second <= 0) { q.pop(); }
        if(q.empty()) { break; }
        auto k = q.front();
        q.pop();
        if(k.first == fst || k.first == llst) {
            fst = -1;
            lst = 0;
            llst = 0;
        }
        if(fst == -1) {
            fst = k.first;
        }
        // cout << k.first << ' ' << k.second << ' ' << fst << ' ' << lst << endl;
        to[lst] = e[k.first][k.second-1];
        lst = to[lst];
        llst = k.first;
        q.push({k.first, k.second-1});
    }
    // for(int i=1; i<=n; i++) { cout << to[i] << ' '; }
    // cout << endl;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        if(b[i] == 0) {
            unordered_set<int> e;
            int r = i;
            int len = 0;
            e.insert(a[r]);
            while(true) {
                if(e.find(a[to[r]]) != e.end()) { break; }
                if(b[to[r]] == 1 || to[r] == 0) { break; }
                // cout << r << ' ' << to[r] << ' ' << a[r] << ' ' << a[to[r]] << endl;
                ++len;
                r = to[r];
                b[r] = 1;
                e.insert(a[r]);
            }
            sum += len;
            // cout << endl;
        }
    }
    vector<int> id[2];
    for(int i=1; i<=n; i++) {
        id[0].push_back(i);
        id[1].push_back(i);
    }

    sort(id[0].begin(), id[0].end(), cmpa);
    sort(id[1].begin(), id[1].end(), cmpb);
    for(int i=0; i<n; i++) { to[id[0][i]] = id[1][i]; }
    for(int i=1; i<=n; i++) { b[i] = 0; }
    int sum1 = 0;

    for(int i=1; i<=n; i++) {
        if(b[i] == 0) {
            unordered_set<int> e;
            int r = i;
            int len = 0;
            e.insert(a[r]);
            b[r] = 1;
            while(true) {
                // cout << r << ' ' << to[r] << ' ' << a[r] << ' ' << a[to[r]] << endl;
                if(e.find(a[to[r]]) != e.end()) { break; }
                if(b[to[r]] == 1) { break; }
                ++len;
                r = to[r];
                b[r] = 1;
                e.insert(a[r]);
            }
            sum1 += len;
            // cout << endl;
        }
    }
    // cout << sum << ' ' << sum1 << endl;
    if(sum <= sum1) { cout << "AC" << '\n'; }
    else { cout << "WA" << '\n'; }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}