#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

TreeNode* insertInBST(TreeNode* root,int data){
    if(root == NULL){
        root = new TreeNode(data); 
        return root;
    }  
    
    if(data > root->data){
        root->right = insertInBST(root->right,data);
    }
    else{
        root->left = insertInBST(root->left,data);
    }
    return root;
}

void createBST(TreeNode* &root){
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;

    while(data != -1){
        root = insertInBST(root,data);
        cout<<"enter data: "<<endl;
        cin>>data;
    }
}

TreeNode* BSTFromInoder(int inorder[], int start, int end){
    //base case 
    if(start > end){
        return NULL;
    }

    //1 case mera
    int mid = (start+end)/2;
    int element = inorder[mid];
    TreeNode* root = new TreeNode(element);

    //recusrion
    root->left = BSTFromInoder(inorder,start,mid-1);
    root->right = BSTFromInoder(inorder, mid+1,end);

    return root;
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7};
    int size = 7;
    int start = 0;
    int end = size-1;
    // TreeNode* root = NULL;
    // createBST(root);
    TreeNode* root = BSTFromInoder(inorder,start,end);
    levelOrder(root);
}