class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        
        // Count required characters from t
        for (char c : t) {
            need[c]++;
        }

        int required = 0;

        // Number of different characters we need
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        vector<int> window(128, 0);

        int formed = 0;
        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            // Character is required and its frequency is now satisfied
            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window
            while (formed == required) {
                int len = right - left + 1;

                // Update minimum answer
                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                // Remove s[left]
                char leftChar = s[left];
                window[leftChar]--;

                // Window is no longer satisfying this character
                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};