class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Put each number in its correct place
        for (int i = 0; i < n; i++) {
            while (
                nums[i] > 0 && nums[i] <= n &&
                nums[i] != nums[nums[i] - 1]
            ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find first index where nums[i] != i+1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all values are at right place
        return n + 1;
    }
};
