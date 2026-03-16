class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Start by assuming the first string is the common prefix
        string prefix = strs[0];

        // Compare the prefix against every other string
        for (int i = 1; i < strs.size(); i++) {
            // Shrink prefix until strs[i] starts with it
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);

                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};