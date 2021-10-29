#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[10010];

int main() {
    char a;
    while(scanf("%c", &a) != EOF) num[a]++;
    int mx = 0;
    for(int i = 'a'; i <= 'z'; i++) mx = max(mx, num[i]);
    cout << mx;
    return 0;
}