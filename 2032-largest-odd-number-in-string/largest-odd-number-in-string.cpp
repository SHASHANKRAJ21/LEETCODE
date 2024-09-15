class Solution {
public:
    string largestOddNumber(string num) {
        int lastoddindex = -1;
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 != 0) {
                lastoddindex = i;
                break;
            }
        }
        if (lastoddindex != -1) {
            string result = "";
            for (int j = 0; j <= lastoddindex; j++) {
                result += num[j];
            }
            return result;
        }

        return "";
    }
};