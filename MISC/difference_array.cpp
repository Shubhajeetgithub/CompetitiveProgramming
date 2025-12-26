/*
https://codeforces.com/problemset/problem/1323/B
*/
#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; ll k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    std::vector<ll> fa(n+1, 0), fb(m+1, 0);
    int ia = 1, ib = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            fa[ia++]++;
        }
        else ia = 1;
    }
    for (int i = 0; i < m; i++) {
        if (b[i] == 1) fb[ib++]++;
        else ib = 1;
    }
    for (int i = n-1; i >= 1; i--) fa[i] += fa[i+1];
    for (int i = m-1; i >= 1; i--) fb[i] += fb[i+1];
    ll ways = 0;
    for (ll i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            ll j = k / i;
            if (i <= n && j <= m) ways += fa[i] * fb[j];
            if (i != j && j <= n && i <= m) ways += fa[j] * fb[i];
        }
    }
    std::cout << ways << std::endl;
    return 0;
}