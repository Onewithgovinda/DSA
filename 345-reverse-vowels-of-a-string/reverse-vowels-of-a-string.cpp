class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        // Store all vowels
        string vowels = "aeiouAEIOU";

        while (left < right) {

            // Move left until we find a vowel
            while (left < right && vowels.find(s[left]) == string::npos) {
                left++;
            }

            // Move right until we find a vowel
            while (left < right && vowels.find(s[right]) == string::npos) {
                right--;
            }

            // Swap the two vowels
            swap(s[left], s[right]);

            // Move both pointers
            left++;
            right--;
        }

        return s;
    }
};