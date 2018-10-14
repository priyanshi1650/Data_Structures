#include<iostream>
#include<stack>
using namespace std;
class heap
{
	int l,r,F=0,largest;
	public:
		void build_max_heap(int arr[],int n)
		{
			for(int i=n/2;i>=1;i--)
				max_heapify(arr,i,n);
		}
		void max_heapify(int arr[],int i,int n)
		{
			F=0;
			l=2*i;
			r=(2*i)+1;
			if(l<=n && arr[l]>arr[i])
			{
				F=1;
				largest = l;
			}
			else if(l<=n && arr[i]>arr[l])
				largest=i;
			if(r<=n && arr[r]>arr[largest])
			{
				F=1;
				largest=r;
			}
			if(F==1)
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[largest];
				arr[largest]=temp;
				max_heapify(arr,largest,n);
			}
		}
		int delete_(int arr[],int &n)
		{
			int save;
			save = arr[1];
			arr[1] = arr[n];
			n--;
			max_heapify(arr,1,n);
			return save;
		}
		void insert(int arr[],int &n)
		{
			int ele,temp;
			cout<<"Enter what element you want to insert\n";
			cin>>ele;
			n++;
			arr[n] = ele;
			int i = n;
			while(arr[i/2] < arr[i] && i > 1)
			{
				temp = arr[i / 2];
				arr[i/2] = arr[i];
				arr[i] = temp;
				i = i / 2;
			}
		}
		void update(int arr[],int n)
		{
			int index,new_,temp;
			cout<<"Enter on what index you want the new value to be inserted and the value of new element\n";
			cin>>index>>new_;
			if(new_>arr[index])
			{
				arr[index] = new_;
				int i = index;
				while(arr[i/2] < arr[i] && i > 1)
				{
					temp = arr[i / 2];
					arr[i/2] = arr[i];
					arr[i] = temp;
					i = i / 2;
				}
			}
			else
			{
				arr[index] = new_;
				max_heapify(arr,index,n);
			}
		}
		void heap_sort(int arr[],int n)
		{
			stack <int> ms;
			while(n>0)
			{
				int save = arr[1];
				ms.push(save);
				arr[1] = arr[n];
				n--;
				max_heapify(arr,1,n);
			}
			while(!ms.empty())
			{
				cout<<ms.top()<<"\t";
				ms.pop();
			}
			cout<<endl;
		}
};
int main()
{
	heap obj;
	int n;
	cout<<"Enter number of elements in you want in heap\n";
	cin>>n;
	int arr[n];
	cout<<"Enter elements in array\n";
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int choice,c=0;
	char cont;
	cout<<"Enter y to continue and n to exit\n";
	cin>>cont;
	while(cont!='n')
	{
		cout<<"Enter 1 to create max heap\n";
		cout<<"Enter 2 for deletion\n";
		cout<<"Enter 3 for insertion of new element\n";
		cout<<"Enter 4 for updation of any element\n";
		cout<<"Enter 5 for sorting in ascending order\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					obj.build_max_heap(arr,n);
					break;
				}
			case 2:
				{
					obj.delete_(arr,n);
					break;
				}
			case 3:
				{
					obj.insert(arr,n);
					break;
				}
			case 4:
				{
					obj.update(arr,n);
					break;
				}
			case 5:
				{
					obj.heap_sort(arr,n);
					c = 1;
					break;
				}
		}
		if(c==0)
		{
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<"\t";
		}
		cout<<endl;
		cout<<"Enter y to continue and n to exit\n";
		cin>>cont;
	}
	return 0;
}
