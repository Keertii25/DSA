#include <iostream>
#include <queue>
#include<climits>
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
binaryTreenode<int> *takeInputLevelOrder()
{
    int rootData;
    cout << "Enter the root data: " << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    binaryTreenode<int> *root = new binaryTreenode<int>(rootData);
    queue<binaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        binaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout << "Enter the left child data of " << front->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreenode<int> *leftChild = new binaryTreenode<int>(leftChildData);
            front->Left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cout << "Enter the right child data of " << front->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreenode<int> *rightChild = new binaryTreenode<int>(rightChildData);
            front->Right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

void printlevelorder(binaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<binaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->Left != NULL)
        {
            cout << "L" << front->Left->data;
            pendingNodes.push(front->Left);
        }

        if (front->Right != NULL)
        {
            cout << "R" << front->Right->data;
            pendingNodes.push(front->Right);
        }
        cout<<endl;
    }
}
bool isbsthelper(binaryTreenode<int>* root,int min=INT_MIN,int max=INT_MAX){
if(root==NULL){
    return true;
}
if(root->data<min || root->data>max){
    return false;
}
bool isleftok=isbsthelper(root->Left,min,root->data-1);
bool isrightok=isbsthelper(root->Right,root->data,max);
return isleftok && isrightok;
}
bool isbst(binaryTreenode<int> *root){
 return isbsthelper(root);
}

int main()
{
    binaryTreenode<int> *root = takeInputLevelOrder();
    
    printlevelorder(root);
    if(isbst(root)){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
   
    return 0;
}
// 5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
// 3 1 5 -1 2 -1 -1 -1 -1