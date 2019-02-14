#pragma once
#include <string>
using std::string;

class Sovellus
{
public:
	Sovellus();
	Sovellus(string nimi);
	~Sovellus();
	void asetaNimi(string nimi);
	string annaNimi() const;

	void aja() const;

private:
	string tulostaValikko() const;
	string nimi_;
};