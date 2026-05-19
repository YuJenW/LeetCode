class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        bool inNums1[2001] = {}; //因為題目範圍是-1000~1000
        bool inNums2[2001] = {};

        // 記錄 nums1 中出現過的數字
        for (int num : nums1) {
            inNums1[num + 1000] = true;
        }

        // 記錄 nums2 中出現過的數字
        for (int num : nums2) {
            inNums2[num + 1000] = true;
        }

        vector<vector<int>> answer(2);

        // 檢查所有可能值：-1000 ~ 1000
        for (int value = -1000; value <= 1000; value++) {
            int idx = value + 1000;

            if (inNums1[idx] && !inNums2[idx]) {
                answer[0].push_back(value);
            }

            if (inNums2[idx] && !inNums1[idx]) {
                answer[1].push_back(value);
            }
        }

        return answer;
    }
};
