#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<int>> q;
int n, m, s;

int nx[10010], he[10010], to[10010], w[10010];
int dis[10010];

void dijstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    int siz = 0;
    int la = s;
    while(siz != n) {
        for(int i=he[la]; i; i=nx[i])
            if()
    }
}

int main() {
    cin >> n >> m >> s;
    int a, b, c;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        nx[i] = he[a];
        he[a] = i;
        to[i] = b;
        w[i] = c;
    }

    return 0;
}