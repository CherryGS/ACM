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

int t, n, m;
char s[1001000];

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> s;
        int x = 0, y = 0;
        int r[4] = {0, 0, 0, 0}; // 0min_x 1max_x 2min_y 3max_y
        int le = strlen(s);
        for(int i=0; i<le; i++) {
            if(s[i] == 'L') {
                if(r[1]-(x-1) >= m) break;
                r[0] = min(r[0], x-1);
                x -= 1;
            }
            else if(s[i] == 'R') {
                if(x+1-r[0] >= m) break;
                r[1] = max(r[1], x+1);
                x += 1;
            }
            else if(s[i] == 'D') {
                if(r[3]-(y-1) >= n) break;
                r[2] = min(r[2], y-1);
                y -= 1;
            }
            else if(s[i] == 'U'){
                if((y+1)-r[2] >= n) break; 
                r[3] = max(r[3], y+1);
                y += 1;
            }
        }
        cout << r[3]+1 << ' ' << -r[0]+1 << endl;
    }
    return 0;
}