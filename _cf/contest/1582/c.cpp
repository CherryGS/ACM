#include <bits/stdc++.h>
using namespace std;

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

int t, n;
char s[100100];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        int ans = 0;
        for(int i=0; i<=25; i++) {
            int pre = 0;
            vector<int> q;
            for(int j=0; j<n; j++)
                if(s[j] != 'a'+i) q.push_back(j), ++pre;
            if(q.empty()) {
                ans = n;
                break;
            }
            bool st = 1;
            int l = 0;
            int r = q.size()-1;
            while(l <= r) {
                if(s[q[l]] != s[q[r]]) {st = 0; break;}
                ++l; --r;
            }
            if(st == 1)  {
                int l = q[0], r = q[q.size()-1];
                while(l <= r) {
                    while(s[l] == 'a'+i && s[r] == s[l] && l <= r) {
                        if(l < r) pre += 2;
                        else ++pre;
                        ++l; ++r;
                    }
                    while(l<=r && s[l] == 'a'+i && s[r] != 'a'+i) ++l;
                    while(l<=r && s[l] != 'a'+i && s[r] == 'a'+i) --r;                    
                    ++l; --r;
                }
                l = q[0], r = q[q.size()-1];
                // while(l > 0 && r < n) {
                //     pre += 2;
                //     --l;
                //     ++r;
                // }
                ans = max(ans, pre);
            }
        }
        if(ans == 0) cout << -1 << endl;
        else cout << n-ans << endl;
    }
    return 0;
}
/*
1
8
rprarlap

*/