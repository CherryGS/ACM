#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

struct node {
    int x,y,w;
    bool operator < (const node& a) const {
        return w < a.w;
    }
}a[100100];
int n, m;

bool book[2][10010];

bool check(cint key) {
    memset(book, 0, sizeof book);
    int num = 0;
    for(int i = 1; i <= key; i++)
        if(!book[0][a[i].x] && !book[1][a[i].y]) {
            book[0][a[i].x] = 1;
            book[1][a[i].y] = 1;
            num++;
        }
    if(num == n) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
        cin >> a[i].x >> a[i].y >> a[i].w;
    sort(a+1, a+1+n);

    int l = 1, r = m;
    int mid;
    while(l < r) {
        mid = (l+r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << a[r].w;

    return 0;
}