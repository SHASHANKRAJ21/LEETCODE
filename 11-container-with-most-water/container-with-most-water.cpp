class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        long long maxWater = 0;

        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            long long currentWater = 1LL * width * minHeight;
            maxWater = max(maxWater, currentWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};