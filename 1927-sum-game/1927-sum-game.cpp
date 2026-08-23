class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, right = 0, a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?')
                    a++;
                else
                    left += (num[i] - '0');
            } else {
                if (num[i] == '?')
                    b++;
                else
                    right += (num[i] - '0');
            }
        }

        if ((a + b) & 1)
            return true;

        if ((left - right) == 9 * ((b - a)/2))
            return false;

        return true;
    }
};