#pragma once
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
#include <vector>
using std::string; using std::vector;

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	~Koulutusohjelma();
	void asetaNimi(string nimi);
	string annaNimi() const;
	void lisaaOpettaja();
	void lisaaOpiskelija();
	void poistaOpettaja();
	void poistaOpiskelija();
	void paivitaOpettaja();
	void paivitaOpiskelija();
	void lueOpettaja(Opettaja&);
	void lueOpiskelija(Opiskelija&);
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	string tallennaOpettajat(int noNewLine);
	string tallennaOpiskelijat(int noNewLine);

private:
	int etsiOpettaja(string tunnus) const;
	int etsiOpiskelija(string opiskelijanumero) const;
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

