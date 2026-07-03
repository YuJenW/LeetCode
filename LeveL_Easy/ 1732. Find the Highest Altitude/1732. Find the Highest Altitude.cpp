class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;

        // 先計算第一個長度為 k 的視窗總和
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // 滑動視窗
        for (int right = k; right < nums.size(); right++) {
            windowSum += nums[right];       // 加入右邊的新元素
            windowSum -= nums[right - k];   // 移除左邊離開視窗的元素

            maxSum = max(maxSum, windowSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};
