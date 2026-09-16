class Solution {
public:
    //The approach is simple. Start adding both strings from the last digit. Convert each character into its numeric value using ASCII. Add the two digits along with the carry from the previous step. Use `sum % 10` to get the current digit and `sum / 10` to get the carry. Continue until both strings have no digits left and there is no carry remaining. Sometimes, digits finish but a carry is still left. For example, `999 + 999 = 1998`. In this case, add the remaining carry to the result.

    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j = num2.size()-1;
        int carry=0;
        string result="";

        while (i >= 0||j >= 0||carry != 0) {
            int d1 =(i>=0)?num1[i]-'0':0;
            int d2 =(j>=0)?num2[j]-'0':0;
            int sum = d1 + d2 + carry;
            carry = sum/10;
            result += to_string(sum % 10);
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};