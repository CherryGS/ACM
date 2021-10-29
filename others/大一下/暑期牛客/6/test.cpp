#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <tuple>
using namespace std;
#define LL long long
#define cint const int&
#define lson (loc<<1)
#define rson ((loc<<1)|1)
struct block_{
    LL a[4];
};
struct blocks{
    block_ a[4];
    blocks(const block_ &al,const block_ &b,const block_ &c,const block_ &d){
        a[0] = al, a[1] = b, a[2] = c, a[3] = d;
    }
};

blocks deal(LL x1, LL y1, LL x2, LL y2, LL d){
    LL x3, x4, x5 = 0, x6 = 0;
    LL y3, y4, y5 = 0, y6 = 0;
    if (x2 - x1 >= d){
        x3 = 0, x4 = d;
    }
    else{
        x3 = (x1 % d + d) % d;
        if (x3 + (x2 - x1) <= d)
            x4 = x3 + (x2 - x1);
        else{
            x4 = d;
            x5 = 0;
            x6 = (x2 % d + d) % d;
        }
    }

    if (y2 - y1 >= d){
        y3 = 0, y4 = d;
    }
    else{
        y3 = (y1 % d + d) % d;
        if (y3 + (y2 - y1) <= d)
            y4 = y3 + (y2 - y1);
        else{
            y4 = d;
            y5 = 0;
            y6 = (y2 % d + d) % d;
        }
    }
    return blocks{
        (block_){x3, y3, x4, y4},
        (block_){x3, y5, x4, y6},
        (block_){x5, y3, x6, y4},
        (block_){x5, y5, x6, y6}
        };
};
bool valid(block_ t){
    if (t.a[0] == t.a[2] || t.a[1] == t.a[3])
        return 0;
    else return 1;
}
int n, d;
int node[100100*10];
int laz[100100*10];

int cnt;

void push(cint loc) {
    laz[lson] += laz[loc];
    laz[rson] += laz[loc];
    node[lson] += laz[loc];
    node[rson] += laz[loc];
    laz[loc] = 0;
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
struct line
{
    LL x, l, r;
    LL f;
    bool operator < (const line &be) const{
        return x != be.x ? x < be.x : f > be.f;
    }
}arr[1000010];

int main (){
    int x1, x2, y1, y2, cnt = 0;
    cin >> n >> d;
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        auto ts = deal(x1, y1, x2, y2, d);
        for (int i = 0; i < 4; ++ i){
            auto t = ts.a[i];
            if (valid(t)){
                LL a1 = t.a[0]; 
                LL b1 = t.a[1]; 
                LL a2 = t.a[2]; 
                LL b2 = t.a[3]; 
                // cout << a1 <<" "<<b1<<" "<<a2<<" "<<b2<<endl;
                arr[++cnt] = (line){a1, b1, b2, 1};
                arr[++cnt] = (line){a2+1, b1, b2, -1};
            }
        }
    }
    sort(arr + 1, arr + 1 + cnt);
    for (LL i = 1;i <= cnt; ++ i){
        add(0, d-1, arr[i].l, arr[i].r-1, 1, arr[i].f);
        // cout << arr[i].x<<endl;
        if (node[1] == 0 && arr[i].x != d && (i!=cnt || arr[i].x != arr[i+1].x)){
            LL ans = query(0, d-1, 1);
            cout << "YES\n";
            cout <<  arr[i].x <<" " << ans;
            return 0;
        }

    }
    cout << "NO";
    return 0;
}