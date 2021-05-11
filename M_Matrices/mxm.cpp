#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void Multiplicar_matriz(int (*p)[3][3]){
    int *q2=**(p+2);

    for (int (*q)[3]=*p;q<*(p+1);q++){
        for (int *q1=**(p+1); q1 < *(*(p+1)+1); q1++){
            for (int i = 0; i < 3; i++)
            {
                *q2+=*(*q+i) * *(q1+i*3);
            }
            q2++;
        }
    }
}


void LLenar_matriz(int (*p)[3][3]){
    srand(time(0));

    for (int (*q)[3]=*p; q < *(p+2); q++){
        for (int *r=*q; r<*(q+1); r++){
            *r=rand()%26+1;
        }
    }

    for (int (*q)[3]=*(p+2); q < *(p+3); q++){
        for (int *r=*q; r<*(q+1); r++){
            *r=0;
        }
    }
}



void Print_matriz(int (*p)[3][3]){
    int aux=0;
    for (int (*q)[3]=*p; q < *(p+3); q++){
        for (int *r=*q; r<*(q+1); r++){
            cout<<"|"<<*r<<"|";
        }
        cout<<endl;
        aux++;
        if(aux==3){
            cout<<endl;
            aux=0;
        }
    ;}
    
    cout<<endl;
}



int main(){

    int matriz[3][3][3];
    int (*p)[3][3]=matriz;
    cout<<"Matrices antes:\n"<<endl;
    LLenar_matriz(p);
    Print_matriz(p);
    cout<<"Matrices despues:\n"<<endl;
    Multiplicar_matriz(p);
    Print_matriz(p);

}