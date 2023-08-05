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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int p1, u1;
int p2, u2;
int a1[101], b1[101];
int a2[101], b2[101];

bool solve(cint T) {
    cin >> p1 >> u1;
    for(int i=1; i<=p1; i++) { cin >> a1[i]; }
    for(int i=1; i<=u1; i++) { cin >> b1[i]; }
    cin >> p2 >> u2;
    for(int i=1; i<=p2; i++) { cin >> a2[i]; }
    for(int i=1; i<=u2; i++) { cin >> b2[i]; }
    int ans = 0;
    int l = u2;
    for(int i=u1; i>=1; i--) {
        int r = 0;
        for(int j=1; j<=u2; j++) {
            if(b2[j] == b1[i]) { r = j; break; }
        }
        if(r != 0) {
            if(r != l) { ++ans; }
            else { --l; }
        }
    }
    ans += l;
    l = 1;
    for(int i=1; i<=p1; i++) {
        int r = 0;
        for(int j=1; j<=p2; j++) {
            if(a2[j] == a1[i]) { r = j; break; }
        }
        if(r != 0) {
            if(r != l) { ++ans; }
            else { ++l; }
        }
    }
    ans += p2 - l + 1;
    cout << ans << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}