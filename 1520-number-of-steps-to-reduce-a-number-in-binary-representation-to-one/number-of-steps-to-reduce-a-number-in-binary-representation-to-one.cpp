class Solution {
public:
    int numSteps(string s) {
        int c = 0;  // Count of steps
        int carry = 0;  // Carry for addition operations

        // Process the string from the end to the beginning
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] == '1') {
                if (carry == 1) {
                    // If there is already a carry, turning 1 to 0 and carry forward
                    c += 1;
                } else {
                    // If no carry, this 1 bit makes the number odd, so we add 1, making it 0 and carry forward
                    c += 2;
                    carry = 1;
                }
            } else {  // s[i] == '0'
                c += 1;  // Just divide by 2 (remove the '0')
                if (carry == 1) {
                    c += 1;  // If there's a carry, turn 0 to 1 (equivalent to adding 1)
                }
            }
        }

        // Finally, account for the first bit
        if (carry == 1) {
            c += 1;  // If there's a carry left, add one step
        }

        return c;
    }
};
