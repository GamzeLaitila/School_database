#pragma once
#include "Koulutusohjelma.h"
#include <vector>
#include <string>
using std::string; using std::vector;

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();
	void asetaNimi(string nimi);
	string asetaNimi() const;

	void lisaaKoulutusohjelma(); // valinta 1
	void tulostaKoulutusohjelmat() const; // valinta 2
	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja(); // *
	void tulostaKoulutusohjelmanOpettajat() const; // *
	void lisaaKoulutusohjelmaanOpiskelija(); // *
	void tulostaKoulutusohjelmanOpiskelijat() const; // *
	void poistaKoulutusohjelma();// *
	void poistaKoulutusohjelmastaOpettaja(); // *
	void poistaKoulutusohjelmastaOpiskelija(); // *
	void paivitaKoulutusohjelmanNimi(); // *
	void paivitaOpettajanTiedot(); // *
	void paivitaOpiskelijanTiedot(); // *
	void lueTiedot();
	void tallennaTiedot();

	// * fonksiyonlarinin once hangi koulutusohjelmadan bahsedildigini bilmesi lazim
	// koulutusohjelma vektorunden koulutusohjelmanin ismini cekiyoruz

private:
	int etsiKoulutusohjelma(string po_li_pai_tul) const;
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
};

