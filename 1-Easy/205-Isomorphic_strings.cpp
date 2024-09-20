/*Question no. 205
Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.*/

// Solution:

class Solution
{
public:
    string createMapping(string &str)
    {
        char start = 'a';
        char mapping[300] = {0};

        for (auto ch : str)
        {
            if (mapping[ch] == 0)
            {
                mapping[ch] = start;
                start++;
            }
        }

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            str[i] = mapping[ch];
        }
        return str;
    }

    bool isIsomorphic(string s, string t)
    {
        string temp1 = createMapping(s);
        string temp2 = createMapping(t);

        if (temp1 == temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};