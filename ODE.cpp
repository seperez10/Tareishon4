#include <math.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
using std::cout;
using std::cin;

//Defino las variables que me brinda el enunciado de la tarea 
double c=0.2;
double m=0.2;
double resultini=0.0;
double g=10.0;
double velo=300.0;
double dx;
double dy;

//Es necesario crear una funcion para encontrar cual sera la derivada de la velocidad en x pero para eso necesito tener la derivada tanto en y como en x de la posicion 
double deriy( double dy)
{
 return dy;
}
double derix( double dx)
{
 return dx;
}

//////En el paso anterior estan las funciones para que se puedan utilizar con facilidad las derivadas de las posiciones
//////Primero es necesario hallar la magnitud de la velocidad simplemente con la raiz de la suma de las dos componentes elevadas al cuadrado cada una

double magnitudvelo= sqrt(pow(dx,2)+pow(dy,2));

double deriveloy(double dy,double dx){

 resultini= -c*((pow(magnitudvelo,2)/m)*(dy/magnitudvelo));
 cout << "magnitud" << magnitudvelo << endl;
 return resultini;
}
double derivelox(double dy,double dx){

 resultini= -c*((pow(magnitudvelo,2)/m)*(dx/magnitudvelo));

 return resultini;
}

////////////Aca se hara una funcion
int main(){
}

