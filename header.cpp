#include <iostream>
#include <string>
#include "header.h"
#include <iomanip>
#include <ctype.h>

using namespace std;


Medium::Medium()																		//Konstruktor der Klasse Medium
{
	cout << endl << "Signatur eingeben: ";
	cin >> signatur;
	while(cin.fail())
	{
		cin.clear();
		cin.sync();
		cout << endl << "Nur Zahlen eingeben!" << endl;
		cout << endl << "Signatur eingeben: ";
		cin >> signatur;				
	}
		
	cout << endl << "Titel eingeben: ";
	cin.sync();
	getline(cin,titel);
		
	cout << endl << "Verleihstatus(verliehen = 0 ; vorhanden = 1): ";
	cin >> status;
	while(cin.fail())
	{
		cin.clear();
		cin.sync();
		cout << endl << "Nur 1 oder 0 angeben" << endl;
		cout << endl << "Verleihstatus(verliehen = 0 ; vorhanden = 1): ";
		cin >> status;		
	}
	cout << endl;
}

void Medium::print()																	//Elementfunktion der Klasse Medium
{																						//Bildschirmausgabe der Klassendaten
	cout << setw(10) << right << signatur;

	cout << setw(9) << left << "   Medium";

	cout << "   " << setw(20) << left << titel;

	if(status == 0){cout << setw(8) << right << "   entl." << endl;}else{cout << setw(8) << right << "   vorh." << endl;}

}

void Medium::entleihen()																//Elementfunktion der Klasse Medium
{																						//Entleihe Medium und setze ggf. Status
	if(status == 0)																		//Pruefe ob gewuenschtes Medium bereits entliehen
	{
		cout << endl << "Medium breits entliehen!" << endl;
	}
	else
	{
		status = 0;
		cout << endl << "Buch wurde erfolgreich geliehen." << endl;
	}
}

void Medium::zurueck()																	//Elementfunktion der Klasse Medium
{																						//Gebe Medium zurueck und setze ggf. Status
	if(status == 0)																		//Pruefe ob Medium bereits zurueckgegeben worden ist
	{
		status = 1;
		cout << endl << "Medium wird zurueckgegeben!" << endl;
	}
	else
	{
		cout << endl << "Medium ist bereits zurueckgegeben worden" << endl;
	}
}

bool Medium::sigi(int sigi)
{
	if(signatur == sigi)
	{
		return true;
	}
	else
	{
		return false;
	}

}


Medium::Medium(int i)																	//Ueberladener Medium-Konstruktor (Parametertyp int)
{
	cout << endl << "Signatur eingeben: ";
	cin >> signatur;
	while(cin.fail())
	{
		cin.clear();
		cin.sync();
		cout << endl << "Nur Zahlen eingeben!" << endl;
		cout << endl << "Signatur eingeben: ";
		cin >> signatur;				
	}						
}