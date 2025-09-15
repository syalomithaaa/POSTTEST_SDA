#include <iostream>
using namespace std;

int main(){
    int m[3][3];
    cout<<"Input matriks 3x3:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cin>>m[i][j];
    }

    cout<<"\nMatriks:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }

    int sum=0;
    for(int i=0;i<3;i++){
        if((i+1)%2==0){
            for(int j=0;j<3;j++) sum+=m[i][j];
        }
    }
    cout<<"Jumlah baris genap = "<<sum<<endl;
    return 0;
}
