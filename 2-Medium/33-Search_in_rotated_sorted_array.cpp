/*Question no.33
Search in Rotated Sorted array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104*/

//Solution:

class Solution {
public:
    int findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (s == e) {
                return s;
            }

            if (mid+1 < n && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            else if (mid-1 >= 0 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            else if (arr[s] > arr[mid]) {
                e = mid - 1;
            }

            else {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }

    int binarySearch(vector<int>& arr, int s, int e, int target) {
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        int n = nums.size();
        int ans = -1;
        

        if (target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }

        else {
            ans = binarySearch(nums, pivotIndex + 1, n - 1, target);
        }

        return ans;
    }
};