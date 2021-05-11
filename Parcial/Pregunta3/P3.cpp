#include <iostream>

using namespace std;

bool par(int val)
{ return val%2==0;}

bool impar(int val)
{return val%2!=0;}


void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void dividir(int *ini, int *fin,bool(*pf)(int))
{
  int *p1=ini;//Puntero que aumentara la posicion para ordenar los imparares o pares al inicio
  bool listo=true;//Bool para el bucle

  for(int *p = ini; p <= fin; p++)//Recorremos por completo el array
  { 
    if ((*pf)(*p))//Hacemos la comprobacion de par o impar de acuerdo a la funcion que nos enviaron de parametro
    {
        swap(p,p1);//Cambiamos en caso sea necesario
        p1++;   //Avanzamos la posicion 
    }
  }


  while (listo)//Bucle para la ordenacion final
  {
    listo=false;//Negamos la condicion para ver si es necesariol
    for(int *p2 = p1; p2 < fin; p2++)//Recorremos el array desde la posicion donde se cambia de par a impar o viceversa hasta el final
    { 
        if (*p2>*(p2+1))//En caso este no este ordenado
        {
            swap(p2,p2+1);//Se cambia los valores
            listo=true;//Se mantiene el bucle hasta que este ordenado por completo
        }
    }
    if(!listo){//En caso no se requiera se rompe el bucle y se sigue con el codigo
        break;
    }
  }
}

int main() {
  int A[10] = {1,2,3,4,5,6,7,8,9,10};
  int B[10] = {1,2,3,4,5,6,7,8,9,10};
  
  cout<<"Ordenado sin separar"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<" ";
  
  cout<<endl;
  dividir(A,A+9,impar);
  cout<<"Ordenado Separado Impar-Par"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<" ";
  
  cout<<endl;
  dividir(B,B+9,par);
  cout<<"Ordenado Separado Par-Impar"<<endl;
  for(int *p = B; p < B+10; p++)
     cout<< *p <<" ";
}