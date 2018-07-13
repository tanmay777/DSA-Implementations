#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    struct node *left,*right;
};
node *root=NULL;

node *create_new_node(int value);
node *insertElement(node *,int);
void inorderTraversal(node *);
void preorderTraversal(node *);
void postorderTraversal(node *);
node *findSmallestNode(node *);
node *findLargestNode(node *);
node *deleteElement(node *,int key);
int totalNode(node *);
int totalExternalNode(node *);
int totalInternalNode(node *);
int heightOfTree(node *);
void mirrorImage(node *);
void deleteTree(node *);
void levelOrderTraversal(node*);

int main(){
    int option,val;
    node *ptr;

    do{
        cout<<"1.Insert\n";
        cout<<"2.Inorder Traversal\n";
        cout<<"3.Preorder Traversal\n";
        cout<<"4.Postorder Traversal\n";
        cout<<"5.Smallest Element\n";
        cout<<"6.Largest Element\n";
        cout<<"7.Delete Element\n";
        cout<<"8.Total Nodes\n";
        cout<<"9.Total External Nodes\n";
        cout<<"10.Total Internal Nodes\n";
        cout<<"11.Height of Tree is\n";
        cout<<"12.Mirror Image of Tree\n";
        cout<<"13.Delete the Tree\n";
        cout<<"14.Level Traversal\n";
        cout<<"15.Top View\n";
        cout<<"0.Exit\n";
        cin>>option;

        switch(option){
            case 1:
                cout<<"Enter the element value \n";
                cin>>val;
                root=insertElement(root,val);
                break;
            case 2:
                cout<<"The element of the trees are \n";
                inorderTraversal(root);
                cout<<endl;
                break;
            case 3:
                cout<<"The elements of the tree are \n";
                preorderTraversal(root);
                cout<<endl;
                break;              
            case 4:
                cout<<"The elements of the tree are \n";
                postorderTraversal(root);
                cout<<endl;
                break;
            case 5:
                ptr=findSmallestNode(root);
                if(ptr==NULL)
                    cout<<"Tree is empty\n";
                else
                    cout<<"The smallest element is : "<<ptr->data<<endl;
                break;
            case 6:
                ptr=findLargestNode(root);
                if(ptr==NULL)
                    cout<<"Tree is empty";
                else
                    cout<<"The largest element is : "<<ptr->data<<endl;
                break;           
            case 7:
                cout<<"Enter the element which you want to delete : \n";
                cin>>val;
                root=deleteElement(root,val);
                if(root==NULL)
                    cout<<"Tree is empty";
                else
                    cout<<"Element is deleted";
                break;
            case 8: 
                cout<<"Total number of nodes are: "<<totalNode(root)<<endl;
                break;
            case 9:
                cout<<"Total External Nodes are: "<<totalExternalNode(root)<<endl;
                break;
            case 10:
                cout<<"Total Internal Nodes are: "<<totalInternalNode(root)<<endl;
                break;
            case 11:
                cout<<"Height of the tree is: "<<heightOfTree(root);
                break;
            case 12:
                cout<<"Mirror Image of Tree saved"<<endl;
                mirrorImage(root);
                break;
            case 13:
                cout<<"Tree is deleted";
                deleteTree(root);
                break;
            case 14: 
                cout<<"Level Traversal: ";
                levelOrderTraversal(root);
                break;
            case 15:
                cout<<"Top View: ";
                cout<<topView(root);
                break;
        }
    }while(option!=0);
    return 0;
}

node *createNewNode(int value){
    node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=value;
    return temp;
}

node* insertElement(node *node,int value){
    if(node==NULL){
        return createNewNode(value);
    }
    else if(value>node->data)
        node->right=insertElement(node->right,value);
    else
        node->left=insertElement(node->left,value);
    return node;
}

void inorderTraversal(node *node){
    if(node!=NULL)
    {
        inorderTraversal(node->left);
        cout<<node->data<<" ";
        inorderTraversal(node->right);
    }
}

void preorderTraversal(node *node){
    if(node!=NULL){
        cout<<node->data<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(node *node){
    if(node!=NULL)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->data<<" ";
    }
}

node *findSmallestNode(node* node)
{
    if(node==NULL||node->left==NULL)
        return node;
    else
        return findSmallestNode(node->left);
}

node *findLargestNode(node *node)
{
    if(node==NULL||node->right==NULL)
        return node;
    else
        return findLargestNode(node->right);
}

node *deleteElement(node *root,int key){
    if(root==NULL)
        return root; 
    if(key<root->data)
        root->left=deleteElement(root->left,key);
    else if(key>root->data)
        root->right=deleteElement(root->right,key);
    else {
        if(root->left==NULL) //We can check right node also first.
        {
            node *tmp=root->right;
            delete root;
            return tmp;
        }
        else if(root->right==NULL)
        {
            node *tmp=root->left;
            delete root;
            return tmp;
        }
        else
        {
            node *tmp=findSmallestNode(root->right);
            root->data=tmp->data;

            root->right=deleteElement(root->right,tmp->data);
            return root;
        }
    }
    return root;
}

int totalNode(node *root){
    if(root==NULL)
        return 0;
    else
        return(totalNode(root->left)+totalNode(root->right)+1);
}

int totalInternalNode(node *root){
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return 0;
    else
        return(totalInternalNode(root->left)+totalInternalNode(root->right)+1);
}

int totalExternalNode(node *root){
    if(root==NULL)
        return 0;
    else if(root->left==NULL&&root->right==NULL)
        return 1;
    else
        return(totalExternalNode(root->left)+totalExternalNode(root->right));
}

int heightOfTree(node *root)
{
    int leftHeight,rightHeight;
    if(root==NULL)
        return 0;
    else
    {
        leftHeight=heightOfTree(root->left);
        rightHeight=heightOfTree(root->right);
        if(leftHeight>rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
    }
}

void mirrorImage(node *root)
{
    node *ptr;
    if(root!=NULL)
    {
        mirrorImage(root->left);
        mirrorImage(root->right);
        ptr=root->left;
        root->left=root->right;
        root->right=ptr;
    }
}

void deleteTree(node *root){ //Note: Deletion is done in post order manner
    if(root!=NULL)
        {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;   
}
}

void levelOrderTraversal(node *root){
    queue<node*> q;
    if(root!=NULL)
        q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
/*
void topView(node *root,int dist,int level, auto &map){
    if(root==NULL)
        return;
    if(map.find(dist)==map.end()||level<map[dist].second)
        map[dist]={root->data,level};

    printTop(root->left,dist-1,level+1,map);
    printTop(root->right,dist+1,level+1,map);
}

void topView(node *root){
    if(root==NULL)
        return;
    unordered_map<int,pair<int,int> > map ;
    topView(root,0,0,map);
    for(auto it:map)
        cout<<it.second.first<<" ";
    
}
*/
