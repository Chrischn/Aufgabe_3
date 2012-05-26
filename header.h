#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;

class Medium														//Klasse Medium
{
protected:															//protected zur Vererbung von Variablen
	int signatur;
	string titel;
	bool status;

public:																//public fuer globalen Zugriff
	Medium();
	Medium(int i);
	void print();
	void entleihen();
	void zurueck();
	bool sigi(int sig);
};
#endif	/*HEADER_H*/