#include <iostream>
#include <string>
#include "header.h"
#include "container.h"
using namespace std;

int main()
{
	char modus = NULL;																		//Variable fuer Modus
	Medium* ptrm = NULL;																	//Temporaere Pointer auf neuerstelltes Objekt des Typs Mediums
	int sigi;
	Container* ptrc = new Container();

	while(modus != 'q')																		//Pruefe ob Modus 'q' (Quit) ist, sonst Programm fortfuehren
	{
		cout << "Waehlen sie den gewuenschten Modus:" << endl << endl;
		cout << "Moegliche Modi:" << endl;
		cout << "m : neues Medium anlegen" << endl;
		cout << "l : Medium ausgeben" << endl;
		cout << "e : Medium entleihen" << endl;
		cout << "r : Medium zurueckgeben" << endl;
		cout << "d : Medium loeschen" << endl;
		cout << "q : beenden" << endl << endl;
		cout << "Modus: "; 
		cin >> modus;																		//Einlesen des gewuenschten Modus in Variable 'modus'
		cout << endl;

			switch(modus)
			{
////------------------------------------------------------------------------------------------------------------------------------------
				case 'm':
				ptrm = new Medium();
				ptrc->add(ptrm);
				ptrm = NULL;
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				case 'l':																	//Gebe kompletten Medienbestand auf Bildschirm aus
				cout << "Medienbestand:" << endl;
				ptrc->tmp_element = ptrc->erstes_element;
				while(ptrc->tmp_element != NULL)
				{
					ptrc->tmp_element->obj_adr->print();
					ptrc->tmp_element = ptrc->tmp_element->next;
				}
				ptrc->tmp_element = NULL;
////------------------------------------------------------------------------------------------------------------------------------------
				case 'q':																	//Beende Programm
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				case 'd':
				cout << endl << "Zu loeschende Mediensignatur eingeben: ";
				cin >> sigi;
				while(cin.fail())
				{
					cin.clear();
					cin.sync();
					cout << endl << "Nur Zahlen eingeben!" << endl;
					cout << endl << "Signatur eingeben: ";
					cin >> sigi;
				}
				cout << endl;
				if(ptrc->remove(sigi))
				{
					cout << "Das Medium wurde geloescht!" << endl;
				}
				else
				{
					cout << "Kein Medium mit dieser Signatur gefunden!" << endl;
				}
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				default:
				cout << endl << "Nur gueltige Buchstaben verwenden!" << endl;				//Abfangen von fehlerhaften Benutzereingaben
////------------------------------------------------------------------------------------------------------------------------------------
			}
		if(modus != 'q'){modus = NULL; cin.sync();}											//Setze modus Pointer zurueck
		cout << endl;
	}
	return 0;
}