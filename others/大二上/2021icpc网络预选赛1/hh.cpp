#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL q[20000], p[30000];
map<LL, LL> revq, revp;
vector<LL> app[20000];
LL cnt[20000];
struct edge{
    LL v;
    edge *nxt;
    edge (LL al, edge *be){
        v = al, nxt = be;
    };
}*head[20000];
int main()
{
    LL n, m, ge, de, th, op;
    double al, be, kk;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (LL i = 1;i <= n; ++ i){
        cin >> q[i] >> al >> be >> kk;
        revq[q[i]] = i;
    }
    for (LL i = 1;i <= m; ++ i){
        cin >> p[i] >> op;
        revp[p[i]] = i;
        if (op == 203){
            cin >> ge >> de >> th;
            head[revq[ge]] = new edge(revq[de], head[revq[ge]]);
            head[revq[de]] = new edge(revq[ge], head[revq[de]]);
            head[revq[de]] = new edge(revq[th], head[revq[de]]);
            head[revq[th]] = new edge(revq[de], head[revq[th]]);
            head[revq[th]] = new edge(revq[ge], head[revq[th]]);
            head[revq[ge]] = new edge(revq[th], head[revq[ge]]);
            app[revq[de]].push_back(i);
            app[revq[ge]].push_back(i);
            app[revq[th]].push_back(i);
        }
        else{
            cin >> ge >> de;
            head[revq[ge]] = new edge(revq[de], head[revq[ge]]);
            head[revq[de]] = new edge(revq[ge], head[revq[de]]);
            app[revq[de]].push_back(i);
            app[revq[ge]].push_back(i);
        }
    }
    LL L;
    cin >> L;
    while (L --){
        cin >> de;
        cout << de <<"\n";
        vector<LL> tmp;
        for (edge *i = head[revq[de]];i;i = i->nxt){
            tmp.push_back(i->v);
        }
        sort(tmp.begin(), tmp.end());
        auto k = unique(tmp.begin(), tmp.end());
        for (auto i = tmp.begin(); i < k ; ++ i){
            cout << q[*i]<<",";
        }
        cout << "\n";
        sort(app[revp[de]].begin(), app[revp[de]].end());
        k = unique(app[revp[de]].begin(), app[revp[de]].end());
        for (auto i = app[revp[de]].begin(); i < k; ++ i){
            cout << p[*i]<<",";
        }
        cout << "\n";
    }
    return 0;
}
