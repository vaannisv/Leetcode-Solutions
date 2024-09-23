/*Question no. 539
Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0


Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".*/

// Solution:

class Solution
{
public:
    int convertToMins(string &time)
    {
        int hr = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        return 60 * hr + min;
    }

    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> mins;

        // traverse each time
        for (auto time : timePoints)
        {
            mins.push_back(convertToMins(time));
        }

        sort(mins.begin(), mins.end());

        int minDiff = 1440;

        for (int i = 1; i < mins.size(); i++)
        {
            int diff = mins[i] - mins[i - 1];
            minDiff = min(minDiff, diff);
        }

        // edge case
        int circularDiff = 1440 + mins[0] - mins.back();
        minDiff = min(circularDiff, minDiff);

        return minDiff;
    }
};