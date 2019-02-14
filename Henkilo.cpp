#include "Henkilo.h"
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::getline;

Henkilo::Henkilo() :etunimi_(), sukunimi_(), osoite_(), puhelinnumero_()
{
}

Henkilo::Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero) : etunimi_(etunimi), sukunimi_(sukunimi), osoite_(osoite), puhelinnumero_(puhelinnumero)
{
}

Henkilo::Henkilo(const Henkilo & alkup) : etunimi_(alkup.etunimi_), sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_), puhelinnumero_(alkup.puhelinnumero_)
{
}

Henkilo::~Henkilo()
{
}

Henkilo & Henkilo::operator=(const Henkilo & sij)
{
	if (this != &sij) {
		etunimi_ = sij.etunimi_; // stringde kendinden operator= var
		sukunimi_ = sij.sukunimi_; // ^^
		osoite_ = sij.osoite_; // ^^
		puhelinnumero_ = sij.puhelinnumero_; // ^^
	}
	return *this;
}

void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

void Henkilo::kysyTiedot()
{
	cout << "Anna etunimi: ";
	getline(cin, etunimi_);
	cout << "Anna sukunimi: ";
	getline(cin, sukunimi_);
	cout << "Anna osoite: ";
	getline(cin, osoite_);
	cout << "Anna puhelinnumero: ";
	getline(cin, puhelinnumero_);
}

void Henkilo::tulosta() const
{	
	int length_e, length_s, length_o, length_p;
	length_e = 13 - etunimi_.length();
	length_s = 12 - sukunimi_.length();
	length_o = 12 - osoite_.length();
	length_p = 14 - puhelinnumero_.length();
	
	cout << etunimi_;
	for (int i = 0; i < length_e; i++)
		cout << " ";
	cout << "| " << sukunimi_;
	for (int i = 0; i < length_s; i++)
		cout << " ";
	cout << "| " << osoite_;
	for (int i = 0; i < length_o; i++)
		cout << " ";
	cout << "| " << puhelinnumero_;
	for (int i = 0; i < length_p; i++)
		cout << " ";
}
