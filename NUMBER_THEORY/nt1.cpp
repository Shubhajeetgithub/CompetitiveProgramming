#include <iostream>
#include <vector>
#include <algorithm>
void solve() {
    int n; std::cin >> n;
    std::vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        if (x <= n) freq[x]++;
    }
    std::vector<int> cnt(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            cnt[j] += freq[i];
        }
    }
    std::cout << *max_element(cnt.begin(), cnt.end()) << std::endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}