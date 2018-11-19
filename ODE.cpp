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
double pi=3.1416;

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
 return resultini;
}

double derivelox(double dy,double dx){

 resultini= -c*((pow(magnitudvelo,2)/m)*(dx/magnitudvelo));

 return resultini;
}

////////////Aca se hara una funcion la cual nos permita saber que pasara con el proyectil dependiendo el angulo con el que pueda ser disparado

double calculitos (double angulito){
//En primer lugar para que las cosas funcionen es necesario pasar el angulo de radianes a grados y definimos cual quiero que sea mi modificacion de tiempo que en este caso sera 0.0001 ya que no se brinda una en el enunciado
 double dt=0.0001;
 double angulitogr= ((angulito*pi)/180.0);
//Necesitamos tener los datos del inicio y tambien de alguna condicion futura que pueda existir
 double xf;
 double yf;
 double xini=0.0;
 double yini=0.0;
// tambien sera necesario definir las condiciones iniciales y de algun futuro para las derivadas respecto a la posicion, la inicial simplemente se encontrara mediante el uso de componentes a partir de la velocidad inicial dada en el enunciado
 double dxf;
 double dyf;
 double dxini=velo*cos(angulitogr);
 double dyini=velo*sin(angulitogr); 
//este paso anterior nos generara 4 variables las cuales son xf,yf,dxf y dyf, para las cuales sera necesari
}
int main(){
}

