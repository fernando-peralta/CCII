#include <iostream>
#include <cmath>//Para tener un valor de Pi
using namespace std;

//Comentarios
//Profe decidi que los parametros sean double debido a las posibilidades de las areas de presentar numeros no enteros
//el unico caso que nose si esta bien es el area del circulo por la manera de determinar los parametros de entrada en el for


double AreaCirc(int a, int b){
    return M_PI*(a*b);//Uso del valor de pi de cmath y area del circulo (pi * r^2)
}

double AreaRect(int b, int h){
    return b*h;//Area Rectangulo (base * altura)
}

double AreaTrian(int b, int h){
    return (b*h)/2;//Area triangulo (base * altura)/2
}

int main(){

    int parm[2]={10,15},aux=0;//valores de parametros y auxiliar para las frases
    double (*p[3])(int,int)={AreaCirc,AreaRect,AreaTrian};//puntero a funcion que recibe en este caso 2 int pero puede ser float o double para la presicion
    char frase[3][100]={"Circulo","Rectangulo","Triangulo"};//Frases de las areas

    for(double (*(*pp))(int,int)=p; pp<p+3; pp++){//recorrido con punteros
        if ((*pp)==AreaCirc)//en caso pida el area del circulo
        {
            for (int i = 0; i < 2; i++)//Repetimos dos veces en este caso con los valores de parm
            {
                 cout<<"Area de "<<frase[aux]<<" con parm ["<<i<<"]: "<<(*pp)(parm[i],parm[i])<<endl;
            }
            aux++;
        }else{
            cout<<"Area de "<<frase[aux]<<": "<<(*pp)(parm[0],parm[1])<<endl;//Realizamos la solucion de las demas areas
            aux++;
        }
    }
    cout<<endl<<"Un feliz dia de la madre a su senora esposa y senora madre."<<endl<<endl;
    cout<<"Fin del programa";
}