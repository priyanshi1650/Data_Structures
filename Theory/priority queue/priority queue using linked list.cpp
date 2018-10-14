using namespace std;
#include<iostream>
class pqueue
{
    struct node
    {
        int val;
        struct node *next;
        int prior;
    };
    struct node *front;
    struct node *rear;
    struct node *new_node;
    struct node *ptr;
    struct node *save;
public:
    pqueue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue()
    {
        int num,priority;
        cout<<"enter value"<<endl;
        cin>>num;
        cout<<"enter priority"<<endl;
        cin>>priority;
        new_node=new node;
        new_node->val=num;
        new_node->prior=priority;
        if (rear==NULL)
        {
            new_node->next=NULL;
            rear=new_node;
            front=new_node;
        }
        else
        {
          if(new_node->prior<front->prior)
              {
                 new_node->next=front;
                 front=new_node;
              }
          else if(new_node->prior > rear->prior)
              {
                  new_node->next=NULL;
                  rear->next=new_node;
                  rear=new_node;
              }
              else
              {
                  ptr=front;
                  while(ptr!=NULL)
                  {
                  if(new_node->prior < ptr->prior)
                  {
                      break;
                  }
                  save=ptr;
                  ptr=ptr->next;
                  }
                  new_node->next=ptr;
                  save->next=new_node;
              }
          }
    }
    void dequeue()
    {
        int p;
        cout<<"enter priority"<<endl;
        cin>>p;
        ptr=front;
        int flag=0;
        while (ptr != NULL)
        {
            if (ptr->prior==p)
            {
                flag=1;
                break;
            }
            save=ptr;
            ptr=ptr->next;
        }
        if (flag==1)
        {
            save->next=ptr->next;
            ptr->next=NULL;
            delete ptr;
        }
        else
            cout<<"Wrong priority"<<endl;
    }
    void display()
    {
        ptr=front;
       while (ptr!=NULL)
       {
        cout<<ptr -> val;
        cout<<endl;
        ptr=ptr->next;
       }
    }
};
int main()
{
    pqueue ob;
    int ch;
    cout<<"enter 1 to insert elements"<<endl<<"2 to display"<<endl<<"3 to delete"<<endl<<"0 to exit"<<endl;
    cin>>ch;
    while (ch!=0)
    {
        switch (ch)
        {
        case 1:
            ob.enqueue();
            break;
        case 2:
            ob.display();
            break;
        case 3:
            ob.dequeue();
            break;
        }
     cout<<"enter 1 to insert elements"<<endl<<"2 to display"<<endl<<"3 to delete"<<endl<<"0 to exit"<<endl;
     cin>>ch;
    }
}
