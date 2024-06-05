#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<int> minFreq(26, 0);

        // Update the minFreq array with the frequency of characters in the first word
        for (char c : words[0]) {
            minFreq[c - 'a']++;
        }

        // Iterate over the rest of the words
        for (int i = 1; i < words.size(); ++i) {
            std::vector<int> charFreq(26, 0);
            for (char c : words[i]) {
                charFreq[c - 'a']++;
            }

            // Update minFreq to keep the minimum frequency of each character
            for (int j = 0; j < 26; ++j) {
                minFreq[j] = std::min(minFreq[j], charFreq[j]);
            }
        }

        // Construct the result based on minFreq
        std::vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minFreq[i]; ++j) {
                result.push_back(std::string(1, 'a' + i));
            }
        }

        return result;
    }
};
