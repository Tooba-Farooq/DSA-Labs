#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int leftRow = 0;
        int leftCol = 0;
        int rightRow = matrix.size() - 1;
        int rightCol = matrix[0].size() - 1;
        int lastColumnIndex = matrix[0].size() - 1;

        while (leftRow <= rightRow and leftCol <= rightCol) {
            int midRow = (leftRow + rightRow) / 2;
            int midCol = (leftCol + rightCol) / 2;

            if (matrix[midRow][midCol]==target) {
                return true;
            }
            if (matrix[midRow][midCol]>target) {
                if (midCol==0) {
                    rightRow--;
                    rightCol = lastColumnIndex;
                }
                
                else {
                    rightCol--;
                }
            }
            else {
                if (leftCol==lastColumnIndex) {
                    leftRow++;
                    leftCol = 0;
                }
                else {
                    leftCol++;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> arr = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
   
    Solution obj1;
    cout<<obj1.searchMatrix(arr, 3)<<endl;
    cout<<obj1.searchMatrix(arr, 13)<<endl;
    
    return 0;
}
