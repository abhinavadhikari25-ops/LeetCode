class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += ' ';
                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaces = maxWidth - letters;
                int each = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = each + (extra > 0 ? 1 : 0);
                        line += string(count, ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};