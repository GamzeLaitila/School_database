#include "Tyontekija.h"
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::getline;

Tyontekija::Tyontekija(): Henkilo(), palkka_(0.0), tunnus_()
{
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, 
	double palkka, string tunnus) : Henkilo(etunimi, sukunimi, osoite, puhelinnumero), palkka_(palkka), tunnus_(tunnus)
{
}

Tyontekija::Tyontekija(const Tyontekija & alkup) : Henkilo(alkup), palkka_(alkup.palkka_), tunnus_(alkup.tunnus_)
{
}


Tyontekija::~Tyontekija()
{
}

Tyontekija & Tyontekija::operator=(const Tyontekija & sij)
{
	if (this != &sij) {
		Henkilo::operator=(sij);
		palkka_ = sij.palkka_;
		tunnus_ = sij.tunnus_;
	}
	return *this;
}

void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

double Tyontekija::annaPalkka() const
{
	return palkka_;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

void Tyontekija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "Anna palkka: ";
	string palkkaX;
	getline(cin, palkkaX);
	palkka_ = atof(palkkaX.c_str()); // c_str() stringi char tablosuna ceviriyor. atof(): ascii to float
	cout << "Anna tunnus: ";
	getline(cin, tunnus_);
}

void Tyontekija::tulosta() const
{
	int length_pa, length_tu;
	if (palkka_ < 100)
		length_pa = 2;
	if (palkka_ > 100 && palkka_ < 1000)
		length_pa = 3;
	if (palkka_ > 1000 && palkka_ < 10000)
		length_pa = 4;
	if (palkka_ > 10000 && palkka_ < 100000)
		length_pa = 5;
	length_tu = 12 - tunnus_.length();

	Henkilo::tulosta();
	cout << "| " << palkka_;
	for (int i = 0; i < (12 - length_pa); i++)
		cout << " ";
	cout << "| " << tunnus_;
	for (int i = 0; i < length_tu; i++)
		cout << " ";
}
