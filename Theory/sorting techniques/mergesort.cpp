using namespace std;
#include<iostream>
void merging(int *arr,int p,int q,int r)
{
    cout<<"\nMerging="<<p<<","<<q<<"and"<<r;
    int m=q-p+1;
    int n=r-q;
    int i,a[100],b[100],j=0,k,z,temp[100],t=0;
    for (i=p;i<=q;i++)
    {
        a[j]=arr[i];
        j++;
    }
    for (z=q+1;z<=r;z++)
    {
        b[t]=arr[z];
        t++;
    }
    i=0;
    j=0;
    k=p;
     for (t=0;t<m+n;t++)
    {
        if (a[i]<b[j] && i!=m || j==n)
        {
            arr[k]=a[i];
            i++;

        }
        else if(j!=n)
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }

}
void ms(int *arr,int p,int r)
{
    int q;
    if(p<r)
    {
       q=(p+r)/2;
       cout<<"\nMS="<<p<<"and"<<r;
       ms(arr,p,q);
       ms(arr,q+1,r);
       merging(arr,p,q,r) ;
    }
}

int main()
{
    int arr[50],s,i;
    cout<<"enter size of array"<<endl;
    cin>>s;
    for (i=0;i<s;i++)
        cin>>arr[i];
    int p=0,r=s-1;
    ms(arr,p,r);
    cout<<endl<<"SORTED ARRAY: "<<endl;
   for (i=0;i<s;i++)
    cout<<arr[i]<<endl;
}
