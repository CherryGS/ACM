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
const ld ept = 1e-5;

struct point {
    ld x, y;
    point() { cin >> x >> y; }
    point(ld a, ld b) { x = a; y = b; }
    void sw() { swap(x, y); }
};

struct line {
    ld a, b, c;
    line(point aa, point bb) { 
        a = bb.y-aa.y;
        b = aa.x-bb.x;
        c = -(aa.x*(bb.y-aa.y) + aa.y*(aa.x-bb.x));
    }
};

point mirr(point s, line r) { 
    ld x1 = s.x - 2*r.a*(r.a*s.x+r.b*s.y+r.c)/(r.a*r.a+r.b*r.b);
    ld y1 = s.y - 2*r.b*(r.a*s.x+r.b*s.y+r.c)/(r.a*r.a+r.b*r.b);
    return point(x1, y1);
}

point mix(line s, line r) { 
    ld x1 = (s.b*r.c - r.b*s.c) / (s.a*r.b - r.a*s.b);
    ld y1 = (s.a*r.c - r.a*s.c) / (s.b*r.a - r.b*s.a);
    return point(x1, y1);
}

int main() {
    //freopen("1.in", "r", stdin);
    cout.flags(ios::fixed); cout.precision(4);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        bool flag = 0;
        point p = point(), q = point();
        if(p.x == 0 && q.x == 0) { 
            p.sw(); q.sw();
            flag = 1;
        }
        if(p.x > q.x) swap(p, q);
        point h = point(), f = point(), e = point();
        if(flag) h.sw(), f.sw(), e.sw();
        ld le = sqrt(pow(h.x-f.x, 2) + pow(h.y-f.y, 2));
        line mir(p, q);
        // cout << mir.a << ' ' << mir.b << ' ' << mir.c << endl;
        point h1 = mirr(h, mir);
        point f1 = mirr(f, mir);
        line t = line(e, h1);
        // cout << t.a << ' ' << t.b << ' ' << t.c << endl;
        point d1 = mix(line(e, h1), mir);
        point d2 = mix(line(e, f1), mir);
        // cout << d1.x << ' ' << d1.y << ' ' << endl;

        if(d1.x > d2.x) swap(d1, d2);
        if(d1.x < p.x) {
            if(d2.x > q.x) cout << abs( (q.x-p.x) / (d2.x-d1.x) * le) << endl;
            else cout << abs((d2.x-p.x) / (d2.x-d1.x) * le)  << endl;
        }
        else {
            if(d2.x > q.x) cout << abs((q.x-d1.x) / (d2.x-d1.x) * le ) << endl;
            else {
                cout << 1 * le + ept << endl;
            }
        }
    }
    return 0;
}