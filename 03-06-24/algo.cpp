#include<bits/stdc++.h>
using namespace std;
void printList(int *a,int n){
    for (int i=0;i<n;i++){
            cout<<(a+i)<<*(a+i)<<" "<<a[i]<<endl;
        }
    //cout<<(a+0)<<*(a+0)<<" "<<a[0]<<endl;
    //cout<<(a+1)<<*(a+1)<<" "<<a[1]<<endl;


}
int main()
{

   int a[5]={10,20,30,40,50};
   printList(a,5);
   return 0;
}
