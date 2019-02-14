#include "Koulutusohjelma.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using std::cout; using std::cin;
using std::endl; using std::getline;
using std::to_string;

Koulutusohjelma::Koulutusohjelma() : nimi_(), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja ope;
	ope.kysyTiedot();
	opettajat_.push_back(ope);
	cout << endl << "---Opettaja lisatty---" << endl;
}

void Koulutusohjelma::paivitaOpettaja()
{
	string tunnus;
	cout << "Anna paivittamasi opettajan tunnus: ";
	getline(cin, tunnus);

	int indeksi = etsiOpettaja(tunnus);
	if (indeksi >= 0) {
		opettajat_[indeksi].kysyTiedot();
		cout << endl << "---Opettajan tiedot paivitetty---" << endl;
	}
	else
		cout << endl << "! Opetteja ei loytynyt !" << endl;

}

void Koulutusohjelma::lueOpettaja(Opettaja& luettuopettaja)
{
	opettajat_.push_back(luettuopettaja);
}

void Koulutusohjelma::poistaOpettaja()
{
	string tunnus;
	cout << "Anna poistamasi opettajan tunnus: ";
	getline(cin, tunnus);

	int indeksi = etsiOpettaja(tunnus);
	if (indeksi >= 0) {
		opettajat_.erase(opettajat_.begin() + indeksi);
		cout << endl << "---Opettaja poistettu---" << endl;
	}
	else
		cout << endl << "! Opetteja ei loytynyt !" << endl;
}

void Koulutusohjelma::tulostaOpettajat() const
{
	// ogretmen hic girilmemisse, "giris yok" gibisinden mesaj yazdir
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
		opettajat_[i].tulosta();
	}
}

string Koulutusohjelma::tallennaOpettajat(int noNewLine)
{
	string tallennettavatOpettajat = "";
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
	
		std::ostringstream streamObj;
		streamObj << opettajat_[i].annaPalkka();
		std::string strObj = streamObj.str();

		tallennettavatOpettajat = tallennettavatOpettajat + annaNimi() + ";" + opettajat_[i].annaEtunimi()
			+ ";" + opettajat_[i].annaSukunimi() + ";" + opettajat_[i].annaOsoite()
			+ ";" + opettajat_[i].annaPuhelinnumero() + ";" + strObj
			+ ";" +	opettajat_[i].annaTunnus() + ";" + opettajat_[i].annaOpetusala();
		if (!(noNewLine == 1 && i == opettajat_.size() - 1))
			tallennettavatOpettajat = tallennettavatOpettajat + "\n";
	}
	return tallennettavatOpettajat;
}

string Koulutusohjelma::tallennaOpiskelijat(int noNewLine)
{
	string tallennettavatOpiskelijat;
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		tallennettavatOpiskelijat = tallennettavatOpiskelijat + annaNimi() 
			+ ";" + opiskelijat_[i].annaEtunimi() + ";" + opiskelijat_[i].annaSukunimi() 
			+ ";" + opiskelijat_[i].annaOsoite() + ";" + opiskelijat_[i].annaPuhelinnumero() 
			+ ";" + opiskelijat_[i].annaOpiskelijanumero();
		if (!(noNewLine == 1 && i == opiskelijat_.size() - 1))
			tallennettavatOpiskelijat = tallennettavatOpiskelijat + "\n";
	}
	return tallennettavatOpiskelijat;
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija opisk;
	opisk.kysyTiedot();
	opiskelijat_.push_back(opisk);
	cout << endl << "---Opiskelija lisatty---" << endl;
}

void Koulutusohjelma::paivitaOpiskelija()
{
	string opiskelijanumero;
	cout << "Anna paivittamasi opiskelijan opiskelijanumero: ";
	getline(cin, opiskelijanumero);

	int indeksi = etsiOpiskelija(opiskelijanumero);
	if (indeksi >= 0) {
		opiskelijat_[indeksi].kysyTiedot();
		cout << endl << "---Opiskelijan tiedot paivitetty---" << endl;
	}
	else
		cout << endl << "! Opetteja ei loytynyt !" << endl;
}

void Koulutusohjelma::lueOpiskelija(Opiskelija& luettuopiskelija)
{
	opiskelijat_.push_back(luettuopiskelija);
}

void Koulutusohjelma::poistaOpiskelija()
{
	string opiskelijanumero;
	cout << "Anna poistamasi opiskelijan opiskelijanumero: ";
	getline(cin, opiskelijanumero);

	int indeksi = etsiOpiskelija(opiskelijanumero);
	if (indeksi >= 0) {
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
		cout << endl << "---Opiskelija poistettu---" << endl;
	}
	else
		cout << endl << "! Opiskelija ei loytynyt !" << endl;
}


void Koulutusohjelma::tulostaOpiskelijat() const
{
	// ogrenci hic girilmemisse, "giris yok" gibisinden mesaj yazdir
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		opiskelijat_[i].tulosta();
	}
}
int Koulutusohjelma::etsiOpettaja(string tunnus) const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
		if (tunnus == opettajat_[i].annaTunnus())
			return i;
	}
	return -1; // ei löytynyt - listede verilen isim yoksa
}
int Koulutusohjelma::etsiOpiskelija(string opiskelijanumero) const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero())
			// buyuk kucuk harf ayrimi yapilmamasi saglanabilir
			// zamandan kazanmak icin (cunku 10larca isim olabilir) belki once ilk harflere bakilabilir
			return i;
	}
	return -1; // ei löytynyt - listede verilen isim yoksa
}