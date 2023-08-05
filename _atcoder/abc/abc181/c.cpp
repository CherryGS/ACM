#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

struct Node {
    int x, y;

    // (a.x-x, a.y-y) (b.x-x, b.y-y)
    bool check(const Node&a, const Node&b) {
        return ((a.x-x)*(b.y-y)) == ((a.y-y)*(b.x-x));
    }
}st[10010];

int main() {
    int n;
    cin >> n;
    int ans=0;
    for(int i=1; i<=n; i++) cin >> st[i].x >> st[i].y;
    for(int i=1; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<=n; k++)
                ans += st[i].check(st[j], st[k]);
    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}