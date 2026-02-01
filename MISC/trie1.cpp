#include <iostream>
#include <vector>
#include <algorithm>

struct TrieNode {
    TrieNode* child[2];
    int leaf_cnt;
    TrieNode() {
        leaf_cnt = 0;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    // assuming 32 bit int
    void insert(const int& x) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
        }
        (cur->leaf_cnt)++;
    }

    void remove(const int& x) {
        TrieNode* cur = root;
        TrieNode* path[32];  // store path for backtracking
        int bits[32];        // store bits along the path

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) return; // x not present
            path[i] = cur;                // parent at this level
            bits[i] = bit;
            cur = cur->child[bit];
        }
        cur->leaf_cnt--;

        // cleanup if leaf_cnt == 0
        if (cur->leaf_cnt == 0) {
            for (int i = 0; i <= 31; i++) {
                TrieNode* parent = path[i];
                int bit = bits[i];
                TrieNode* node = parent->child[bit];

                // only delete if node has no children and leaf_cnt == 0
                if (node->leaf_cnt == 0 && !node->child[0] && !node->child[1]) {
                    delete node;
                    parent->child[bit] = nullptr;
                } else {
                    break; // stop if node still needed
                }
            }
        }
    }

    int maxXor(const int& x) {
        TrieNode* cur = root;
        int y = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((x >> i) & 1) ^ 1; // prefer opposite bit
            if (cur->child[bit]) {
                cur = cur->child[bit];
                if (bit) y |= (1 << i);
            }
            else if (cur->child[bit ^ 1]) {
                cur = cur->child[bit ^ 1];
                if (bit ^ 1) y |= (1 << i);
            }
            else break;
        }
        return x ^ y;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q; std::cin >> q;
    Trie* myTrie = new Trie();
    myTrie->insert(0);
    while (q--) {
        char op; int x;
        std::cin >> op >> x;
        if (op == '+') myTrie->insert(x);
        else if (op == '-') myTrie->remove(x);
        else std::cout << myTrie->maxXor(x) << '\n';
    }
    return 0;
}