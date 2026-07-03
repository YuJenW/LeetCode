class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int leftH = height[left];
            int rightH = height[right];

            int width = right - left;
            int area = width * min(leftH, rightH);
            ans = max(ans, area);

            if (leftH < rightH) {
                // 跳過所有高度 <= 目前 leftH 的左邊界
                while (left < right && height[left] <= leftH) {
                    left++;
                }
            } else {
                // 跳過所有高度 <= 目前 rightH 的右邊界
                while (left < right && height[right] <= rightH) {
                    right--;
                }
            }
        }

        return ans;
    }
};
