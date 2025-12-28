#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector<std::pair<int, int>> freq_char(26);
        for (int i = 0; i < 26; i++) freq_char[i] = {0, i};
        for (char c : s) {
            int id = c - 'a';
            freq_char[id].first++;
        }
        std::sort(freq_char.begin(), freq_char.end(), [](const auto& a, const auto& b){ return a.first > b.first; });

        int k_lim = std::min(26, n);
        int min_changes = INT_MAX;
        int k_opt = -1;
        for (int k = 1; k <= k_lim; k++) {
            // k * f == n
            if (n % k != 0) continue;
            int unchanged = 0;
            for (int i = 0; i < k; i++) unchanged += std::min(freq_char[i].first, n / k);
            int changes = n - unchanged;
            if (changes < min_changes) {
                min_changes = changes;
                k_opt = k;
            }
        }
        std::cout << min_changes << '\n';
        std::unordered_map<char, int> capacity, unchanged;
        for (int i = 0; i < k_opt; i++) {
            char c = freq_char[i].second + 'a';
            int fr = freq_char[i].first;
            int cap = (fr >= n/k_opt) ? 0 : n/k_opt - fr;
            if (cap > 0) capacity[c] = cap;
            unchanged[c] = std::min(fr, n/k_opt);
        }
        std::string s_new = s;
        for (char& c : s_new) {
            if (unchanged[c] > 0) {
                unchanged[c]--;
            }
            else {
                auto it = capacity.begin();
                c = (*it).first;
                (*it).second--;
                if ((*it).second == 0) capacity.erase(it);
            }
        }
        std::cout << s_new << '\n';
    }
    return 0;
}