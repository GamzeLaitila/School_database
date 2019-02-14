#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout; using std::cin;
using std::endl; using std::getline;
using std::ofstream; using std::ifstream;

Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}

Koulu::~Koulu()
{
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::asetaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	int sopivaNimi_1, sopivaNimi_2;
	string nimi;
	// burada nimi icin sartlar belirleyebilirsin, cok uzun bir isim girilirse "emin misin?" gibisinden
	do {
		cout << "Anna koulutusohjelman nimi (max 10 merkkia): ";
		getline(cin, nimi);

		if (nimi.size() > 10) {
			sopivaNimi_1 = 0;
			cout << "Antamasi koulutusohjelman nimi ylittaa merkkirajan" << endl;
		}
		else
			sopivaNimi_1 = 1;
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			if (koulutusohjelmat_[i].annaNimi() == nimi) {
				cout << "Antamasi koulutusohjelma on jo olemassa" << endl;
				sopivaNimi_2 = 0;
				break;
			}
			else
				sopivaNimi_2 = 1;
		}
		if (sopivaNimi_1 == 1 && sopivaNimi_2 == 1)
			koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
	} while (sopivaNimi_1 != 1 || sopivaNimi_2 != 1);
}

void Koulu::poistaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma("poista");
	if (indeksi >= 0) {
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + indeksi);
		cout << koulutusohjelmat_[indeksi].annaNimi() << " on poistettu jarjestelmasta..." << endl;
	}
}

void Koulu::paivitaKoulutusohjelmanNimi()
{
	string nimi;
	int indeksi = etsiKoulutusohjelma("paivita k_nimi");
	if (indeksi >= 0) {
		cout << "Anna koulutusohjelman uusi nimi: ";
		getline(cin, nimi);
		koulutusohjelmat_[indeksi].asetaNimi(nimi);
		cout << "Koulutusohjelman " << koulutusohjelmat_[indeksi].annaNimi() << " on paivitetty " << nimi << ":lla" << endl;
	}
}

void Koulu::tulostaKoulutusohjelmat() const
{
	cout << "Koulutusohjelmat:" << endl;
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		cout << i + 1 << ") " << koulutusohjelmat_[i].annaNimi() << endl;
		// koulutusohjelmat.h de kendine ozel tulosta fonksiyonu da yapabilirdik
		// burada direkt annaNimi diyerek bilgiye ulasiyoruz.
	}
	if (koulutusohjelmat_.size() == 0)
		cout << "Jarjestelmassa ei ole koulutusohjelmaa..." << endl;
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	if (koulutusohjelmat_.size() == 0)
		cout << "Jarjestelmassa ei ole koulutusohjelmaa..." << endl;
	else
		cout << "Jarjestelmassa on " << koulutusohjelmat_.size() << " koulutusohjelmaa" << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma("lisaa tiedot");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
}

void Koulu::poistaKoulutusohjelmastaOpettaja()
{
	int indeksi = etsiKoulutusohjelma("poista tiedot");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}
}

void Koulu::paivitaOpettajanTiedot()
{
	string nimi;
	int indeksi = etsiKoulutusohjelma("paivita opettaja");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpettaja();
	}
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma("tulosta tiedot");
	if (indeksi >= 0) {
		cout << "   Etunimi   |   Sukunimi  |    Osoite   | Puhelinnumero |   Palkka    |    Tunnus   |   Opetusala  " << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
	koulutusohjelmat_[indeksi].tulostaOpettajat();
	}	
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma("lisaa tiedot");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
}

void Koulu::poistaKoulutusohjelmastaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma("poista tiedot");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}
}

