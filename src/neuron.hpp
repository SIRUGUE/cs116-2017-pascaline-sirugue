#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>

using namespace std;

class Neuron {
	
private:
double MembranePotential;
int NbSpikes;
double TimeSpikes;
int TimeRefractory;
double J;
double Iext;
double delay;
vector <double> buffer;
const double c=1.0; 
const double tau=20.0 ; 
const double Vreset=0.0;
const double Vthr=20.0;
const double h=0.1;


public :
Neuron (double MP, int NS, double TS, int TR, double j, double i, double d);
Neuron (double i);
double getMembranePotential() const;
int getNbSpikes() const; 
int getTimeRefractory() const;
double getTimeSpikes() const; 
double getVreset() const;
double getVthr() const;
double getTau() const;
double geth() const;
double getJ() const;
double getDelay() const;
void setMembranePotential(double MP);
void setNbSpikes(int NP);
void setTimeSpikes(double TS);
void setTimeRefractory (int TimeRefractory);
void setI (double i);
void updateMembranePotential (); 
void write();
bool IsSpiking();
void updateNeuron (double tmin, double tmax, double i);
void addJ(int i, double j);
~Neuron();

} ;

#endif

