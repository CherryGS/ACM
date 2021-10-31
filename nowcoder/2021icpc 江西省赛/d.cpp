#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<ll, ll> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll t, n, d;
ll a[1000100];

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> d;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        ll st, x = -1;
        vector<pii> q;
        ll tmp = 0;
        bool flag = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] != a[i+1] || i == n) {
                q.push_back( {i-tmp, tmp+1} );
                // cout << i - tmp << ' ' << i << ' ' << a[i] << endl;
                if(i-tmp == 1) flag = 1;
                tmp = i;
            }
        }
        if(flag == 1) {
            for(int i=1; i<=n; i++) cout << a[i] << ' ';
            cout << endl;
            continue;
        }
        for(int i=0; i<q.size(); i++) {
            auto k = q[i];
            if(k.second + d*(k.first-1) <= n) {
                // cout << i << " --- " << x << ' ' << k.second << endl;
                if(x < k.second+1) {
                    x = k.second+1;
                    st = i;
                }
            }
            else if(n-d*(k.first-1) >= 1){
                if(x < n-d*(k.first-1)) {
                    x = n-d*(k.first-1);
                    st = i;
                }
            }
            // cout << k.first << ' ' << k.second << ' ' << q[st].second << endl;
        }
        vector<ll> ans;
        if(x == -1) cout << -1 << endl;
        else {
            ll val = a[q[st].second];
            ll num = q[st].first;
            ll cnt = 0;
            if(q[st].second + d*(q[st].first-1) <= n) {
                for(int i=1; i<=n; i++) {
                    if(a[i] < val || num<=0) { ans.push_back(a[i]); }
                    else if(a[i] > val){
                        if(cnt == 0) {
                            ans.push_back(val);
                            cnt = d-2;
                            --num;
                            // cout << i << " --- " << val << ' ' << num << endl;
                        }
                        else {
                            --cnt;
                        }
                        ans.push_back(a[i]);
                    }
                }
                while(num) {ans.push_back(val); num--;}
            } else {
                vector<ll> b;
                for(int i=n; i>=1; i--) {
                    if(a[i] != val) {
                        if(num > 0) {
                            if(cnt == 0) {
                                cnt = d-2;
                                b.push_back(val);
                                --num;
                            } else --cnt;
                            // cout << i << ' ' << cnt << endl;
                        }
                        b.push_back(a[i]);
                    }
                }
                while(num) {b.push_back(val); num--;}
                for(int i=b.size()-1; i>=0; i--) ans.push_back(b[i]);
            }
            for(auto i: ans) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}