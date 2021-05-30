#include <iostream>

using namespace std;

void multiplicar(int (*pa)[3][3]){
    int *pini = **pa;
    int *pfin =**(pa+1);
    int *qini= pfin;
    int *qfin = **(pa+2);
    int (*rini)[3] = *(pa+2);
    int (*rfin)[3] = rini+1;


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

int main(){
    
    int A[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{10,20,30},{40,50,60},{70,80,90}},{{0,0,0},{0,0,0},{0,0,0}}};


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
    
    multiplicar(A);

    cout<<"\n------------------------------------------------\n";

    for (int i = 0; i < 3; i++)
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
    }


}