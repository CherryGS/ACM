#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;

struct node { int x, y; };
vector<node> q;

int main() {
    cin >> n;
    int x, y;
    for(int i=1; i<=n; i++) {
        cin >> x >> y;
        q.push_back( {x, y} );
    }
    for(int i=1; i<=n; i++) {
        for(int j=i-1; j; j--) {
            
        }
    }
    return 0;
}