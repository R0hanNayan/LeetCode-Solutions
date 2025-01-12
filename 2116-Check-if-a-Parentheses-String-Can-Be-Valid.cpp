class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0)
            return false;

        // Forward pass: Check for sufficient opening brackets '('
        int open = 0, flexible = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                flexible++;
            } else if (s[i] == '(') {
                open++;
            } else {
                open--;
            }
            // If closing ')' exceeds the available '(' and flexible slots, it's
            // invalid
            if (open + flexible < 0)
                return false;
        }

        // Backward pass: Check for sufficient closing brackets ')'
        int close = 0;
        flexible = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                flexible++;
            } else if (s[i] == ')') {
                close++;
            } else {
                close--;
            }

            // If opening '(' exceeds the available ')' and flexible slots, it's
            // invalid
            if (close + flexible < 0)
                return false;
        }

        return true;
    }
};
