#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int h, w;
int bcj[2][1010];
vector<int> row[1001], col[1001];

int fd(cint x, bool st) {
    return bcj[st][x] == x ? x : bcj[st][x] = fd(bcj[st][x], st);
}

int main() {
    cin >> h >> w;
    char a;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) {
            cin >> a;
            if(a == '#') {
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    for(int i=1; i<=h; i++) bcj[0][i] = i;
    for(int i=1; i<=w; i++) bcj[1][i] = i;
    bcj[1][w] = 1; bcj[0][h] = 1;
    int a1, a2;
    for(int i=1; i<=h; i++) {
        if(i == 1 || i == h) 
            for(int j=0; j<(int)row[i].size(); j++) {
                a1 = row[i][j];
                bcj[1][fd(bcj[1][a1], 1)] = fd(bcj[1][1], 1);
            }
        else 
            for(int j=0; j<(int)row[i].size()-1; j++) {
                a1 = row[i][j], a2 = row[i][j+1];
                bcj[1][fd(bcj[1][a1], 1)] = fd(bcj[1][a2], 1);
            }
    }
    for(int i=1; i<=w; i++) {
        if(i == 1 || i == w) 
            for(int j=0; j<(int)col[i].size(); j++) {
                a1 = col[i][j];
                bcj[0][fd(bcj[0][a1], 0)] = fd(bcj[0][1], 0);
            }
        else 
            for(int j=0; j<(int)col[i].size()-1; j++) {
                a1 = col[i][j], a2 = col[i][j+1];
                bcj[0][fd(bcj[0][a1], 0)] = fd(bcj[0][a2], 0);
            }
    }
    int tmp = 0;
    for(int i=1; i<=w; i++)
        if(bcj[1][i] == i) ++tmp;
    int tmp1 = 0;
    for(int i=1; i<=h; i++)
        if(bcj[0][i] == i) ++tmp1;
    cout << min(tmp1, tmp) - 1 << endl;
    return 0;
}