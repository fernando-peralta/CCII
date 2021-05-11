#include <iostream>
using namespace std;

void SinEspacios(char cadena[100]){//Recibe de funcion las frases de maximo 100 caracteres
    char* pt=cadena;//Puntero que apunta al inicio de cada frase

    for (; *cadena; cadena++)//Recorremos la frase
    {
        if (*cadena !=' '){//Mientras el caracter sea diferente de espacio
            *pt=*cadena;//Hacemos que el valor ubicado en ese espacio de memoria sea igual a la frase
            ++pt;//Avanzamos un espacio de memoria
        }
    }
    *pt ='\0';//Cerramos la frase sin espacios con el caracter \0 para poder detectar el final de la misma
}

bool Palindromo(char (*p)[100]){//Recibe de parametro las fraces que tengan como limite 100 caracteres
    char* paux=*p;//Ubicamos puntero a frase
    char* paux2=*p;//Ubicamos puntero a frase
    SinEspacios(*p);//Llenamos la funcion sin espacios para la comparacion
    for (;*paux; paux++);//Enviamos nuestro primer puntero hasta el digito \0
    paux--;//retrocedemos un digito para de esta forma ubicarnos en la ultima letra de la frase
    while (*paux==*paux2){//Comprobamos si todas las letras son iguales
        paux--;//El que esta ubicado al final retrocede 
        paux2++;//El que esta ubicado en el inicio avanza hasta el final
        if (*paux2=='\0')//Para evitar el error de pasarte al inicio rompemos el bucle al llegar al final 
        {
            break;
        }
    }
    if(*paux2==*paux){//Si los valores an terminado igual, es decir, es una frase palindroma
        return true;//Retornamos True
    }else{//Si no son iguales al momento de terminar el recorrido
        return false;//Retornamos false
    }
}

int main(){
    char A[5][100]={"amo la paloma","roma se asoma","ali tomo tila","anita lava la tina","ramona come mora"};//Frases a evaluar
    char (*p)[100]=A;//Puntero que apunta a frases que tienen 100 caracteres como maximo 
    for (int i=0;i<5;i++)//For para poder enviar la evaluacion para la cantidad de frases que tiene a evaluar en este acaso son 5
    {
        cout<<"Frase "<<i+1<<":"<<Palindromo(p+i)<<endl;//Al retornar como sabemos que frase a sido nos apoyamos en el for para determinar la posicion de la frase que se evaluo
    }
    

}