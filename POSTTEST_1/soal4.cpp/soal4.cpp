#include <iostream>
using namespace std;

void tukar(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<"Sblm: "<<x<<" "<<y<<endl;
    tukar(x,y);
    cout<<"Ssdh: "<<x<<" "<<y<<endl;
    return 0;
}
