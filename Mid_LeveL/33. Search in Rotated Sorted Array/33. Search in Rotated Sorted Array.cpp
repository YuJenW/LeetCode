class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // 左半邊是正常排序
            if (nums[left] <= nums[mid]) {
                // target 在左半邊範圍內
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } 
                // target 不在左半邊，往右半邊找
                else {
                    left = mid + 1;
                }
            } 
            // 右半邊是正常排序
            else {
                // target 在右半邊範圍內
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } 
                // target 不在右半邊，往左半邊找
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
