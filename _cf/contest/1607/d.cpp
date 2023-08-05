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

int t, n;
ll a[200200];
char s[200200];

bool cmp(cint x, cint y) { return a[x] < a[y]; }

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        cin >> s;
        vector<int> q1, q2;
        for(int i=1; i<=n; i++) {
            if(s[i-1] == 'R') q1.push_back(i);
            else q2.push_back(i);
        }
        sort(q1.begin(), q1.end(), cmp);
        sort(q2.begin(), q2.end(), cmp);
        int l = 0, r = 0, sum = 0;
        bool st = 0;
        for(int i=1; i<=n; i++) {
            while(r < q2.size() && a[q2[r]] < i) { ++r; }
            if(r < q2.size()) ++ r;
            else if(l < q1.size() && a[q1[l]] <= i) ++ l;
            else {
                st = 1; break;
            }
        }
        if(st) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}