#include <iostream>

using namespace std;

void CocktailSort(int a[], int n){//Recibe el array y su largo
    int start = 0, end=n-1,aux;//Posiciones en la que iniciara las bubble ida y vuelta, aux=auxiliar
    int *punter=a;//Puntero para el array
    bool listo=true;//Bool para seguir mientras se ordena el array

    while (listo)
    {
        listo=false;//inicia en false para comprobar

        for (int i = start; i < end; i++)
        {
            aux=i+1;//auxiliar para la comparacion con el elemento siguiente a[i] y a[i+1]
            if (*(punter+i)>*(punter+aux)){//comprueba cual es mayor
                swap(*(punter+i),*(punter+aux));//intercambia el valor en la direccion de memoria
                listo=true;//permite que el while continue
            }
        }

        if(!listo){// Si no se intercambio nada se corta de golpe
            break;//para reducir la cantidad de veces que se produce (eficiencia)
        }

        listo=false;//Repetimos el proceso pero desde otra posicion

        --end;//reducimos la posicion de inicio del bubble de vuelta

        for (int i = end-1; i >= start; --i)//Recorremos el array denuevo pero de vuelta se compara hasta llegar al inicio
        {
            aux=i+1;
            if (*(punter+i)>*(punter+aux)){//Comparacion y cambio
                swap(*(punter+i),*(punter+aux));
                listo=true;//se permite seguir con el While
            }
        }

        ++start;//aumentamos la posicion de inicio del bubble de ida
        cout<<"1";

    }    
}

void imprimir(int a[], int n){//Funcion para mostrar el Array
    int *puntero=a;//puntero para recorrer

    for (int i = 0; i < n; i++)//se recorre segun la cantidad de elementos
    {
        cout<<*(puntero+i)<<" ";//imprime elemento por elemento
    }

    cout<<endl;
}

void CocktailSort1(int a[],int n){
    int end=n-1;
    bool listo=true;
    int *p=a;
    while (listo)
    {
        listo=false;

        for (; p<(a+end); p++)
        {
            if (*p>*(p+1))
            {
                swap(*p,*(p+1));
                listo=true;
            }
        }

        if(listo==false){
            break;
        }

        listo=false;

        for (int *p1=p; p1>(p-end); p1--)
        {
            if (*p1<*(p1-1))
            {
                swap(*p1,*(p1-1));
                listo=true;
            }
            
        }
        end=end-1;
    }
}




int main(){

    int a[]={5,2,1,6,7,25,20,63,4}, largo=sizeof(a)/sizeof(a[0]);//array y calculo de la cantidad de elementos
    cout<<"Cadena inicial: ";//Imprimimos cadena sin ordenar
    imprimir(a,largo);
    /*CocktailSort(a,largo);//Ordenamos la cadena
    cout<<"Cadena ordenada CocktailSort: ";//Imprimimos cadena ordenada
    imprimir(a,largo);*/
    CocktailSort1(a,largo);//Ordenamos la cadena
    cout<<"Cadena ordenada CocktailSort1: ";//Imprimimos cadena ordenada
    imprimir(a,largo);
    cout<<"Fin del programa";
}