#include<bits/stdc++.h>
using namespace std;
int main(){
srand(time(0));
int a;
ofstream fout("100k.txt");
for(int i=0;i<100000;i++){
a=rand();//%6+1;
fout<<a<<endl;

}
}
