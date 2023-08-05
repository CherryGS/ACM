#include <bits/stdc++.h>
using namespace std;

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
int n;
int a[101];
map<int, int> e;
int cnt;
struct node {
    int a, b, c;
};
vector<node> q;

void sol(cint l, cint r, int v) {
    while(v--) {
        for(int i=l; i<r; i++)
            swap(a[i], a[i+1]);
    }
}

int main() {
    cin >> t;
    while(t--) {
        q.clear();
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<n; i++) {
            int r = inf_int, id;
            for(int j=i; j<=n; j++) {
                if(a[j] < r) {
                    r = a[j];
                    id = j;
                }
            }
            // cout << r << "----" << id << endl;
            if(id != i) q.push_back( {i, id, id-i} );
            sol(i, id, id-i);
        }
        cout << q.size() << endl;
        for(auto k: q) {
            cout << k.a << ' ' << k.b << ' ' << k.c << endl;
        }
    }
    return 0;
}