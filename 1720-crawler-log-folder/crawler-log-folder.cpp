class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0; // Track current directory depth

        for (const string& log : logs) {
            if (log == "../") {
                depth = max(depth - 1, 0); // Avoid going below root directory
            } else if (log != "./") {
                depth++; // Increment depth for valid directory names
            }
        }

        return depth;
    }
};
