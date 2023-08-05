#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
bool vis[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int a, b, c;
        for(int i=1; i<=n; i++) vis[i] = 0;
        for(int i=1; i<=m; i++) {
            cin >> a >> b >> c;
            vis[b] = 1;
        }
        int id = 0;
        for(int i=1; i<=n; i++) if(!vis[i]) id = i;
        for(int i=1; i<=n; i++) if(i != id) cout << id << ' ' << i << endl;
    }
    return 0;
}