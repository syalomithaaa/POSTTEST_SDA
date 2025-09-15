#include <iostream>
using namespace std;

struct Mhs{
    string nama;
    string nim;
    float ipk;
};

int main(){
    Mhs m[4];
    for(int i=0;i<4;i++){
        cout<<"Nama : "; cin>>m[i].nama;
        cout<<"NIM  : "; cin>>m[i].nim;
        cout<<"IPK  : "; cin>>m[i].ipk;
    }

    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            if(m[i].ipk>m[j].ipk){
                Mhs tmp=m[i];
                m[i]=m[j];
                m[j]=tmp;
            }
        }
    }

    cout<<"\nData urut IPK:\n";
    for(int i=0;i<4;i++){
        cout<<m[i].nama<<" "<<m[i].nim<<" "<<m[i].ipk<<endl;
    }
    return 0;
}

