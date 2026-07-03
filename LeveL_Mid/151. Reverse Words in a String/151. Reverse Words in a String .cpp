class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.size() - 1;

        while (i >= 0) {
            // 1. 跳過空格，直到不是空格
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            // 如果已經沒有字元，結束
            if (i < 0) {
                break;
            }

            // 2. 記錄單字結尾
            int end = i;

            // 3. 找到單字開頭
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            // 4. 如果 ans 不是空的，先加一個空格
            if (!ans.empty()) {
                ans += ' ';
            }

            // 5. 加入目前單字
            ans += s.substr(i + 1, end - i);
        }

        return ans;
    }
};
