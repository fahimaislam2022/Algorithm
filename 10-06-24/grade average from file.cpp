#include<bits/stdc++.h>
using namespace std;
double findAvg(int*p,int n){
int sum=0;
for (int i=0;i<n;i++){
    sum+=p[i];
    }
    return (double)sum/(double)n;
}
int main(){
    int n=40;
    int *a=new int[n];

    ifstream fin("marks.txt");
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<a[i]<<endl;
    }

        cout<<"avg:"<<findAvg(a,n)<<endl;

    }




