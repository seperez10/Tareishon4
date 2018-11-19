#include <math.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
using std::cout;
using std::cin;
ofstream datossalida("datosproyect.txt");
ofstream datosadic("adicional.txt");
//Defino las variables que me brinda el enunciado de la tarea y hacia donde redireccionare los archivos
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



double deriveloy(double dx,double dy){
 double magnitudvelo= sqrt((pow(dx,2)+pow(dy,2)));
 resultini= -c*((pow(magnitudvelo,2)/m)*(dy/magnitudvelo));
 
 return resultini;
}
double derivelox(double dx,double dy){
double magnitudvelo= sqrt((pow(dx,2)+pow(dy,2)));
 resultini= -c*((pow(magnitudvelo,2)/m)*(dx/magnitudvelo));
 return resultini;
}

////////////Aca se hara una funcion la cual nos permita saber que pasara con el proyectil dependiendo el angulo con el que pueda ser disparado

double calculitos (double angulito){
//En primer lugar para que las cosas funcionen es necesario pasar el angulo de radianes a grados y definimos cual quiero que sea mi modificacion de tiempo que en este caso sera 0.0001 ya que no se brinda una en el enunciado
 double angulitogr= (angulito/180.0*3.1416);
 double dt=0.0002;
 cout<<"resolvemos la trayectoria del proyectil cuando es lanzado a" << angulito<<"°"<<endl;
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

/////Aca realizaremos la derivada para el unico punto que conocemos en los 4 casos 
int i=0;
 do{
int i=0;
  var1xf= derix(dxini);
  var1yf= derix(dyini);
  var1dxf= derivelox(dyini,dxini);
  var1dyf= deriveloy(dyini,dxini);

//Posteriormente con forward y las diferentes variables creadas anteriormente se intentara calcular la derivada adelante utilizando la que calculamos anteriormente y asi consecutivamente hasta tener todas las variables para asi lograr hallar la pendiente de cada uno de los casos tomando los valores de las variables en x en y en dx o dy
  var2xf= derix(dxini+0.5*dt*var1dxf); 
  var2yf= deriy(dyini+0.5*dt*var1dyf);
  var2dxf= derivelox(dxini+0.5*dt*var1dxf, dyini+0.5*dt*var1dyf);
  var2dyf= deriveloy(dxini+0.5*dt*var1dxf, dyini+0.5*dt*var1dyf);
  var3xf= derix(dxini+0.5*dt*var2dxf); 
  var3yf= deriy(dyini+0.5*dt*var2dyf);
  var3dxf= derivelox(dxini+0.5*dt*var2dxf, dyini+0.5*dt*var2dyf);
  var3dyf= deriveloy(dxini+0.5*dt*var2dxf, dyini+0.5*dt*var2dyf); 
  var4xf= derix(dxini+1*dt*var3dxf); 
  var4yf= deriy(dyini+1*dt*var3dyf);
  var4dxf= derivelox(dxini+1*dt*var3dxf, dyini+1*dt*var3dyf);
  var4dyf= deriveloy(dxini+1*dt*var3dxf, dyini+1*dt*var3dyf);
  pendxf=(1.0*var1xf+2.0*var2xf+2.0*var3xf+1.0*var4xf)/6.0;  
  pendyf=(1.0*var1yf+2.0*var2yf+2.0*var3yf+1.0*var4yf)/6.0;
  penddxf=(1.0*var1dxf+2.0*var2dxf+2.0*var3dxf+1.0*var4dxf)/6.0;
  penddyf=(1.0*var1dyf+2.0*var2dyf+2.0*var3dyf+1.0*var4dyf)/6.0;   


//Luego de hacer TOOOOOODO esto, se deben ir actualizando los pasos de las variables xf, yf, dxf y dyf a medida que avanza el tiempo mediante el uso del dt
  xf=xini+pendxf*dt;
  yf=yini+pendyf*dt;
  dxf=dxini+penddxf*dt;
  dyf=dyini+penddyf*dt;
  datossalida<<xini<<" "<<yini<<" "<<dxini<<" "<<dyini<<endl;

///Y finalmente tocaria guardar los valores de xf, yf, dxf y dyf en xini,yini,dxini y dyini y se le sumara 1 al i para que siga cambiando los valores a medida que avanza
  xini=xf;
  yini=yf;
  dxini=dxf;
  dyini=dyf;
  i=i+1;
} while(i=0 && yini>0);
//Despues de esto ya sabremos cual es el xf el cual representara nuestra distancia recorrida total horizontalmente
 datosadic<<i<<endl;
 cout<<"La distancia total recorrida horizontalmente por el proyectil es" << xini <<endl;
 cout<<"La trayectoria que se calcula para el proyectil a" << angulito << " ° "<<endl<<endl;
//datossalida.close();
//datosadic.close();
 return xini;
}
//Aqui realizaremos lo que tiene que mostrar o sea lo mas importante e inicializamos las variables de nuevo
int main(int argc, char const *argv[]){
 double angulito=45.0;
 double xini= calculitos(angulito);
 double distance[7];
 ///Ahora es necesario encontrar el angulo al cual presentara una mayor distancia el proyectil como lo dice el enunciado
for (int i=0;i<7;++i){
 angulito= 10.0*(i+1);
 distance[i]=calculitos(angulito);
}
int maximo=6;
for (int i=0;i<7;i++){
 if (distance[maximo]<distance[i]){
  maximo=i;
 }
}
cout<<"Donde se presenta una mayor distancia es cuando el proyectil es lanzado a un angulo de" << (maximo+1)*10 <<endl<<endl;	
 return 0;
}

