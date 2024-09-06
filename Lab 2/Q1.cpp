#include <iostream>
#include <vector>
using namespace std;

class BinarySearch{
public:
    void search(vector<vector<int>>& matrix, int target){
        int rows = matrix.size();
        int columns = matrix[0].size();
        int left = 0;
        int right = rows * columns -1;

        while (left <= right) {
            int midIndex = left + (right - left)/2;
            int midValue = matrix[midIndex/rows][midIndex%rows];

            if (midValue == target){
                cout << target << " is at " << midIndex/rows + 1 << " row and " << midIndex%rows + 1 << " column." << endl;
                return;
            }
            else if (midValue > target) {
                right = midIndex - 1;
            }
            else {
                left = midIndex + 1;
            }
        }
        cout << target <<" is not found in matrix." << endl;
    }
};

int main(){
    vector<vector<int>> Matrix = {{2, 5, 7},
                                  {9, 13, 16},
                                  {20, 24, 29}};

    BinarySearch obj;
    obj.search(Matrix, 16);
    obj.search(Matrix, 32);

    return 0;
}
