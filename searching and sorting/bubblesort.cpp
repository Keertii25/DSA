#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=1;i<n-1;i++){
        int miniindex =i;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
               
            }
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {1, 6, 9, 2, 4, 6, 3};
    bubblesort(arr,7);
    print(arr,7);
    

    return 0;
}