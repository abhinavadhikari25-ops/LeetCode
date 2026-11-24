
class Solution {
public:
    string addStrings(string num1, string num2) {

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry != 0) {

            int a = 0;
            int b = 0;

            // Get digit from first string
            if (i >= 0) {
                a = num1[i] - '0';
                i--;
            }

            // Get digit from second string
            if (j >= 0) {
                b = num2[j] - '0';
                j--;
            }

            // Add both digits and carry
            int sum = a + b + carry;

            // Extract the digit
            int digit = sum % 10;

            // Calculate the new carry
            carry = sum / 10;

            // Convert integer digit into character
            result += (digit + '0');
        }

        // Reverse the result
        reverse(result.begin(), result.end());

        return result;
    }
};
