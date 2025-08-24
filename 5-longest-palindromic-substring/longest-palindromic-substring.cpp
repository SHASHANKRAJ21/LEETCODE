
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int bestL = 0, bestR = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--; r++;
            }
            // return inclusive bounds after stepping back
            return pair<int,int>{l + 1, r - 1};
        };

        for (int i = 0; i < n; ++i) {
            // odd length
            auto [l1, r1] = expand(i, i);
            if (r1 - l1 > bestR - bestL) {
                bestL = l1; bestR = r1;
            }

            // even length
            auto [l2, r2] = expand(i, i + 1);
            if (r2 - l2 > bestR - bestL) {
                bestL = l2; bestR = r2;
            }
        }
        return s.substr(bestL, bestR - bestL + 1);
    }
};

