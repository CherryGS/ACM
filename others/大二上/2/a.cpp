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

char s[8008];
int n;
int st[8008];

void solve(cint T) {
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++)
        st[s[i]] += 1;
    int flag = 0;
    for(int i='a'; i<='z'; i++)
        flag += st[i]%2;
        // cout << flag << endl;
    if(flag >= 2) {
        cout << "Impossible" << endl;
        return;
    }
    int ans = 0;
    int l = 0, r = n-1;
    int des = -1;
    while(l < r) {
        // cout << l << ' ' << r << endl;
        if(s[l] == s[r]) {
            ++l; --r;
            continue;
        }
        for(int i=r-1; i>l; i--) {
            if(s[i] == s[l]) {
                ans += r-i;
                for(int j=i; j<r; j++)
                    swap(s[j], s[j+1]);
                --r;
                break;
            }
            else if(i == l+1) des = l;
        }
        ++l;
        // cout << ans << endl;
    }
    if(des != -1) ans += n/2 - des;
    cout << ans << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}