#include <iostream>

using namespace std;

//Me parece que esta mal porque esta facil.

int long_cad(char *cad)
{
  int cont=0;
  for (;*cad;cad++){
    cont++;
  }
  return cont;
}

int long_trim_cad(char *cad)
{
  int cont=0;
  for (;*cad;cad++){
    if (*cad!=' ')
    {
      cont++;
    }
  }
  return cont;
}

int main() {
  char C[][200] = {"No hay caminos para la paz; la paz es el camino (Mahatma Gandhi)","Cada día sabemos más y entendemos menos (Albert Einstein)"," El mundo no está en peligro por las malas personas sino por aquellas que permiten la maldad (Albert Einstein)"};

  cout<<"Longitud de las cadenas"<<endl;
  cout<<"Cadena 1 "<<long_cad(*C)<<endl;
  cout<<"Cadena 2 "<<long_cad(*(C+1))<<endl;
  cout<<"Cadena 3 "<<long_cad(*(C+2))<<endl;
  
  cout<<"Longitud de las cadenas sin espacios"<<endl;
  cout<<"Cadena 1 "<<long_trim_cad(*C)<<endl;
  cout<<"Cadena 2 "<<long_trim_cad(*(C+1))<<endl;
  cout<<"Cadena 3 "<<long_trim_cad(*(C+2))<<endl;  
}