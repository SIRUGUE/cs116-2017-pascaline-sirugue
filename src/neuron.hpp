#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron {
	
private:
double MembranePotential;
int NbSpikes;
double TimeSpikes;
double c;


public :
Neuron (double MP, int NS, double TS, double C);
double getMembranePotential() const;
int getNbSpikes() const; 
double getTimeSpikes() const; 
void setMembranePotential(double MP);
void setNbSpikes(int NP);
void setTimeSpikes(double TS);
void updateMembranePotential (double h, double Iext, double Taw); 
~Neuron();

} ;

#endif

