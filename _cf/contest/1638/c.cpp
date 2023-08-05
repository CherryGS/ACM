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
int a[100100];
int bcj[100100];

int fd(cint x) {
    return bcj[x] == x ? x : bcj[x] = fd(bcj[x]);
}

void merge_sort(cint l, cint r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid+1, r); 
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) bcj[i] = i;
    priority_queue<pii, vector<pii>, less<pii>> q;
    for(int i=1; i<=n; i++) {
        int r = a[i];
        while(!q.empty() && q.top().first > a[i]) {
            bcj[fd(q.top().second)] = i;
            r = max(r, q.top().first);
            q.pop();
        }
        q.push({r, i});
    }
    int ans = 0;
    for(int i=1; i<=n; i++) if(bcj[i] == i) ++ ans;
    cout << ans << endl;
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