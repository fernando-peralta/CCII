#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void dividir(int *ini, int *fin)
{
  int *p1=ini;//Puntero que aumentara la posicion para ordenar los imparares o pares al inicio
  bool listo=true;//Bool para el While de ordenamiento final

  for(int *p = ini; p <= fin; p++)
  { 
    if (*p%2!=0)//En el caso que no sea par
    {
        swap(p,p1);//Intercambiamos el valor de p y p1 de esta forma se van ubicando en el inicio del array
        p1++;//Aumentamos en 1 la posicion para que avanze 
    }
  }

  while (listo)//Bool de comprobacion
    {
        listo=false;//negamos la condicion para la evaluacion
        for(int *p2 = p1; p2 < fin; p2++)//Recorremos el array desde la posicion en la que se quedo el puntero anterior, donde cambiamos de pares a impares o viceversa
        { 
            if (*p2>*(p2+1))//Hacemos una comprobacion con el siguiente elemento en el array
            {
                swap(p2,p2+1);//De ser mayor se cambia el valor
                listo=true;//Y nos aseguramos de que el bucle continue mientras no este del todo ordenado
            }
        }
        if(!listo){//Si salimos en false se rompe el bucle
            break;
        }
    }
  
}

int main() {
  int A[10] = {1,2,3,4,5,6,7,8,9,10};
  int B[10] = {1,3,4,6,7,9,10,12,11,13};
  
  cout<<"Array A"<<endl;
  cout<<"Ordenado sin separar"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<" ";
  
  cout<<endl;
  dividir(A,A+9);
  cout<<"Ordenado Separado"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<" ";

  cout<<endl;
  cout<<"Array B"<<endl;
  cout<<"Ordenado sin separar"<<endl;
  for(int *p = B; p < B+10; p++)
     cout<< *p <<" ";
  
  cout<<endl;
  dividir(B,B+9);
  cout<<"Ordenado Separado"<<endl;
  for(int *p = B; p < B+10; p++)
     cout<< *p <<" ";
}