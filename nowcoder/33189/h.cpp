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
int s[101];
map<int, int> e;

struct node {
    int x, y, id;
    void operator = (const node&a) {
        x = a.x; y = a.y; id = a.id;
    }
    void p() {
        cout << x << ' ' << y << ' ' << id << endl;
    }
} a[100100], b[100100];

void solve(cint T) {
    cin >> n;
    int ans = inf_int, ct;
    int le = (n+1)*n*(n+1)/2 - n*(n+1)*(n*2+1)/6;
    // cout << le << endl;
    for(int i=n; i<=le; i++) {
        if(le % i == 0) {
            for(int j=1; j<=n; j++) { e[j] = n-j+1; }
            int cnt = 0;
            bool flag = true;
            for(int k=1; k<=le/i; k++) {
                int r = i;
                while(r) {
                    auto id = e.upper_bound(r);
                    if(id == e.begin()) { flag = false; break; }
                    --id;
                    int num = id->second - 1;
                    b[++cnt] = {i-r, k-1, id->first};
                    r -= id->first;
                    if(num == 0) { e.erase(id); }
                    else { e[id->first] = num; }
                }
                if(flag == false) { break; }
            }
            int mx = i*2+(le/i)*2;
            if(flag == true && ans > mx) { 
                ans = mx;
                for(int j=1; j<=cnt; j++) {
                    a[j] = b[j]; 
                    // b[j].p();
                }
                // cout << cnt << endl;
                ct = cnt;
            }
        }
    }
    // for(int i=1; i<=ct; i++) { a[i].p(); }
    sort(a+1, a+1+ct, [](const node&a, const node&b) { return a.id < b.id; } );
    cout << ans << '\n';
    for(int i=1; i<=ct; i++) {
        cout << a[i].x << ' ' << a[i].y << ' ' << a[i].x+a[i].id << ' ' << a[i].y+1 << '\n';
    }
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