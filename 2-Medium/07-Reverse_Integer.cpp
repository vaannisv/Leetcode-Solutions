/*Question no.07
Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21
 

Constraints:
-231 <= x <= 231 - 1
*/

//Solution:

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x != 0) {
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
    }
}

;