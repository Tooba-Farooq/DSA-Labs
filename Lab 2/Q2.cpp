#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    void printMatrix(vector<vector<int>>& res, int row, int col) {
        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
    }

    void addition(vector<vector<int>>& m1, vector<vector<int>>& m2, int row1, int col1, int row2, int col2) {
        if (row1 != row2 && col1 != col2) {
            cout << "Addition not possible" << endl;
        }
        else {
            vector<vector<int>> result(row1, vector<int>(col1)) ;

            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col1; j++) {
                    result[i][j] = m1[i][j] + m2[i][j];
                }
            }

            cout << endl << "Addition of Matrix 1 and Matrix 2" << endl;
            printMatrix(result, row1, col1); 
        }
    }

    void subtraction(vector<vector<int>>& m1, vector<vector<int>>& m2, int row1, int col1, int row2, int col2) {
        if (row1 != row2 && col1 != col2) {
            cout << "Subtraction not possible" << endl;
        }
        else {
            vector<vector<int>> result(row1, vector<int>(col1)) ;

            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col1; j++) {
                    result[i][j] = m1[i][j] - m2[i][j];
                }
            }

            cout << endl << "Subtraction of Matrix 1 and Matrix 2" << endl;
            printMatrix(result, row1, col1);
        }
    }

    void multiplication(vector<vector<int>>& m1, vector<vector<int>>& m2, int row1, int col1, int row2, int col2) {
        if (col1 != row2) {
            cout << "Multiplication is not possible" << endl;
        }
        else {
            vector<vector<int>> result(row1, vector<int>(col2));
            
            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col2; j++) {
                    for (int k = 0; k < col1; k++) {
                        result[i][j] += m1[i][k]*m2[k][j];
                    }
                }
            }

            cout << endl << "Multiplication of Matrix 1 and Matrix 2" << endl;
            printMatrix(result, row1, col2);
        }
    }

    void scalarMultiplication(vector<vector<int>>& m1, int row1, int col1, int constant) {

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                constant*m1[i][j];
            }
        }

        cout << endl << "Scalar Multiplication of Matrix with " << constant << endl;
        printMatrix(m1, row1, col1);
    }

    void transpose(vector<vector<int>>& m1, int row1, int col1) {
        vector<vector<int>> result(row1, vector<int>(col1));
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                result[i][j] = m1[j][i];
            }
        }

        cout << endl << "Transpose of Matrix 1" << endl;
        printMatrix(result, row1, col1);
    }

};
    
int main(){
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    Matrix obj;
    cout << "Matrix 1" << endl;
    obj.printMatrix(matrix1, 3, 3);
    cout << endl << "Matrix 2" << endl;
    obj.printMatrix(matrix2, 3, 3);
    obj.addition(matrix1, matrix2, 3, 3, 3, 3);
    obj.subtraction(matrix1, matrix2, 3, 3, 3, 3);
    obj.multiplication(matrix1, matrix2, 3, 3, 3, 3);
    obj.scalarMultiplication(matrix1, 3, 3, 3);
    obj.transpose(matrix1, 3, 3);

    return 0;
}
