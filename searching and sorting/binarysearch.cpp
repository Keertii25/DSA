#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
            mid=s+(e-s)/2;
        }
        else if(arr[mid]<key){
            s=mid+1;
            mid=s+(e-s)/2;
        }
    }
    return -1;

}

int main(){
    int arr[]={1,4,5,6,7,8};
    int key;
    cout<<"enter the key ";
    cin>>key;
    int s=binarysearch(arr,6,key);
    cout<<"the index of the key is "<<s;

}