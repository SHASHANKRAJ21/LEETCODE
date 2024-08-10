class Solution {
public:
    int maxArea(vector<int>& height)  {
    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int h = std::min(height[left], height[right]);
        int width = right - left;
        int water = h * width;
        maxWater = std::max(maxWater, water);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}
};