#include <iostream>
#include <fstream>

using namespace std;

const int MAXDIM = 10;
const int HOVINTO = 1;
const int HOPERSO = 2;

struct partita {
	string formato;
	string myDeck;
	string oppDeck;
	int gameVinti;
	int gamePersi;
	int esito;
};

struct lista {
	int indicatore;
	partita dati[MAXDIM];	
};

int schermoMenu();
int leggiInteroCompreso(int min, int max, string messaggio);
void schermoLeggiDati(lista& l);
int menuLeggiDati();
int listaVuota (lista l);
void leggiDaTastiera(lista& l);
partita leggiPartitaConsole(int numPartita);
string leggiStringa(string messaggio);
int calcolaEsito(int gameVinti, int gamePersi);
void leggiDaFile(lista& l);
void leggiDaFile(partita& p, ifstream& flussoDaFile);
void schermoStampaDati(lista l);
int menuStampaDati (lista l);
void stampaSuConsole(lista l);
void stampaPartitaConsole(partita p);
void stampaSuFile(lista l);
void stampaIntestazione(lista l, ofstream& flussoSuFile);
void stampaPartitaFile(partita p, ofstream& flussoSuFile);

int main() {
	int scelta;
	lista l;
	l.indicatore = 0;
	while (true) {
		scelta = schermoMenu();
		if (scelta == 0) {
			cout << "Alla prossima!" << endl;
			break;
		} 
		else if (scelta == 1) {
			schermoLeggiDati(l);
		}
		else if (scelta == 2) {
			schermoStampaDati(l);	
		}
		else if (scelta == 3) {
			cout << "3" << endl;
		}
	}
	return 0;
}

int schermoMenu() {
	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << "|+----------------------------------------------------------------------------+|" << endl;
	cout << "|| Benvenuto sul mio tracker per mtg! Che operazione vuoi eseguire?           ||" << endl;
	cout << "|| 1. Acquisisci dati partite                                                 ||" << endl;
	cout << "|| 2. Stampa dati                                                             ||" << endl;
	cout << "|| 3.                                                                         ||" << endl;
	cout << "|| 0. Esci                                                                    ||" << endl;
	cout << "|+----------------------------------------------------------------------------+|" << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;
	return leggiInteroCompreso(0, 3, "Scelta --> "); 
}

int leggiInteroCompreso(int min, int max, string messaggio) {
	int valore;
	cout << messaggio;
	cin >> valore;
	while (valore < min || valore > max) {
		cout << "ERRORE! Deve essere compreso tra " << min << " e " << max << ". Reinserisci: ";
		cin >> valore;
	}
	return valore;
}

void schermoLeggiDati(lista& l) {
	if (listaVuota(l) == (MAXDIM - 1)) {
		cout << "La lista e' piena" << endl;
	} else {
		int scelta = menuLeggiDati();
		if (scelta == 0) {
			cout << "Hai deciso di non inserire nessun dato" << endl;
		}
		else if (scelta == 1) {
			leggiDaTastiera(l);
		}
		else if (scelta == 2) {
			leggiDaFile(l);
		}
	}
}

int menuLeggiDati() {
	cout << "+--------------------------------------+" << endl;
	cout << "| 1. Inserisci dati manualmente        |" << endl;
	cout << "| 2. Carica dati da file               |" << endl;
	cout << "| 0. Esci                              |" << endl;
	cout << "+--------------------------------------+" << endl;
	return leggiInteroCompreso(0, 2, "Scelta --> ");
}  

int listaVuota (lista l) {
	return l.indicatore;
}

void leggiDaTastiera(lista& l) {
	int numDati = leggiInteroCompreso(0, (MAXDIM - l.indicatore), "Quante partite vuoi inserire? " );
	for (int i = 0; i < numDati; i++) {
		// Mostra dati di formato e mazzo in anticipo e puo' inserirli automaticamente se si ha giocato di nuovo lo stresso mazzo
		l.dati[i] = leggiPartitaConsole(i);
		l.indicatore++;
	}
}

partita leggiPartitaConsole(int numPartita) {
	cout << "Partita numero " << numPartita + 1 << ". Inserisici i dati." << endl;
	partita p;
	cin.ignore();
	p.formato = leggiStringa("Inserisci formato: ");
	p.myDeck = leggiStringa("Inserisci il mazzo che hai giocato: ");
	p.oppDeck = leggiStringa("Inserisci il mazzo contro cui hai giocato: ");
	p.gameVinti = leggiInteroCompreso(0, 2, "Quanti game hai vinto? ");
	p.gamePersi = leggiInteroCompreso(0, 2, "Quanti game hai perso? ");
	p.esito = calcolaEsito(p.gameVinti, p.gamePersi);
	return p;
}

