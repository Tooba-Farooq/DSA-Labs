#include <iostream>
#include <vector>
using namespace std;

void copyArray(const vector<vector<int>>& twoD, int row, int col) {
    vector<int> oneD(row * col);
    int index = 0;

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j ++ ) {
            oneD[index] = twoD[j][i];
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        cout << oneD[i] << " ";
    }
}

int main() {
    int row, col;
    cout << "Enter number of rows of array: ";
    cin >> row;
    cout << "Enter number of columns of array: ";
    cin >> col;
    vector<vector<int>> twoD(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter " << j+1 << " element of " << i+1 << " row: ";
            cin >> twoD[i][j];
        }
    }

    cout << endl << "2D Array: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << twoD[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "After copying 2D array in 1D array in Column major order: " << endl;
    copyArray(twoD, row, col);

    return 0;
}
