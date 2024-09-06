#include <iostream>
#include <vector>
using namespace std;

int scalarProduct(vector<int>& a, vector<int>& b, int size){
    int result;

    for (int i=0; i<size; i++){
        result += a[i] * b[i];
    }

    return result;
}

void vectorAddition(vector<int>& a, vector<int>& b, int x, int y, int size){
    vector<int> result(size);

    for (int i = 0; i < size; i++){
        result[i] = x*a[i] + y*b[i];
    }

    cout << "XA + YB = (";
    for (int i=0; i<size; i++){
        cout << result[i];

        if (i != size - 1){
            cout << ", ";
        }
    }
    cout << ")" << endl;

}

int main(){
    vector<int> A = {16, -6, 7};
    vector<int> B = {4, 2, -3};
    int vectorSize = A.size();

    int X = 2;
    int Y = -5;

    cout << "A.B = " << scalarProduct(A, B, vectorSize) << endl;
    vectorAddition(A, B, X, Y, vectorSize);

    return 0;
}
