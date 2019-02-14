#pragma once
#include "Tyontekija.h"
class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus, string opetusala);
	Opettaja(const Opettaja & alkup);
	~Opettaja();
	Opettaja& operator=(const Opettaja & sij);

	void asetaOpetusala(string opetusala);
	string annaOpetusala() const;
	void kysyTiedot();
	void tulosta() const;

private:
	string opetusala_;
};

