class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int common = min(m, n);

        string ans(m + n, '\0');
        int k = 0;

        for (int i = 0; i < common; i++) {
            ans[k++] = word1[i];
            ans[k++] = word2[i];
        }

        for (int i = common; i < m; i++) {
            ans[k++] = word1[i];
        }

        for (int i = common; i < n; i++) {
            ans[k++] = word2[i];
        }

        return ans;
    }
};
