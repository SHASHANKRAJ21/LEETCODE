class Solution {
public:
    void reverse(vector<int>& row) {
        int left = 0;
        int right = row.size() - 1;

        while (left < right) {
            swap(row[left], row[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i]);
        }
    }
};