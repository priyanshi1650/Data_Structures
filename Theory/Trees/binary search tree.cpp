using namespace std;
#include<iostream>
#include<queue>
#include<stack>
class tree
{
    struct BST
    {
        int info;
        struct BST *left;
        struct BST *right;
    };
    struct BST *root=NULL;
    struct BST *check;
    struct BST *new_node;
public:
    BST* get()
    {
        return root;
    }
    void create()
    {
        int num;
        cout<<"enter values."<<endl<<"Press 0 to exit."<<endl;
        cin>>num;
        while(num!=0)
        {
           new_node=new BST;
           new_node->info=num;
           new_node->left=NULL;
           new_node->right=NULL;
           if(root==NULL)
           {
               root=new_node;
           }
           else
           {
               check=root;
               while(1)
               {
               if(check->info<num)
               {
                   if(check->right==NULL)
                   {
                       check->right=new_node;
                       cout<<"Parent is:"<<check->info<<endl;
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
                       cout<<"Parent is:"<<check->info<<endl;
                       break;
                   }
                   else
                   {
                       check=check->left;
                   }
               }
               }
           }
           cin>>num;
        }
    }
void search(int num)
{
struct BST *parent;
struct BST *save=root;
check=root;
int flag=1;
if (save->info==num)
{
    cout<<"Number found"<<endl;
    cout<<"it is a root element"<<endl;
}
else
{
while(1)
{
if(check->info==num)
{
cout<<"Number Found"<<endl;
break;
}
else if(check->info<num && check->right!=NULL)
{
    parent=check;
    check=check->right;
}
else if(check->info>num && check->left!=NULL)
{
    parent=check;
    check=check->left;
}
else
{
cout<<"Number Not found"<<endl;
flag=0;
break;
}
}
if (flag==1)
cout<<"Parent of"<<num<<" is:"<<parent->info<<endl;

}
}
void preorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        cout<<a->info<<endl;
        preorder_display(a->left);
        preorder_display(a->right);
    }
}
void postorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        postorder_display(a->left);
        postorder_display(a->right);
        cout<<a->info<<endl;
    }
}
void inorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        inorder_display(a->left);
        cout<<a->info<<endl;
        inorder_display(a->right);
    }
}
void min()
{
    check=root;
    while(check->left!=NULL)
    {
        check=check->left;
    }
    cout<<"Minimum element is:"<<check->info<<endl;
}
void max()
{
    check=root;
    while(check->right!=NULL)
    {
        check=check->right;
    }
    cout<<"Maximum element is:"<<check->info<<endl;
}
void level_order(BST* root)
{
    struct BST *ptr;
    queue<BST*> myqueue;
    myqueue.push(root);
    ptr=myqueue.front();
    while(!myqueue.empty())
    {
        myqueue.pop();
        cout<<ptr->info<<" ";
        if(ptr->left!=NULL)
            myqueue.push(ptr->left);
        if(ptr->right!=NULL)
            myqueue.push(ptr->right);
        ptr=myqueue.front();
    }
    cout<<endl;
}
void pre(BST *root)
{
    struct BST *ptr;
    stack<BST*>mystack;
    mystack.push(root);
    while(!mystack.empty())
    {
        ptr=mystack.top();
        mystack.pop();
        cout<<ptr->info<<" ";
        if(ptr->right!=NULL)
            mystack.push(ptr->right);
        if(ptr->left!=NULL)
            mystack.push(ptr->left);
    }
    cout<<endl;
}
void in(BST *root)
{
    stack<BST*>stk;
    struct BST *ptr;
    ptr=root;
    do
    {
    if(ptr)
    {
        stk.push(ptr);
        ptr=ptr->left;
    }
    else
    {
        ptr=stk.top();
        stk.pop();
        cout<<ptr->info<<" ";
        ptr=ptr->right;
    }
    }while(!stk.empty() || ptr!=NULL);
}
};
int main()
{
    tree ob;
    int ch;
    cout<<"Press 1 to create binary tree"<<endl<<"Press 2 to search an element"<<endl<<"Press 3 to find minimum element in tree"<<endl;
    cout<<"Press 4 to find max element in tree"<<endl<<"Press 0 to exit"<<endl;
    cin>>ch;
    while(ch!=0)
    {
    switch(ch)
    {
   case 1:
    ob.create();
    break;
   case 2:
    int val;
    cout<<"Enter number you want to search"<<endl;
    cin>>val;
    ob.search(val);
    break;
   case 3:
    ob.min();
    break;
   case 4:
    ob.max();
    break;
   case 5:
       char op;
       cout<<"Press 'a' to display INORDER with recursion"<<endl<<"Press 'b' to display PREORDER with recursion"<<endl;
       cout<<"Press 'c' to display POSTORDER with recursion"<<endl<<"Press 'd' to display level order"<<endl;
       cout<<"Press 'e' to display PREORDER without recursion"<<endl<<"Press 'f' to display POSTORDER without recursion"<<endl;
       cout<<"Press 'g' to display INORDER without recursion"<<endl;
       cin>>op;
       if(op=='a')
       ob.inorder_display(ob.get());
       if(op=='g')
       ob.in(ob.get());
       else if(op=='b')
        ob.preorder_display(ob.get());
       else if(op=='c')
        ob.postorder_display(ob.get());
       else if(op=='d')
        ob.level_order(ob.get());
       else if(op=='e')
        ob.pre(ob.get());
     break;
    }
    cout<<"Press 1 to create binary tree"<<endl<<"Press 2 to search an element"<<endl<<"Press 3 to find minimum element in tree"<<endl;
    cout<<"Press 4 to find max element in tree"<<endl<<"Press 5 to display"<<endl<<"Press 0 to exit"<<endl;
    cin>>ch;
    }
}
