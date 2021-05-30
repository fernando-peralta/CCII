#include <iostream>
using namespace std;

void llenar_Matriz(int m[][3]){
    int (*p)[3]=m;
    int aux=0;

    for(;p<(m+3);p++){
        for (int *q = *p; q < *(p+1); q++)
        {
            *q=aux+1;
            aux++;
        }
        
    }

}

void Imprimir_matriz(int m[3][3]){
    int (*p)[3]=m;

    for(;p<(m+3);p++){
        for (int *q = *p; q < *(p+1); q++)
        {
            cout<<"|"<<*q<<"|";
        }
        cout<<endl;
    }
}

void transpuesta(int m[][3]){
    int aux=0;

    for (int (*p)[3]=m; p < (m+3); p++)
    {
        for (int *q=*p; q < *(p+1); q++)
        {
            if (q!=(*p)+aux)
            {
                *q=0;
            }
        }
        aux++;
    }
    
    
    

}

int main(){
    int M[3][3]={};
    llenar_Matriz(M);
    //Imprimir_matriz(M);
    transpuesta(M);
    Imprimir_matriz(M);
    cout<<endl<<"Fin del Programa"<<endl;
}