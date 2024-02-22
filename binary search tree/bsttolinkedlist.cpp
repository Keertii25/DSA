#include <iostream>
#include <queue>
using namespace std;
template <typename T>
#include <vector>
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
	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
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
        cout << endl;
    }
}



 Node<int>* constructlinkedlist(binaryTreenode<int>* root) {
    if(root==NULL){
        return NULL;
    }
    Node<int>* lh=constructlinkedlist(root->Left);
    Node<int>* rootnode= new Node<int>(root->data);
    Node<int>* rh=constructlinkedlist(root->Right);
    if(lh==NULL){
        rootnode->next=rh;
        return rootnode;
    }
   
    Node<int>* temp=lh;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=rootnode;
     rootnode->next=rh;
    return lh;

	
   
}
void printlinkedlist(Node<int>* head){
    Node<int>* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


int main()
{
    binaryTreenode<int> *root = takeInputLevelOrder();

    printlevelorder(root);
    Node<int>* head=constructlinkedlist(root);
    printlinkedlist(head);

    
    return 0;
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1