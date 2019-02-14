#pragma once
#include "Henkilo.h"
class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus);
	Tyontekija(const Tyontekija & alkup);
	~Tyontekija();
	Tyontekija& operator=(const Tyontekija & sij);

	void asetaPalkka(double palkka);
	void asetaTunnus(string tunnus);
	double annaPalkka() const;
	string annaTunnus() const;

	void kysyTiedot();
	void tulosta() const;

private:
	double palkka_;
	string tunnus_;
};