void Koulu::paivitaOpiskelijanTiedot()
{
	string nimi;
	int indeksi = etsiKoulutusohjelma("paivita opiskelija");
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpiskelija();
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma("tulosta tiedot");
	if (indeksi >= 0) {
		cout << "   Etunimi   |   Sukunimi  |    Osoite   | Puhelinnumero | Opiskelijanumero " << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
}

void Koulu::lueTiedot()
{
	ifstream kooh_tied, opet_tied, opis_tied;

	kooh_tied.open("koulutusohjelmat.csv");

	if (kooh_tied.is_open()) {
		int check;
		string nimi;
		while (kooh_tied.peek() != EOF) {
			getline(kooh_tied, nimi); // lopettaa rivinvaihtoon

			if (koulutusohjelmat_.size() == 0) {
				koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
			}
			else {
				check = -1;
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
					if (nimi == koulutusohjelmat_[i].annaNimi())
						check = i;
				}
				if (check == -1) {
					koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
				}
			}
		}
		cout << "---Koulutusohjelmat luettu tiedostosta---" << endl;
		kooh_tied.close();
	}
	else
		cout << "! Tiedostoa opettajista ei voi avata !" << endl;

	opet_tied.open("opettajat.csv");

	if (opet_tied.is_open()) {
		string nimi, etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
		int indeksi, check;
		double opalkka;
		while (opet_tied.peek() != EOF) {
			getline(opet_tied, nimi, ';');
			getline(opet_tied, etunimi, ';');
			getline(opet_tied, sukunimi, ';');
			getline(opet_tied, osoite, ';');
			getline(opet_tied, puhelinnumero, ';');
			getline(opet_tied, palkka, ';');
			getline(opet_tied, tunnus, ';');
			getline(opet_tied, opetusala); // lopettaa rivinvaihtoon

			opalkka = atof(palkka.c_str()); // dosyadan string olarak aldigimiz palkkayi double yapiyoruz

			if (koulutusohjelmat_.size() == 0) {
				indeksi = 0;
				koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
			}
			else {
				check = -1;
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
					if (nimi == koulutusohjelmat_[i].annaNimi())
						check = i;
				}
				if (check == -1) {
					indeksi = koulutusohjelmat_.size();
					koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
				}
				else
					indeksi = check;
			}

			Opettaja luettuopettaja(etunimi, sukunimi, osoite, puhelinnumero, opalkka, tunnus, opetusala);
			koulutusohjelmat_[indeksi].lueOpettaja(luettuopettaja);
		}
		cout << "---Opettajat luettu tiedostosta---" << endl;
		opet_tied.close();
	}
	else
		cout << "! Tiedostoa opettajista ei voi avata !" << endl;

	opis_tied.open("opiskelijat.csv");

	if (opis_tied.is_open()) {
		string nimi, etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;
		int indeksi, check;
		while (opis_tied.peek() != EOF) {
			getline(opis_tied, nimi, ';');
			getline(opis_tied, etunimi, ';');
			getline(opis_tied, sukunimi, ';');
			getline(opis_tied, osoite, ';');
			getline(opis_tied, puhelinnumero, ';');
			getline(opis_tied, opiskelijanumero); // lopettaa rivinvaihtoon

			if (koulutusohjelmat_.size() == 0) {
				indeksi = 0;
				koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
			}
			else {
				check = -1;
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
					if (nimi == koulutusohjelmat_[i].annaNimi())
						check = i;
				}
				if (check == -1) {
					indeksi = koulutusohjelmat_.size();
					koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
				}
				else
					indeksi = check;
			}

			Opiskelija luettuopiskelija(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
			koulutusohjelmat_[indeksi].lueOpiskelija(luettuopiskelija);
		}
		cout << "---Opettajat luettu tiedostosta---" << endl;
		opis_tied.close();
	}
	else
		cout << "! Tiedostoa opiskelijoista ei voi avata !" << endl;
}

void Koulu::tallennaTiedot()
{
	int noNewLine;
	ofstream kooh_tied("koulutusohjelmat_tallennettu.csv"), opet_tied("opettajat_tallennettu.csv"), opis_tied("opiskelijat_tallennettu.csv");

	if (kooh_tied.is_open())
	{
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
				kooh_tied << koulutusohjelmat_[i].annaNimi();
				if (i != koulutusohjelmat_.size() - 1)
					kooh_tied << "\n";
			}
			kooh_tied.close();
	}
	else
		cout << "! Tiedosto ei loydy !" << endl;

	if (opet_tied.is_open())
	{
		noNewLine = 0;
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			if (i == koulutusohjelmat_.size() - 1)
				noNewLine = 1;
			opet_tied << koulutusohjelmat_[i].tallennaOpettajat(noNewLine);
		}
		opet_tied.close();
	}
	else
		cout << "! Tiedosto ei loydy !" << endl;

	if (opis_tied.is_open())
	{
		noNewLine = 0;
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			if (i == koulutusohjelmat_.size() - 1)
				noNewLine = 1;
			opis_tied << koulutusohjelmat_[i].tallennaOpiskelijat(noNewLine);
		}
		opis_tied.close();
	}
	else
		cout << "! Tiedosto ei loydy !" << endl;
}

int Koulu::etsiKoulutusohjelma(string po_li_pai_tul) const // po_li_pai_tul: poista, lisää, päivitä, tulosta
{
	int check_ = 0;
	string nimi;

	if (koulutusohjelmat_.size() == 0) {
		cout << "! Jarjestelmassa ei ole koulutusohjelmaa !" << endl;
		return -1;
	}
	else {
		if (po_li_pai_tul == "lisaa tiedot") {
			cout << "Anna koulutusohjelman nimi, johon haluat lisata tietoja: ";
		}
		if (po_li_pai_tul == "poista") {
			cout << "Anna koulutusohjelman nimi, jonka haluat poistaa jarjestelmasta: ";
		}
		if (po_li_pai_tul == "poista tiedot") {
			cout << "Anna koulutusohjelman nimi, josta haluat poistaa tietoja: ";
		}
		if (po_li_pai_tul == "paivita k_nimi") {
			cout << "Anna koulutusohjelman nimi, jota haluat paivittaa: ";
		}
		if (po_li_pai_tul == "paivita opettaja") {
			cout << "Anna koulutusohjelman nimi, jonka opettajan tiedot haluat paivittaa: ";
		}
		if (po_li_pai_tul == "paivita opiskelija") {
			cout << "Anna koulutusohjelman nimi, jonka opiskelijan tiedot haluat paivittaa: ";
		}
		if (po_li_pai_tul == "tulosta tiedot") {
			cout << "Anna koulutusohjelman nimi, jonka tietoja haluat tulostaa: ";
		}
		getline(cin, nimi);
		// burada anna koulutusohj... sorularini yukardaki fonksiyonlara ozel yaz ki adam neyi nereye yazdigini bilsin

		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			if (nimi == koulutusohjelmat_[i].annaNimi()) {
				// buyuk kucuk harf ayrimi yapilmamasi saglanabilir
				// zamandan kazanmak icin (cunku 10larca isim olabilir) belki once ilk harflere bakilabilir
				check_ = 1;
				return i;
			}
		}
	}
	if (check_ == 0) {
		cout << "! Koulutusohjelmaa ei loytynyt !" << endl;
	}
	return -2;
}
