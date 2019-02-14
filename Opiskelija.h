#pragma once
#include "Henkilo.h"
class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero);
	Opiskelija(const Opiskelija & alkup);
	~Opiskelija();
	Opiskelija& operator=(const Opiskelija & sij);

	void asetaOpiskelijanumero(string opiskelijanumero);
	string annaOpiskelijanumero() const;
	void kysyTiedot();
	void tulosta() const;

private:
	string opiskelijanumero_;
};

