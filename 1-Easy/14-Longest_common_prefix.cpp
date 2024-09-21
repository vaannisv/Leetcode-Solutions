/*Question no. 14
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

// Solution:

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int size = strs.size();
        int i = 0;
        string ans = "";

        if (strs.empty())
            return "";

        while (i < strs[0].size() && i < strs[size - 1].size() && strs[0][i] == strs[size - 1][i])
        {
            ans.push_back(strs[0][i]);
            i++;
        }

        return ans;
    }
};