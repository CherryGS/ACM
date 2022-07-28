如果某一个项的值和前面的项有关 , 可以考虑使用分治 FFT 优化

基本思路为分治 , 对于 $[l,r]$ , 先求出 $[l,mid]$ 的值 , 再计算 $[l,mid]$ 对 $[mid+1,r]$ 的贡献 , 再去算 $[mid+1,r]$ 内的贡献

```cpp
void cdq(int l, int r) {
    if(l == r) { return; }
    int mid = (l+r) >> 1;
    cdq(l, mid);
    solve_contri();
    for(int i=mid+1; i<=r; i++) { add_contri();  }
    cdq(mid+1, r);
}
```

注意 , 分治到 $[a,b]$ 的时候 , 应该只用 $[a,b]$ 这一段做多项式乘法 , 而不是 $[1, b]$ 

举个例子

```cpp
void cdq(int l, int r) {
    if(l == r) { return; }
    int mid = (l+r) >> 1;
    cdq(l, mid);
    NTT::solve(ans+l, a, mid+1-l, r-l+1, pre);
    for(int i=mid+1; i<=r; i++) { (ans[i] += pre[i-l]) %= mod;  }
    cdq(mid+1, r);
}
```

