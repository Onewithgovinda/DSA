class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        // Maximum possible digit sum is 9 * num
        if (sum > 9 * num)
            return "";

        string ans = "";

        // Put as many 9s as possible
        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        // Add the remaining digit
        if (sum > 0) {
            ans += char('0' + sum);
        }

        // Fill remaining places with zeros
        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};