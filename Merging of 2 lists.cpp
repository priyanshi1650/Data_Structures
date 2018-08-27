#include<iostream>
using namespace std;
class array_ll
{
  private:
   struct node
   {
     int value;
     struct node*next;
   };
  struct node*start[2];
  struct node*new_node;
  struct node*ptr;
  struct node*save;
  public:
   array_ll()
    {
      for(int i=0;i<2;i++)
       {
         start[i]=NULL;
       }
    }
   void create_ll_b()
    {
     for(int i=0;i<2;i++)
      {
        start[i]=NULL;
        int num;
        cin>>num;
       while(num!=0)
        {
          new_node=new node;
          new_node->value=num;
          new_node->next=start[i];
          start[i]=new_node;
          cin>>num;
        }
      }
    }
   void create_ll_e()
    {
        cout<<"enter elements of list1.Press 0 to exit."<<endl;
     for(int i=0;i<2;i++)
      {
        start[i]=NULL;
        int num;
        cin>>num;
       while(num!=0)
        {
          if(start[i]==NULL)
           {
            new_node=new node;
            new_node->value=num;
            new_node->next=start[i];
            start[i]=new_node;
            save=new_node;
           }
         else
          {
            new_node=new node;
            new_node->value=num;
            new_node->next=NULL;  //new_node->next=save->next
            save->next=new_node;
            save=new_node;
          }
         cin>>num;
        }
        if (i==0)
         cout<<"enter elements of list2. press 0 to exit."<<endl;
      }

    }
   void show()
    {
      for(int i=0;i<2;i++)
       {
         ptr=start[i];
         while(ptr!=NULL)
          {
           cout<<ptr->value<<" ";
           ptr=ptr->next;
          }
       }
    }
};
int main()
{
  array_ll obj;
  int flag=0;
  int option,num;
  do
  {
    cout<<"Press 1 for creating the linked lists"<<endl;
    cout<<"Press 2 for output"<<endl;
    cin>>option;
    switch(option)
    {
      case 1:
      {
       flag=1;
       cout<<"Press b for insertion at beginning and e for insertion at end"<<endl;
       char ch;
       cin>>ch;
       if(ch=='b')
        {
          obj.create_ll_b();
        }
       else if(ch=='e')
        {
          obj.create_ll_e();
        }
       else
        {
          cout<<"Enter valid option";
        }
       }
         break;
      case 2:
       {
         if(flag==1)
          {
            obj.show();
          }
         else
          {
            cout<<"Please enter the input first"<<endl;
          }
       }
         break;
       default:
            if(option!=0)
             {
               cout<<"invalid";
             }
     }
   }while(option!=0);
}
