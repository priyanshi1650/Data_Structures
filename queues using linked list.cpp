using namespace std;
#include<iostream>
class queues
{
struct node
{
int val;
struct node *next;
};
struct node *front;
struct node *rear;
struct node *new_node;
public:
queues()
{
front=NULL;
rear=NULL;
}
void enqueue()
{
int num;
cout<<"enter value"<<endl;
cin>>num;
new_node=new node;
new_node->val=num;
new_node->next=NULL;
if (rear==NULL)
 {
  rear=new_node;
  front=new_node;
 }
else
{
 rear->next=new_node;
 rear=new_node;
}
}
void dequeue()
{
   if (front==NULL)
   cout<<"UNDERFLOW"<<endl;
   else
   {
    struct node *temp;
    temp=front;
    front=temp -> next;
    temp -> next=NULL;
    cout<<"element deleted: "<<temp->val<<endl;
    delete temp;
    }
}
void show()
{
    while (front!=NULL)
    {
       dequeue();
    }
    if (front==NULL)
        cout<<"empty queue"<<endl;
}
};

int main()
{
    queues ob;
    int ch;
    cout<<"enter 1 to enter a element in queue \n2 to delete\n3 to display \n0 to exit"<<endl;
    cin>>ch;
    while (ch!=0)
    {
        switch(ch)
        {
        case 1:
            ob.enqueue();
            break;
        case 2:
            ob.dequeue();
            break;
        case 3:
            ob.show();
        }
         cout<<"enter 1 to enter a element in queue \n2 to delete\n3 to display \n0 to exit"<<endl;
    cin>>ch;
    }
}
