#include<bits/stdc++.h>
using namespace std;
int main(){
srand(time(0));
int a;
int n=40;
ofstream fout("marks.txt");
for(int i=0;i<n;i++){
a=rand()%100+1;
fout<<a<<endl;

}
}

