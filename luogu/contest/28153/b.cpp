#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&


struct card{
    int col, lev, id;
    bool operator < (const card&a) const {
        if(col == a.col) return lev < a.lev;
        return col < a.col;
    }
}c[100010], d[100010];

ull n, m, cc, v;
int arr[100010];
ll que[100010], cnt;

int main() {
    cin >> n >> m >> cc >> v;
    for(int i = 1; i <= n; i++) {
        cin >> d[i].col >> d[i].lev;
        d[i].id = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> c[i].col >> c[i].lev;
        c[i].id = i;
        arr[i] = -1;
    }
    sort(d+1, d+1+n);
    sort(c+1, c+1+m); 
    int itrc = m, itrd = n;
    int tmp;
    while(itrd) {
        while(d[itrd].col < c[itrc].col && itrc) {itrc--; v -= cc;}
        while(d[itrd].col == c[itrc].col && itrd && itrc)
            if(d[itrd].lev >= c[itrc].lev) {
                arr[c[itrc].id] = d[itrd].id;
                v += d[itrd].lev + cc;
                itrc--;itrd--;
            } else {
                que[++cnt] = itrc;
                itrc--;
            }
        while(d[itrd].col > c[itrc].col && itrd) {
            tmp = que[cnt];
            if(cnt && d[itrd].col == c[tmp].col) {
                arr[c[tmp].id] = d[itrd].id;
                v -= (cc - d[itrd].lev);
                --cnt;
            }
            itrd--;
        }
        v -= (cnt*cc);
        cnt = 0;
    }
    v -= (itrc*cc);
    cout << v << endl;
    for(int i = 1; i <= m; i++) cout << arr[i] << endl;
    return 0;
}