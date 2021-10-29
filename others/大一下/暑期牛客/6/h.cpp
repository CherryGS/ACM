#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
#define LL long long
#define cint const int&
#define lson (loc<<1)
#define rson ((loc<<1)|1)
LL n, d;
int node[100100*10];
int laz[100100*10];

void push(cint loc) {
    laz[lson] += laz[loc];
    laz[rson] += laz[loc];
    node[lson] += laz[loc];
    node[rson] += laz[loc];
    laz[loc] = 0;
    node[loc] = min(node[lson], node[rson]);
}

void add(cint l, cint r, cint dl, cint dr, cint loc, cint co) {
    if(l >= dl && r <= dr) {
        laz[loc] += co;
        node[loc] += co;
        return;
    }
    int mid = (l+r) >> 1;
    if(laz[loc]) push(loc);
    if(dl <= mid) add(l, mid, dl, dr, lson, co);
    if(dr >= mid+1) add(mid+1, r, dl, dr, rson, co);
    node[loc] = min(node[lson], node[rson]);
}

int query(cint l, cint r, cint loc) {
    if(l == r) return l;
    int mid = (l+r) >> 1;
    if(laz[loc]) push(loc);
    if(node[lson] == 0) return query(l, mid, lson);
    else return query(mid+1, r, rson);
}
struct line {
    LL x, l, r, f;
    bool operator < (const line &be) const{
        return x == be.x ? f > be.f : x < be.x;
    }
} arr[900010];

LL w(LL x) {
    return (x+(abs(x)/d)*d+d)%d;
}

int main (){
    LL x1, x2, y1, y2, cnt = 0;
    cin >> n >> d;
    for(int i=1; i<=n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        --x2; --y2;
        if(x2 < x1 || y2 < y1) continue;
        if(x2-x1 < d) {
            x1 = w(x1);
            x2 = w(x2);
            if(x1 <= x2) {
                if(y2-y1 < d) {
                    y1 = w(y1);
                    y2 = w(y2);
                    if(y1 <= y2) {
                        arr[++cnt] = {x1, y1, y2, 1};
                        arr[++cnt] = {x2+1, y1, y2, -1};
                    }
                    else {
                        // y1 > y2
                        arr[++cnt] = {x1, 0, y2, 1};
                        arr[++cnt] = {x1, y1, d-1, 1};
                        arr[++cnt] = {x2+1, 0, y2, -1};
                        arr[++cnt] = {x2+1, y1, d-1, -1};
                    }
                }
                else {
                    // y2-y1 > d
                    arr[++cnt] = {x1, 0, d-1, 1};
                    arr[++cnt] = {x2+1, 0, d-1, -1};
                }
            }
            else {
                // x1 > x2
                if(y2-y1 < d) {
                    y1 = w(y1);
                    y2 = w(y2);
                    if(y1 <= y2) {
                        arr[++cnt] = {0, y1, y2, 1};
                        arr[++cnt] = {x2+1, y1, y2, -1};

                        arr[++cnt] = {x1, y1, y2, 1};
                    }
                    else {
                        arr[++cnt] = {0, 0, y2, 1};
                        arr[++cnt] = {x2+1, 0, y2, -1};

                        arr[++cnt] = {0, y1, d-1, 1};
                        arr[++cnt] = {x2+1, y1, d-1, -1};

                        arr[++cnt] = {x1, 0, y2, 1};

                        arr[++cnt] = {x1, y1, d-1, 1};
                    }                                   
                }
            }
        }
        else {
            // x2 - x1 > d
            if(y2-y1 < d) {
                y1 = w(y1);
                y2 = w(y2);
                if(y1 <= y2) {
                    arr[++cnt] = {0, y1, y2, 1};
                }
                else {
                    arr[++cnt] = {0, 0, y2, 1};
                    arr[++cnt] = {0, y1, d-1, 1};
                }
            }
            else {
                arr[++cnt] = {0, 0, d-1, 1};
            }
        }
    }
    sort(arr + 1, arr + 1 + cnt);
    for (LL i = 1; i <= cnt; ++ i){
        if(arr[i].x != d) add(0, d-1, arr[i].l, arr[i].r, 1, arr[i].f);
        if (node[1] == 0 && (i == cnt || arr[i].x != arr[i+1].x)){
            LL ans = query(0, d-1, 1);
            cout << "YES\n";
            cout << arr[i].x << " " << ans << endl;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}