class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;  // To store character frequencies
        int c = 0;  // To count the length of the longest palindrome
        
        // Count frequencies of each character
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                c += 2;  // If we find a pair, add 2 to the count
                map[s[i]] = 0;  // Reset the count for that character
                //cout << s[i] << " " << c << "\n";
            } else {
                map[s[i]]++;
            }
        }
        
        // Check if there's any character with a frequency of 1
        for (auto& it : map) {
            if (it.second == 1) {
                c++;  // Add one to the count for the center of the palindrome
                break;
            }
        }
        
        return c;  // Return the length of the longest palindrome
    }
};
