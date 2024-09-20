/*Question nno. 917
Reverse only Letters

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.



Example 1:

Input: s = "ab-cd"
Output: "dc-ba"

Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.*/

// Solution:

class Solution
{
public:
    bool isalpha(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    string reverseOnlyLetters(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (isalpha(s[i]) && isalpha(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!isalpha(s[i]))
            {
                i++;
            }
            else if (!isalpha(s[j]))
            {
                j--;
            }
        }
        return s;
    }
};