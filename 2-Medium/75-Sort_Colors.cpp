/*Question no.75
Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?*/

//Solution:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int index=0;
        int i=0; 
        int j=n-1;

        while(index<=j)
        {
            //checking 0
            if(nums[index]==0)
            {
                swap(nums[i],nums[index]);
                i++;
                index++;
            }

            //checking 1
            else if(nums[index]==1)
            {
                index++;
            }

            //checking 2
            else{
                swap(nums[index],nums[j]);
                j--;
            }
        }
    }
};
