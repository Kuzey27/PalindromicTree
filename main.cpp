#include <bits/stdc++.h>

using namespace std;

struct PalindromicNode {
    int length = 0;
    PalindromicNode *suffix;
    PalindromicNode *children[26] = {nullptr};
};

struct PalindromicTree {
    string s;
    PalindromicNode *rootQ;
    PalindromicNode *root0;

    PalindromicNode *last_suffix;
    vector<PalindromicNode *> palindrome_suffixes;

    PalindromicTree() {
        rootQ = new PalindromicNode(-1);
        rootQ->suffix = rootQ;
        root0 = new PalindromicNode(0);
        root0->suffix = rootQ;
        last_suffix = rootQ;
    }

    explicit PalindromicTree(const string& str) : PalindromicTree() {
        s.reserve(str.size());
        for (char c: str)
            parse_letter(c);
    }

    void parse_letter(char c) {
        int ci = c - 'a';

        s.push_back(c);

        auto at = [&](int i) {
            if (i < 0)
                return '#';
            return s[i];
        };

        PalindromicNode *current = last_suffix;
        while (at(s.size() - current->length - 2) != c)
            current = current->suffix;

        if (current->children[ci] == nullptr) {
            auto *new_palindrome = new PalindromicNode(current->length + 2);

            if (new_palindrome->length == 1)
                new_palindrome->suffix = root0;
            else {
                auto *current_suffix = current->suffix;
                while (at(s.size() - current_suffix->length - 2) != c)
                    current_suffix = current_suffix->suffix;

                new_palindrome->suffix = current_suffix->children[ci];
            }

            current->children[ci] = new_palindrome;
        }

        last_suffix = current->children[ci];
        palindrome_suffixes.push_back(last_suffix);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    PalindromicTree p_tree(s);

    for (int i = 0; i < s.size(); i ++) {
        int len = p_tree.palindrome_suffixes[i]->length;
        cout << i + 1 << " : " << string_view(s).substr(i + 1 - len, len) << endl;
    }

    return 0;
}
