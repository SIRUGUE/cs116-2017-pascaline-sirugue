#include <iostream>
#include <fstream>
#include "network.cpp"

using namespace std; 

int main ()

{
Neuron n1;
Neuron n2;
Network network (n1, n2, 0.0); 
 
double tmin; 
double tmax; 
double i;




cout << "entrez le temps minimal"<< endl; 
cin>> tmin;
cout << "entrez le temps maximal" <<endl;
cin>> tmax;
cout << "entrez le courant extérieur" <<endl;
cin>>i;

network.simulationloop();  

	
return 0;	
} 
