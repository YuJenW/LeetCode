class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // 計算目前字元連續出現幾次
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // 寫入字元
            chars[write++] = currentChar;

            // 如果 count > 1，將 count 拆成每一位 digit 寫入
            if (count > 1) {
                int start = write;

                // 先反向寫入個位、十位、百位...
                while (count > 0) {
                    chars[write++] = '0' + (count % 10); //ascii to char
                    count /= 10;
                }

                // 因為剛剛是反向寫入，所以需要反轉回來
                reverse(chars.begin() + start, chars.begin() + write);
            }
        }

        return write;
    }
};
