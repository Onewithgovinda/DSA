
import java.util.*;

class Solution {
    public String clearDigits(String s) {

        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                if (!st.isEmpty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }

        StringBuilder ans = new StringBuilder();

        for (char ch : st) {
            ans.append(ch);
        }

        return ans.toString();
    }
}
