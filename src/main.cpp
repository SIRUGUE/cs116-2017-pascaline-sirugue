#include <iostream>
#include <fstream>
#include "neuron.cpp"
using namespace std;

int main ()

{
Neuron neuron1; 
double tmin; 
double tmax; 
double h(0.1); 
double Iext;
double Vreset(0.0);
double Vthr(20.0);
int TimeRefractory (0); 
double Taw(20.0);
double i;




cout << "entrez le temps minimal"<< endl; 
cin>> tmin;
cout << "entrez le temps maximal" <<endl;
cin>> tmax;
cout << "entrez le courant extérieur" <<endl;
cin>> i;

neuron1.setTimeSpikes(tmin);

while ((neuron1.getTimeSpikes() < tmax) and (neuron1.getTimeSpikes()>=tmin)) {
Iext=i;

	if (TimeRefractory>0) {
	    TimeRefractory= TimeRefractory-1;
	    neuron1.setMembranePotential(Vreset);
	    }
	    
	else       {
   neuron1.updateMembranePotential(h, Iext, Taw);

      if(neuron1.getMembranePotential()>Vthr)  {
	   ofstream sortie;
	   sortie.open("test.txt", ios::out | ios::app );
	   TimeRefractory = 2.0; 
	   sortie << neuron1.getTimeSpikes() << endl;
	   sortie.close(); 
	    }
	    
	   }
neuron1.setTimeSpikes( ( neuron1.getTimeSpikes()+h ) ) ; 

} 




return 0;
} 
