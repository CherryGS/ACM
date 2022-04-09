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

vector<int> to[200200];
int n;
int son[200200];

void dfs(int u, int fa) {
    for(int &v: to[u]) {
        if(v != fa) {
            ++son[u];
            dfs(v, u);
        }
    }
}

bool cmp1(cint x, cint y) {
    return son[x] > son[y];
}

void solve(cint T) {
    cin >> n;
    int tmp;
    for(int i=1; i<=n; i++) {
        to[i].clear();
        son[i] = 0;
    }
    for(int i=2; i<=n; i++) {
        cin >> tmp;
        if(i != tmp) { 
            to[tmp].push_back(i);
            to[i].push_back(tmp);
        }
    }
    dfs(1, 1);
    // for(int i=1; i<=n; i++) cout << son[i] << ' ';
    // cout << endl;
    vector<int> id;
    for(int i=1; i<=n; i++) { id.push_back(i); }
    sort(id.begin(), id.end(), cmp1);
    int sum = 0;
    int now = 0;
    int ans = 0;
    vector<int> q;
    for(int i=0; i<n; i++) {
        if(son[id[i]] == 0) { break; }
        ++sum;
        q.push_back(i);
    }
    sum += 1;

    ans += (n - now + 1) / 2;
    cout << ans << '\n';
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