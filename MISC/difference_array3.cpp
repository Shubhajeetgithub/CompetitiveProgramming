// https://codeforces.com/contest/177/problem/D2
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, c; std::cin >> n >> m >> c;
    std::vector<int> a(n), b(m), ans(n, 0);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    for (int i = 0; i < m-1; i++) {
        ans[i] += b[i];
        ans[n-i-1] -= b[m-i-2];
    }
    ans[m-1] += b[m-1];
    for (int i = 1; i < n; i++) {
        ans[i] += ans[i-1];
    }
    for (int i = 0; i < n; i++) {
        ans[i] = (ans[i] + a[i]) % c;
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}