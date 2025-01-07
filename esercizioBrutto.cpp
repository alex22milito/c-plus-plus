#include <iostream>

using namespace std;

/*
Esercizio n. 1 
È necessario scrivere un programma in linguaggio C++ che gestisca i dati di una collezione di monitor. La collezione 
può avere dimensione variabile. Ciascun monitor è rappresentato attraverso: a) il modello, b) la marca, c) il prezzo (tra 
1 e 500 Euro) e d) i pollici (tra 13 e 32). Il programma deve effettuare le seguenti operazioni attraverso l’utilizzo di un 
menu di comandi: 
	• leggere dalla tastiera i valori della collezione 
	• stampare i valori della collezione sullo schermo 
	• cerca monitor con numero maggiore di pollici: 
		o il sistema ricerca tutti i monitor con il numero di pollici più grande 
		o stampare sullo schermo il risultato della ricerca 
Esercizio n. 2 
Estendere il programma sviluppato nell’esercizio precedente aggiungendo le seguenti operazioni: 
	• generare una seconda collezione 
		o l’utente inserisce un valore minimo e un valore massimo di pollici 
		o il sistema aggiunge ad una nuova collezione tutti i monitor che hanno un numero di pollici compreso fra i due 
		  valori inseriti precedentemente 
	• stampare i valori della seconda collezione 
	• calcolo prezzo minimo per pollici: 
		o per ogni dimensione in pollici presente in entrambe le collezioni il sistema ricerca il monitor con il prezzo 
		  minore (fra entrambe le collezioni)  
		o stampare sullo schermo la dimensione in pollici e il monitor trovato
*/

const int MAXDIM = 20;

struct monitor {
	string modello;
	string marca;
	float prezzo;
	float pollici;
};

struct lista {
	int indicatore;
	monitor dati[MAXDIM];
};

struct sommaDiListe {
	int indicatore;
	monitor dati[2 * MAXDIM];
};

struct check {
	int indicatore;
	float valori[MAXDIM];
};

int schermoMenu();
int leggiInteroCompreso(int min, int max, string messaggio);
void schermoLeggiDati(lista& l);
bool listaVuota(lista l);
bool listaPiena(lista l);
string leggiStringa(string messaggio);
float leggiRealeCompreso(float min, float max, string messaggio);
void schermoStampaDati(lista l);
void schermoPolliciMax(lista l);
float cercaMax(lista l);
void schermoSottolista(lista l, lista& m);
void schermoPrezzoMin(lista l, lista m);
int cercaMin(sommaDiListe l);
void valoriPollici(lista l, lista m, check& c);
void controllaRipetizione (lista l, check& c, int i);
void creaSommaListe(lista l, lista m, check c, sommaDiListe& n);
void stampaMin(int pos, sommaDiListe n);

int main () {
	lista l, m;
	l.indicatore = 0;
	m.indicatore = 0;
	int scelta;
	while (true) {
		scelta = schermoMenu();
		if (scelta == 0) {
			break;
		}
		else if (scelta == 1) {
			schermoLeggiDati(l);
		}
		else if (scelta == 2) {
			schermoStampaDati(l);
		}
		else if (scelta == 3) {
			schermoPolliciMax(l);
		}
		else if (scelta == 4) {
			schermoSottolista(l, m);
		}
		else if (scelta == 5) {
			schermoStampaDati(m);
		}
		else if (scelta == 6) {
			schermoPrezzoMin(l, m);
		}
	}
	return 0;
}

int schermoMenu() {
	cout << "---------------------------------" << endl;
	cout << "Benvenuto, scegli un'opzione:" << endl;
	cout << "0. Esci" << endl;
	cout << "1. Leggi dati" << endl;
	cout << "2. Stampa dati" << endl;
	cout << "3. Cerca pollici maggiori" << endl;
	cout << "4. Crea seconda collezione" << endl;
	cout << "5. Stampa seconda collezione" << endl;
	cout << "6. Prezzo minimo per pollici" << endl;
	cout << "---------------------------------" << endl;
	int valore = leggiInteroCompreso(0, 6, "Scelta: ");
	return valore;
}

int leggiInteroCompreso(int min, int max, string messaggio) {
	cout << messaggio;
	int valore;
	cin >> valore;
	while (valore < min || valore > max) {
		cout << "Errore! Deve essere compreso tra " << min << " e " << max << ". Reinserisci: ";
		cin >> valore;
	}
	return valore;
}

void schermoLeggiDati(lista& l) {
	if (listaPiena(l)) {
		cout << "La collezione e' piena" << endl;
		return;
	}
	l.indicatore = leggiInteroCompreso(0, MAXDIM, "Quanti elementi vuoi inserire? ");
	for (int i = 0; i < l.indicatore; i++) {
		cout << "* Monitor " << i << endl;
		cin.ignore();
		l.dati[i].modello = leggiStringa("Qual e' il modello? ");
		l.dati[i].marca = leggiStringa("Qual e' la marca? ");
		l.dati[i].prezzo = leggiRealeCompreso(1, 500, "Qual e' il prezzo? ");
		l.dati[i].pollici = leggiRealeCompreso(13, 32, "Quanti pollici misura la diagonale? ");
	}

}

bool listaPiena(lista l) {
	if (l.indicatore == MAXDIM) {
		return true;
	}
	return false;
}


bool listaVuota(lista l) {
	if (l.indicatore == 0) {
		return true;
	}
	return false;
}

