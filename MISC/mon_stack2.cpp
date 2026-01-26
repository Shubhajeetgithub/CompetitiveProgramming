#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> l(n, -1), r(n, n);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) r[i] = st.top();
        st.push(i);
    }

    std::vector<std::pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = {a[i], r[i] - l[i] - 1};
    }
    std::sort(b.begin(), b.end(), [](const auto& x, const auto& y){return x.first > y.first;});
    std::vector<int> ans(n+1);
    int i = 0;
    for (int j = 1; j <= n; j++) {
        while (b[i].second < j) i++;
        ans[j] = b[i].first;
    }
    for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
    std::cout << '\n';
    return 0;
}