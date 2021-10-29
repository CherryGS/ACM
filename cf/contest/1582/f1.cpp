#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx = 4096*2;
int r[mx+1];
int n;
int a[1001000];
struct node {
    int x, y;
    bool operator < (const node&a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};
vector<node> q;
int id[5005];
int id1[5005];

std::mt19937 rng(std::random_device{}());

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<=5000; i++) {
        id1[i] = inf_int;
        id[i] = -1;
    }
    for(int i=0; i<=mx; i++) r[i] = inf_int;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        id1[a[i]] = min(id1[a[i]], i);
        id[a[i]] = max(id[a[i]], i);
    }
    for(int i=0; i<=5000; i++) {
        if(id[i] > -1) q.push_back( {id[i], i} );
        if(id1[i] < inf_int) q.push_back( {id1[i], i} );
    }
    sort(q.begin(), q.end());
    for(int i=1; i<=n; i++) {
        if(i != id[a[i]] && i != id1[a[i]] && rng()/rng()+n<rng()) continue;
        r[a[i]] = min(r[a[i]], a[i]);
        for(int j=0; j<=mx; j++) {
            if(r[j] < inf_int && r[j] < a[i])  {
                r[j^a[i]] = min(r[j^a[i]], a[i]);
            }
        }
    }
    vector<int> ans;
    r[0] = 0;
    for(int j=0; j<=mx; j++) {
        if(r[j] < inf_int) ans.push_back(j);
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}