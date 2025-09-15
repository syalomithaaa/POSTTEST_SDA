#include <iostream>
using namespace std;

void balik(int *p, int n){
    int i=0, j=n-1;
    while(i<j){
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
        i++; j--;
    }
}

int main(){
    int n=7;
    int a[7] = {2,3,5,7,11,13,17};

    cout << "Awal : ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    balik(a,n);

    cout << "Balik: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
