/*
动态开点
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define cint const int &
#define in int &
#define ll long long

struct Node {
    int lson = 0, rson = 0;
    int lazy = 0;
    ll all = 0;
}tr[100100];

int n, m;
int sonN = 1;
int l, r, num;
int root = 1;

inline void push(Node & a, cint le, cint ri, cint mid) {
    if(!a.lson) a.lson = ++sonN;
    if(!a.rson) a.rson = ++sonN;
    tr[a.lson].lazy += a.lazy;
    tr[a.rson].lazy += a.lazy;
    tr[a.lson].all += a.lazy * (mid - le + 1);
    tr[a.rson].all += a.lazy * (ri - mid);
    a.all = tr[a.lson].all + tr[a.rson].all;
    a.lazy = 0;
}

void add(cint le, cint ri, int&cnt) {
    if(!cnt) cnt = ++sonN;
    if(le >= l && ri <= r) {
        tr[cnt].all += num * (ri-le+1);
        tr[cnt].lazy += num; 
        return;
    }
    int mid = (le+ri) >> 1;
    if(tr[cnt].lazy) push(tr[cnt], le, ri, mid);
    if(mid >= l) add(le, mid, tr[cnt].lson);
    if(mid + 1 <= r) add(mid+1, ri, tr[cnt].rson);
    tr[cnt].all = tr[tr[cnt].lson].all + tr[tr[cnt].rson].all;
}
/*
add一定要push lazy吗，为什么
    对于一个任意一个节点若它的lazy不为0，则代表子树还未更新，
    此时对子树进行push up结果显然不对。
    所以add必须push lazy 然后最后push up。
*/

ll query(cint le, cint ri, cint cnt) {
    if(!cnt) return 0;
    if(le >= l && ri <= r) return tr[cnt].all;
    int mid = (le+ri) >> 1;
    ll sum = 0;
    if(tr[cnt].lazy) push(tr[cnt], le, ri, mid);
    if(l <= mid) sum += query(le, mid, tr[cnt].lson);
    if(mid+1 <= r) sum += query(mid+1, ri, tr[cnt].rson);
    return sum; 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x, y, k, tmp;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        l = i; r = i;
        add(1, n, root);
    }
    for(int i = 1; i <= m; i++) {
        cin >> tmp;
        if(tmp == 1) {
            cin >> l >> r >> num;
            add(1, n, root);
        } else {
            cin >> l >> r;
            cout << query(1, n, root) << endl;
        }
    }
    return 0;
}