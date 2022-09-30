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

int n, m, k, q;

struct node {
    int x, y, t;
    void init() { cin >> x >> y >> t; }
} a[501*501];

int sum[501][501];
bool check(int x) {
    memset(sum, 0, sizeof sum);
    for(int i=1; i<=x; i++) { sum[a[i].x][a[i].y] = 1; }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum[i][j] += sum[i-1][j];
        }
    }
    int b[501];
    for(int i=k; i<=n; i++) {
        int lst = 0;
        for(int j=1; j<=m; j++) {
            b[j] = sum[i][j] - sum[i-k][j];
            if(b[j] < k) { lst = j+1; }
            if(j-lst >= k) { return true; }
        }
    }
    return false;
}

// int sum[2][501][501];
// bool check(int x) {
//     memset(sum, 0, sizeof sum);
//     for(int i=1; i<=x; i++) { sum[0][a[i].x][a[i].y] = 1; sum[1][a[i].x][a[i].y] = 1; }
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m; j++) {
//             sum[0][i][j] += sum[0][i-1][j];
//             sum[1][i][j] += sum[1][i][j-1];
//         }
//     }
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m; j++) {
//             for(int l=k-1; l<min(i, j); l++) {
//                 if(sum[0][i][j] - sum[0][i-l-1][j] != l+1) { continue; }
//                 if(sum[0][i][j-l] - sum[0][i-l-1][j-l] != l+1) { continue; }
//                 if(sum[1][i][j] - sum[1][i][j-l-1] != l+1) { continue; }
//                 if(sum[1][i-l][j] - sum[1][i-l][j-l-1] != l+1) { continue; }
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool solve(cint T) {
    cin >> n >> m >> k >> q;
    for(int i=1; i<=q; i++) { a[i].init(); }
    sort(a+1, a+1+q, [](const node&a, const node&b) { return a.t < b.t; } );
    int l=1, r = q+1, mid;
    while(l < r) {
        mid = l + ((r-l)>>1);
        if(check(mid)) { r = mid; }
        else { l = mid + 1; }
    }
    if(r == q+1) { cout << -1 << '\n'; }
    else { cout << a[r].t << '\n'; }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}