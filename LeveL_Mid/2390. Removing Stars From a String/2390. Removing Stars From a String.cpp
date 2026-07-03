class Solution {
public:
    string removeStars(string s) {
        int write = 0;

        for (char ch : s) {
            if (ch == '*') {
                write--;
            } else {
                s[write] = ch;
                write++;
            }
        }

        s.resize(write);
        return s;
    }
};