float leggiRealeCompreso(float min, float max, string messaggio) {
	cout << messaggio;
	float valore;
	cin >> valore;
	while (valore < min || valore > max) {
		cout << "Errore! Deve essere compreso tra " << min << " e " << max << ". Reinserisci: ";
		cin >> valore;
	}
	return valore;
}

string leggiStringa(string messaggio) {
	cout << messaggio;
	string s;
	getline(cin, s);
	while (s.size() == 0) {
		cout << "Errore! Non puo' essere vuota. Reinserisci: ";
		getline(cin, s);
	}
	return s;
}

void schermoStampaDati(lista l) {
	if (listaVuota(l)) {
		cout << "La collezione e' vuota" << endl;
		return;
	}
	for (int i = 0; i < l.indicatore; i++) {
		cout << "* Monitor " << i << endl;
		cout << "Modello: " << l.dati[i].modello << endl;
		cout << "Marca: " << l.dati[i].marca << endl;
		cout << "Prezzo: " << l.dati[i].prezzo << endl;
		cout << "Pollici: " << l.dati[i].pollici << endl;
	}

}

void schermoPolliciMax(lista l) {
	if (listaVuota(l)) {
		cout << "La collezione e' vuota" << endl;
		return;
	}
	float polliciMax = cercaMax(l);
	for (int i = 0; i < l.indicatore; i++) {
		if (l.dati[i].pollici == polliciMax) {
			cout << "* Monitor " << i << endl;
			cout << "Modello: " << l.dati[i].modello << endl;
			cout << "Marca: " << l.dati[i].marca << endl;
			cout << "Prezzo: " << l.dati[i].prezzo << endl;
			cout << "Pollici: " << l.dati[i].pollici << endl;
		}
	}
}

float cercaMax(lista l) {
	int pos = 0;
	for (int i = 1; i < l.indicatore; i++) {
		if (l.dati[pos].pollici < l.dati[i].pollici) {
			pos = i;
		}
	}
	return l.dati[pos].pollici;
}

void schermoSottolista(lista l, lista& m) {
	if (listaVuota(l)) {
		cout << "La collezione e' vuota" << endl;
		return;
	}
	if (listaPiena(m)) {
		cout << "La collezione e' piena" << endl;
		return;
	}
	float polliciMin = leggiRealeCompreso(13, 32, "Inserire valore minimo di pollici: ");
	float polliciMax = leggiRealeCompreso(polliciMin, 32, "Inserire valore massimo di pollici: ");
	int j = 0;
	for (int i = 0; i < l.indicatore; i++) {
		if (l.dati[i].pollici <= polliciMax && l.dati[i].pollici >= polliciMin) {
			m.dati[j].modello = l.dati[i].modello;
			m.dati[j].marca = l.dati[i].marca;
			m.dati[j].prezzo = l.dati[i].prezzo;
			m.dati[j].pollici = l.dati[i].pollici;
			j++;
		}
	}
	m.indicatore = j;
}

void schermoPrezzoMin(lista l, lista m) {
	check c;
	c.indicatore = 0;
	sommaDiListe n;
	n.indicatore = 0;
	valoriPollici(l, m, c);
	int pos;
	for (int i = 0; i < c.indicatore; ++i) {
		creaSommaListe(l, m, c, n);
		pos = cercaMin(n);
		stampaMin(pos, n);
	}
}	

void valoriPollici(lista l, lista m, check& c) {
	for (int i = 0; i < l.indicatore; i++) {
		for (int j = 0; j < m.indicatore; j++) {
			if (l.dati[i].pollici == m.dati[j].pollici) {
				controllaRipetizione(l, c, i);	
			}
		}
	}
}

void controllaRipetizione (lista l, check& c, int i) {
	int k;
	for (k = 0; k < c.indicatore; k++) {
		if (l.dati[i].pollici == c.valori[k]) {
			return;
		}
	}
	l.dati[i].pollici = c.valori[c.indicatore];
	c.indicatore++;
}

int cercaMin(sommaDiListe l) {
	int pos = 0;
	for (int i = 1; i < l.indicatore; i++) {
		if (l.dati[pos].prezzo > l.dati[i].prezzo) {
			pos = i;
		}
	}
	return pos;
}

void creaSommaListe(lista l, lista m, check c, sommaDiListe& n) {
	int k = 0;
	for (int i = 0; i < c.indicatore; i++) {
		for (int j = 0; j < l.indicatore; j++) {
			if (c.valori[i] == l.dati[j].pollici) {
				n.dati[k].modello = l.dati[j].modello;
				n.dati[k].marca = l.dati[j].marca;
				n.dati[k].prezzo = l.dati[j].prezzo;
				n.dati[k].pollici = l.dati[j].pollici;
				k++;
			}
		}
		for (int z = 0; z < m.indicatore; z++) {
			if (c.valori[i] == m.dati[z].pollici) {
				n.dati[k].modello = m.dati[z].modello;
				n.dati[k].marca = m.dati[z].marca;
				n.dati[k].prezzo = m.dati[z].prezzo;
				n.dati[k].pollici = m.dati[z].pollici;
				k++;
			}
		}
	}
	n.indicatore = k;
}

void stampaMin(int pos, sommaDiListe n) {
	cout << "* Misura in pollici: " << n.dati[pos].pollici << endl;
	cout << "Modello: " << n.dati[pos].modello << endl;
	cout << "Marca: " << n.dati[pos].marca << endl;
	cout << "Prezzo: " << n.dati[pos].prezzo << endl;
}