string leggiStringa(string messaggio) {
	string s;
	cout << messaggio;
	getline(cin, s);
	while (s.size() == 0) {
		cout << "ERRORE! Non puo' essere vuoto! Reinserisci: ";
		getline(cin, s);
	}
	return s;
}

int calcolaEsito(int gameVinti, int gamePersi) {
	if (gameVinti < gamePersi) {
		return HOPERSO;
	}
	return HOVINTO; 
}

void leggiDaFile(lista& l) {
	string s;
	string nomeFile = "partite.txt";
	ifstream flussoDaFile(nomeFile.c_str());
	flussoDaFile >> l.indicatore;
	flussoDaFile.ignore();
	for (int i= 0; i < l.indicatore; i++) {
			leggiDaFile(l.dati[i], flussoDaFile);
		}
	flussoDaFile.close();
	cout << "Lettura da file effettuata" << endl;
}

void leggiDaFile(partita& p, ifstream& flussoDaFile) {
	flussoDaFile >> p.formato;
 	flussoDaFile >> p.myDeck;
 	flussoDaFile >> p.oppDeck;
 	flussoDaFile >> p.gameVinti;
 	flussoDaFile >> p.gamePersi;
 	flussoDaFile >> p.esito;
}

void schermoStampaDati(lista l) {
	if (l.indicatore == 0) {
		cout << "La lista e' vuota" << endl;
	} else {
		int scelta = menuStampaDati(l);
		if (scelta == 0) {
			cout << "Hai deciso di non stampare nessun dato" << endl;
		}
		else if (scelta == 1) {
			stampaSuConsole(l);
		}
		else if (scelta == 2) {
			stampaSuFile(l);
		}
	}
} 

int menuStampaDati (lista l) {
	cout << "+--------------------------------------+" << endl;
	cout << "| 1. Stampa dati su schermo            |" << endl;
	cout << "| 2. Stampa dati su file               |" << endl;
	cout << "| 0. Esci                              |" << endl;
	cout << "+--------------------------------------+" << endl;
	return leggiInteroCompreso(0, 2, "Scelta --> ");
}		

void stampaSuConsole(lista l) {
	for (int i= 0; i < l.indicatore; i++) {
			stampaPartitaConsole(l.dati[i]);
		}
}

void stampaPartitaConsole (partita p) {
 	cout << "\nFormato: " << p.formato << endl;
 	cout << "Il tuo mazzo: " << p.myDeck << endl;
 	cout << "Il mazzo dell'avversario: " << p.oppDeck << endl;
 	cout << "Game vinti: " << p.gameVinti << endl;
 	cout << "Game persi: " << p.gamePersi << endl;
 	if (p.esito == HOVINTO) {
 		cout << "Hai vinto!" << endl;
 	} else {
 		cout << "Hai perso!" << endl;
 	}
}

void stampaSuFile(lista l) {
	string nomeFile = "partite.txt";
	ofstream flussoSuFile(nomeFile.c_str());
	stampaIntestazione(l, flussoSuFile);
	for (int i= 0; i < l.indicatore; i++) {
			stampaPartitaFile(l.dati[i], flussoSuFile);
		}
	flussoSuFile.close();
	cout << "Dati stampati su file" << endl;
}

void stampaIntestazione(lista l, ofstream& flussoSuFile) {
	flussoSuFile << l.indicatore << endl;
//	flussoSuFile << "Formato\t";
// 	flussoSuFile << "Il tuo mazzo\t";
// 	flussoSuFile << "Il mazzo dell'avversario\t";
// 	flussoSuFile << "Game vinti\t";
// 	flussoSuFile << "Game persi" << "\n";
// 	flussoSuFile << "----------------------------------------------------------------" << "\n";	
}

void stampaPartitaFile(partita p, ofstream& flussoSuFile) {
	flussoSuFile << p.formato << "\t";
 	flussoSuFile << p.myDeck << "\t";
 	flussoSuFile << p.oppDeck << "\t";
 	flussoSuFile << p.gameVinti << "\t";
 	flussoSuFile << p.gamePersi << "\t";
 	flussoSuFile << calcolaEsito(p.gameVinti, p.gamePersi) << "\n";
}

