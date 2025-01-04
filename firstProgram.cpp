#include<iostream>
using namespace std;

int binarySearch(int n, int arr[], int element) {
    int start = 0, end = n - 1;
    while(start <= end ){
        int mid = start + (end - start) / 2;
        if(arr[mid] == element) {
            return mid;
        }
        else if (arr[mid] > element) {
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout <<"This is binary Search Program";

    
    int element = 4;
    int arr[] = {1,2,3,4,5,6,7,8,9,12};
    cout << binarySearch(10,arr,element);
    

}