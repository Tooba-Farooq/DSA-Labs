#include<iostream>
using namespace std;

class MedianFinder{
private:
    int* nums;
    int capacity;
    int size;

public:
    MedianFinder(){
        capacity = 10;
        size = 0;
        nums = new int[capacity];
    }

    ~MedianFinder();

    void addNum(int num){
        if (size == capacity) {
            capacity *= 2;
            int* temp = new int[capacity];

            for (int i = 0; i < size; i++){
                temp[i] = nums[i];
            }

            delete[] nums;
            nums = temp;
        }
        
        int i = size - 1;
        while (i >= 0 && nums[i]>num) {
            nums[i+1] = nums[i];
            i--;
        }

        nums[i+1] = num;
        size++;
    }

    double findMedian() {
        if (size % 2 == 0) {
            return (nums[size/2 - 1] + nums[size/2]) / 2.0;
        }
        else {
            return nums[size / 2];
        }
    }
};

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << "Median " << obj->findMedian() << endl;
    obj->addNum(3);
    cout << "Median " << obj->findMedian() << endl;
    return 0;
}
