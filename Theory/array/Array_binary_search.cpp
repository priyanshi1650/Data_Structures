#include<iostream>
using namespace std;
int main()
{
	int N,ser;
	cout<<"Enter number of elements in array\n";
	cin>>N;
	int arr[N];
	int temp;
	cout<<"Enter elements in the array in sorted fashion\n";
	for(int i = 0 ; i < N ; i ++)
	{
		cin>>arr[i];
	}
	/*for(int i = 0 ; i < N - 1 ; i ++)
	{
		for(int j = 0 ; j < N - i - 1 ; j ++)
		{
			if(arr[j] > arr[j + 1])
			{
				arr[i] = temp;
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}*/

	cout<<"Enter element to be searched\n";
	cin>>ser;
	int beg = 0;
	int end = N - 1;
	int mid = (beg + end) / 2;
	while(beg <= end)
	{
		if(ser < arr[mid])
		{
			end = mid - 1;
		}
		else if(ser == arr[mid])
		{
			cout<<"Found at position "<<mid;
			break;
		}
		else if(ser > arr[mid])
		{
			beg = mid + 1;
		}
		mid = (beg + end)/2;
	}
	if(beg > end)
	{
		cout<<"Not found";
	}
	return 0;
}
