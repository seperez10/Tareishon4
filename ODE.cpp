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
//este paso anterior nos generara 4 variables las cuales son xf,yf,dxf y dyf, para las cuales sera necesario tener claro que las pendientes iniciales de estas las vamos a asumir como cero pero saber que iran variando con el tiempo
 double pendxf=0.0;
 double pendyf=0.0;
 double penddxf=0.0;
 double penddyf=0.0;

//Tambien sera necesario definir 4 variables para cada una de estas variables 
 double var1xf=0.0;
 double var2xf=0.0;
 double var3xf=0.0;
 double var4xf=0.0;
 double var1yf=0.0;
 double var2yf=0.0;
 double var3yf=0.0;
 double var4yf=0.0;
 double var1dxf=0.0;
 double var2dxf=0.0;
 double var3dxf=0.0;
 double var4dxf=0.0;
 double var1dyf=0.0;
 double var2dyf=0.0;
 double var3dyf=0.0;
 double var4dyf=0.0;
}
/////Aca realizaremos la derivada para el unico punto que conocemos en los 4 casos 
int i=0;
do{

 var1xf= derix(dxini);
 var1yf= derix(dyini);
 var1dxf= derix(dxini,dyini);
 var1dxf= derix(dxini,dyini);

//Posteriormente se
int main(){
}

