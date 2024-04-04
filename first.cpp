#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
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

int minValueInBST(TreeNode* root){
    if(root == NULL){
        return -1;
    }

    TreeNode* temp = root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp->data;
}
TreeNode* maxValueInBST(TreeNode* root){
    if(root == NULL){
        return NULL;
    }

    TreeNode* temp = root;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

bool findInBST(TreeNode* root, int target){
    if(root == NULL){
        return false;
    }

    //1 case mera
    if(target == root->data){
        return true;
    }

    //recurssion
    bool rightKaAnswer = false; 
    bool leftKaAnswer = false; 
    if(target > root->data){
        findInBST(root->right,target);
    }
    else{
        findInBST(root->left,target);
    }

    return rightKaAnswer || leftKaAnswer;
}

TreeNode* deleteFromBST(TreeNode* root, int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        //4 cases

        //1st case leaf node
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2nd case left side NULL and right side non NULL
        else if(root->left == NULL && root->right != NULL){
            TreeNode* ChildNode = root->right;
            delete(root);
            return ChildNode;
        }
        //3rd case left side non NULL and right side NULL
        else if(root->left != NULL && root->right == NULL){
            TreeNode* childNode = root->left;
            delete(root);
            return childNode;
        }
        //dono side he non null
        else{
            //left subtree ka maximum value
            TreeNode* maxi = maxValueInBST(root->left);
            //replacement
            root->data = maxi->data;

            //delete actual node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }

    else if(root->data > target){
        root->left = deleteFromBST(root->left,target);
    }
    else{
        root->right = deleteFromBST(root->right,target); 
    }
    return root;
}

int main(){
    TreeNode* root = NULL;
    createBST(root);
    levelOrder(root);
    int target;
    cout<<"enter the value of target: "<<endl;
    cin>>target;

    while(target != -1){
        root = deleteFromBST(root,target);
        cout<<endl<<"Printing level order after deletion: "<<endl;
        levelOrder(root);

        cout<<"enter the value of target: "<<endl;
        cin>>target;
    }


    // int target;
    // cout<<"enter the target"<<endl;
    // cin>>target;
    // while(target != -1){
    //     bool ans = findInBST(root,target);
    //     if(ans){
    //         cout<<"element found ;) "<<endl;
    //     }
    //     else{
    //         cout<<"element not found :( "<<endl;
    //     }
    //     cout<<"enter the target  "<<endl;
    //     cin>>target;
    // }
    // levelOrder(root);
    // cout<<minValueInBST(root)<<endl;
    // cout<<maxValueInBST(root)<<endl;

}