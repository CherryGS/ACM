//TAG:二分
#include <iostream>
#include <cstdio>
#include <algorithm>

int arr[1000100];
int n, m, a;
using namespace std;

int check(int st) {
    /*
        二分最终是要确定结束点的位置。
        假设有一阈值 s ,要求小于 s 的位置
        当 arr[mid] >= s 时 mid~r 全为无用数,于是 r=mid-1 
    */
    int l = 1, r = n;
    int mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(arr[mid] >= st) r = mid - 1;
        else l = mid + 1;
    }
    if(r != n) ++r;
    if(arr[r] != st) return -1;
    else return r;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(m--) {
        cin >> a;
        cout << check(a) << ' ';
    }
    return 0;
}