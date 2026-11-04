class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int i = 0;
        int n = word.size();

        while (i < n) {
            if (isdigit(word[i])) {
                string num = "";

                while (i < n && isdigit(word[i])) {
                    num += word[i];
                    i++;
                }

                int pos = 0;
                while (pos < num.size() && num[pos] == '0') {
                    pos++;
                }

                num = num.substr(pos);

                if (num.empty()) {
                    num = "0";
                }

                st.insert(num);
            } 
            else {
                i++;
            }
        }

        return st.size();
    }
};