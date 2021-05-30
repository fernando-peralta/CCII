#include <iostream>

using namespace std;

void multiplicar(int (*pa)[3][3]){
    int *pini = **pa;//Primer elemento de la matriz
    int *pfin =**(pa+1);//pa+1, primer elemento de la segunda matriz
    int *qini= pfin;
    int *qfin = **(pa+2);//pa+2, primer elemento de la tercera matriz
    int (*rini)[3] = *(pa+2);//Primera fila de la tercera matriz
    int (*rfin)[3] = rini+1;//Segunda fila de la tercera matriz


    int *p = pini;
    int *q = qini;
    int *r = *rini;

    while (p<pfin)
    {
        *r = *r+ *p * *q;
        r++;
        q++;
        if(r==*rfin){
            p++;
            r=*rini;
        }

        if(q==qfin){
            q=qini;
            rini++;
            rfin++;
            r=*rini;
        }
    }
    
}



void imprimir(int (*pa)[3][3], int (*pf)[3][3]){
    for(int (*i)[3][3]=pa;i<pf+1;i++){
        for (int (*j)[3] = *i; j < *(i+1); j++)
        {
            for (int *k=*j; k < *(j+1); k++)
            {
                cout<<"|"<<*k<<"|";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(){
    
    int A[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{10,20,30},{40,50,60},{70,80,90}},{{0,0,0},{0,0,0},{0,0,0}}};
    
    imprimir(A,A+2);

    multiplicar(A);

    cout<<"------------------------------------------------\n\n";

    imprimir(A,A+2);

    /*for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int  k = 0; k < 3; k++)
            {
                cout<<"|"<<A[i][j][k]<<"|";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }*/


}