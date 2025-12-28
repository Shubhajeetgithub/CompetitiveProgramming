#include <bits/stdc++.h>
using namespace std;

// Build longest prefix-suffix (LPS) array for KMP
vector<int> buildLPS(const vector<int>& pattern) {
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

// Count occurrences of hay in parent using KMP
int countOccurrences(const vector<int>& parent, const vector<int>& hay) {
    if (hay.empty() || parent.empty()) return 0;

    int n = parent.size();
    int m = hay.size();
    vector<int> lps = buildLPS(hay);

    int i = 0; // index for parent
    int j = 0; // index for hay
    int count = 0;

    while (i < n) {
        if (parent[i] == hay[j]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;        // found one occurrence
            j = lps[j - 1]; // continue searching
        } else if (i < n && parent[i] != hay[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<int> parent(n-1), hay(w-1);
    int t;
    cin >> t;
    for (int i = 0; i < n-1; i++) {
        int x; cin >> x;
        parent[i] = x - t;
        t = x;
    }
    cin >> t;
    for (int i = 0; i < w-1; i++) {
        int x; cin >> x;
        hay[i] = x - t;
        t = x;
    }
    if (w == 1) {
        cout << n << endl;
    }
    else if (w > n) {
        cout << 0 << endl;
    }
    else {
        cout << countOccurrences(parent, hay) << endl;
    }
    return 0;
}