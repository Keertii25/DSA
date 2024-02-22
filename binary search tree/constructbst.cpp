#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class binaryTreenode
{
public:
    T data;
    binaryTreenode<int> *Left;
    binaryTreenode<int> *Right;
    binaryTreenode(int data)
    {
        this->data = data;
        Left = NULL;
        Right = NULL;
    }
    ~binaryTreenode()
    {
        delete left;
        delete right;
    }
};

binaryTreenode<int>* sortedArrayToBST(int arr[],int start, int end){
    if(start>end){
        return NULL;
    }
     int mid=(start+end)/2;
    binaryTreenode<int>* root= new binaryTreenode<int>(arr[mid]);
   
   
  root->Left=  sortedArrayToBST(arr,start,mid-1);
   root->Right= sortedArrayToBST(arr,mid+1,end);
   return root;


}

void printpreorder(binaryTreenode<int>* root){
    if(root==NULL){
        return ;

    }
    cout<<root->data<<" ";
    printpreorder(root->Left);
    
    printpreorder(root->Right);
}


int main()
{
    
    int arr[]={1 ,2, 3 ,4 ,5, 6, 7};
    binaryTreenode<int> *root = sortedArrayToBST(arr,0,6);
    printpreorder(root);

   
    return 0;
}
