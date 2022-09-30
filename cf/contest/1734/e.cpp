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

int n;
int a[500][500];

bool check() {
    if(n > 50) { return true; }
    for(int x1=0; x1<n; ++x1) {
        for(int x2=x1+1; x2<n; ++x2) {
            for(int y1=0; y1<n; ++y1) {
                for(int y2=y1+1; y2<n; ++y2) {
                    if((a[x1][y1]+a[x2][y2]-a[x1][y2]-a[x2][y1]+n*2)%n == 0) {
                        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
                        cout << a[x1][y1] << ' ' << a[x2][y2] << ' ' << a[x1][y2] << ' ' << a[x2][y1] << endl;
                        return false; 
                    }
                }
            }
        }
    }
    return true; 
}

bool solve(cint T) {
    cin >> n;
    for(int i=0; i<n; i++) { cin >> a[i][i]; }
    bool flag = false;
    while(flag == false) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) { continue; }
                a[i][j] = rng() % n;
            }
        }
        flag = check();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << endl;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
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