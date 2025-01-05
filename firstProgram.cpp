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
void bubbleSort(int arr[], int n) {

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }
}
int main() {
    int n;
    cin >> n;
    

    
    
    int arr[] = {6, 9, 4, 8, 3, 1};
    bubbleSort(arr,6);
    //printArray(arr,n);
    
    
    

}