#include <bits/stdc++.h>
using namespace std;

// Build longest prefix-suffix (LPS) array for KMP
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t; std::cin >> t;
    int n = t.size();
    std::vector<int> lps = buildLPS(t);
    if (lps[n-1] * 2 <= n) {
        std::cout << "NO\n";
    }
    else {
        std::cout << "YES\n";
        std::cout << t.substr(n-lps[n-1], lps[n-1]) << '\n';
    }
    return 0;
}