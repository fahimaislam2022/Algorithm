#include<bits/stdc++.h>
using namespace std;
int main(){
srand(time(0));
int a;
int n=20;
ofstream fout("bubblesortlist.txt");
for(int i=0;i<n;i++){
a=rand()%10+1;
fout<<a<<endl;

}
}