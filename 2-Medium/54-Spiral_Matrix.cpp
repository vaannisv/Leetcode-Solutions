/*Question no.54
Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.


Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/

//Solution:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElements = m * n;

        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        int count = 0;
        while (count < totalElements) {

            // print starting row
            for (int i = startingRow; i <= endingCol && count < totalElements; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // print ending col
            for (int i = startingRow; i <= endingRow && count < totalElements; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // print ending row
            for (int i = endingCol; i >= startingCol && count < totalElements; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // print starting col
            for (int i = endingRow; i >= startingRow && count < totalElements; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;


        }

        return ans;
    }
};