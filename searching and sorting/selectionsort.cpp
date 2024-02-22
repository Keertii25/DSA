#include <iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int miniindex= i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[miniindex] > arr[j])
            {
                miniindex=j;
            }
            
        }
        swap(arr[miniindex],arr[i]);
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
    selectionsort(arr,7);
    print(arr,7);
    

    return 0;
}