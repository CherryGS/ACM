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
char a[500500];
char s[1000100];
int sum[3][1000100];

void solve(cint T) {
    n = 0;
    cin >> n;
    if(n == 0) { return; }
    cin >> a;
    for(int i=0; i<=n*2; i++) {
        if(i & 1) { s[i] = a[i/2]; }
        else { s[i] = '#'; }
    }
    n = n * 2 + 1; 
    for(int i=1; i<n; i++) {
        sum[0][i] = sum[0][i-1] + (s[i] == 'k');
        sum[1][i] = sum[1][i-1] + (s[i] == 'f');
        sum[2][i] = sum[2][i-1] + (s[i] == 'c');
    }
    int ans[3] = {0, 0, 0};
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        // cout << i << ' ' << s[i] << ' ' << d1[i] << endl;
        for(int j=0; j<3; j++) { ans[j] += sum[j][i+d1[i]-1] - sum[j][i-1]; }
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}