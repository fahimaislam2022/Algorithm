#include<bits/stdc++.h>
using namespace std;
void printList(int a[],int n){
    for ( int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
void Shiftleft(int *a,int n){
    for (int i=0;i<n;i++)
    {
      a[i-1]=a[i];
    }
    for ( int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}
int main()
{

   int a[5]={10,20,30,40,50};
   printList(a,5);
   Shiftleft(a,5);
   return 0;
}


