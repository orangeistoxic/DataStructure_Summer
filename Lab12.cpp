#include<iostream>
#include<string.h>

using namespace std;  

string findPostOrder(string preorder, string inorder){
    if(preorder.length()==0){
        return "";
    }
    else if(preorder.length()==1){
        return preorder; //Last node
    }
    char root = preorder[0];
    int rootIndex = inorder.find(root);
    string leftInOrder = inorder.substr(0,rootIndex);
    string rightInOrder = inorder.substr(rootIndex+1);
    string leftPreOrder = preorder.substr(1,rootIndex);
    string rightPreOrder = preorder.substr(rootIndex+1);

    string leftPostOrder =findPostOrder(leftPreOrder,leftInOrder);
    string rightPostOrder =findPostOrder(rightPreOrder,rightInOrder);

    return leftPostOrder+rightPostOrder+root;
}

int main(){
    string preorder,inorder;
    while(cin>>preorder>>inorder){
        
        string postoreder =findPostOrder(preorder,inorder);
        cout<<postoreder<<endl;

    }
    return 0;
}