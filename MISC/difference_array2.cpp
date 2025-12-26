// https://codeforces.com/contest/816/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
const int N = 200000;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, q; std::cin >> n >> k >> q;
    std::vector<int> cnt_right(N+1, 0), cnt_left(N+1, 0);
    for (int i = 0; i < n; i++) {
        int l, r; std::cin >> l >> r;
        cnt_right[r]++; cnt_left[l-1]++;
    }
    std::vector<int> cnt(N+1, 0), ans(N+1, 0);
    cnt[N] = cnt_right[N] - cnt_left[N];
    for (int i = N-1; i >= 1; i--) {
        cnt_right[i] += cnt_right[i+1];
        cnt_left[i] += cnt_left[i+1];
        cnt[i] = cnt_right[i] - cnt_left[i];
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[i] >= k) ans[i] = ans[i-1] + 1;
        else ans[i] = ans[i-1];
    }
    while (q--) {
        int a, b; std::cin >> a >> b;
        std::cout << ans[b] - ans[a-1] << std::endl;
    }
    return 0;
}