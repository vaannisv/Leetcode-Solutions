/*Question no.59
Spiral Matrix II

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20*/

//Solution:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> newMatrix(n, vector<int> (n));

        int row= newMatrix.size();
        int col= newMatrix[0].size();
        int num=1;
        int size= n*n;

        int startingRow= 0;
        int endingCol= row-1;
        int endingRow= col-1;
        int startingCol= 0;


        for(; num<=size; )
        {
            for(int j=startingRow; j<=endingCol && num<=size ;j++)
            {
                newMatrix[startingRow][j]=num++;
            }
            startingRow++;

            for(int j=startingRow; j<=endingRow && num<=size ;j++)
            {
                newMatrix[j][endingCol]=num++;
            }
            endingCol--;

            for(int j=endingCol; j>=startingCol && num<=size ;j--)
            {
                newMatrix[endingRow][j]=num++;
            }
            endingRow--;

            for(int j=endingRow; j>=startingRow && num<=size ;j--)
            {
                newMatrix[j][startingCol]=num++;
            }
            startingCol++;
        }
        return newMatrix;
    }
};