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

int t, n;

struct node {
    int a, b;
    bool operator < (const node&aa) const {
        return a < aa.a;
    }
};

priority_queue<node, vector<node> > q;
vector<pii> ans;

int main() {
    cin >> t;
    while(t--) {
        ans.clear();
        while(!q.empty()) q.pop();
        cin >> n;
        int tmp;
        for(int i=1; i<=n; i++) {
            cin >> tmp;
            if(tmp) q.push( {tmp, i} );
        }
        while(q.size() > 1) {
            auto k1 = q.top();
            q.pop();
            auto k2 = q.top();
            q.pop();
            --k1.a; --k2.a;
            ans.push_back( {k1.b, k2.b} );
            if(k1.a) q.push(k1);
            if(k2.a) q.push(k2);
        }
        cout << ans.size() << endl;
        for(auto k: ans) {
            cout << k.first << ' ' << k.second << endl;
        }
    }
    return 0;
}