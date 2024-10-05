/*Question no. 415
Add Strings

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.


Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"


Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.*/

// Solution:

class Solution
{
public:
    string solve(string num1, int p, string num2, int q, int carry)
    {
        int digit = 0;

        // base call
        if (p < 0 && q < 0 && carry == 0)
            return "";

        // processing
        int sum = carry;
        if (p >= 0)
            sum += num1[p] - '0';
        if (q >= 0)
            sum += num2[q] - '0';

        int newCarry = sum / 10;
        digit = sum % 10;

        // recursive call
        string ans = solve(num1, p - 1, num2, q - 1, newCarry);
        ans.push_back(digit + '0');
        return ans;
    }

    string addStrings(string num1, string num2)
    {
        return solve(num1, num1.size() - 1, num2, num2.size() - 1, 0);
    }
};