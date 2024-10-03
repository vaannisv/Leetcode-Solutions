/*Question no- 204
Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.


Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106*/

// Solution:

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0)
            return 0;

        // each number is marked as prime at first
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        int ans = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                ans++;

                // mark every multiple of prime as false(non-prime)
                int j = 2 * i;
                for (; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        return ans;
    }
};