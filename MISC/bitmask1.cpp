#include <bits/stdc++.h>
using ll = long long;

ll calculate_pairs(const std::string& a, const std::string& b) {
    ll sum = 0;
    int l = -1, r = -2;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] !=  b[i]) {
            ll sz = r - l + 1;
            sum += (sz * (sz + 1)) / 2;
            l = -1; r = -2;
        }
        else if (l == -1) l = r = i;
        else r = i;
    }
    if (l != -1) {
        ll sz = r - l + 1;
        sum += (sz * (sz + 1)) / 2;
    }
    return sum;
}

std::string transform_string(const std::string& a, const std::string& b, int bitmask, int size, const std::vector<std::vector<int>>& options) {
    std::string a_new = a;
    for (int i = 0; i < size; i++) {
        int bit = (bitmask >> i) & 1;
        if (bit) {
            for (int j : options[i]) a_new[j] = b[j];
        }
    }
    return a_new;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;
        std::string a, b; std::cin >> a >> b;
        std::set<char> st;
        int char_to_id[26]{};
        int size = 0;
        std::vector<std::vector<int>> options;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                char c = a[i];
                if (st.find(c) == st.end()) {
                    st.insert(c);
                    int char_val = c - 'a';
                    char_to_id[char_val] = size++;
                    options.push_back({i});
                }
                else {
                    int j = char_to_id[(int)(c - 'a')];
                    options[j].push_back(i);
                }
            }
        }
        ll max_val = LLONG_MIN;
        for (unsigned i = 0; i < (1 << size); ++i) {
            if (__builtin_popcount(i) > k) continue;
            std::string a_new = transform_string(a, b, i, size, options);
            ll cnt = calculate_pairs(a_new, b);
            max_val = std::max(max_val, cnt);
        }

        std::cout << max_val << '\n';
    }
    return 0;
}