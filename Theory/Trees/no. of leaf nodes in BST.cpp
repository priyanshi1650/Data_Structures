using namespace std;
#include<iostream>
struct BST
{
  int val;
  struct BST *left;
  struct BST *right;
};
struct BST *check=NULL;
struct BST *new_node;
class tree
{
    int count=0;
public:
    BST* create_BST(BST *root,int num)
    {

        new_node=new BST;
        new_node->val=num;
        new_node->left=NULL;
        new_node->right=NULL;
        if(root==NULL)
            root=new_node;
        else
        {
            check=root;
            while(1)
            {
                if(check->val<num)
                {
                    if(check->right==NULL)
                    {
                        check->right=new_node;
                        //cout<<"Parent is:"<<check->val<<endl;
                        break;
                    }
                     else
                   {
                       check=check->right;
                   }
                }
                 else
               {
                   if(check->left==NULL)
                   {
                       check->left=new_node;
                      // cout<<"Parent is:"<<check->val<<endl;
                       break;
                   }
                   else
                   {
                       check=check->left;
                   }
               }
            }
        }
        return root;
    }
    int count_(BST *root)
    {

         if(root==NULL)
           return 0;
       /* if(root!=NULL)       to find total nodes
            count=count+1;*/
        if((root->left==NULL && root->right==NULL))
        {
            count=count+1;
        }
        count_(root->left);
        count_(root->right);
       return count;
    }
};
int main()
{
    struct BST *root=NULL;
    tree ob;
    int num,n;
    cout<<"enter number of nodes in BST"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter value"<<endl;
        cin>>num;
        root=ob.create_BST(root,num);
    }
    int ans=ob.count_(root);
    cout<<"Number of Leaf Nodes:"<<ans;

}
