#include "Koulutusohjelma.h"
#include "Koulu.h"
#include "Sovellus.h"
#include <iostream>
#include <string.h>
using std::cout; using std::endl; using std::cerr;

int main() {

	Sovellus amk("TAMK");

	try {
		amk.aja();
	}

	catch (std::exception & ex) {
		cerr << "Virhe: " << ex.what() << endl;
	}

	catch (...) {
		cerr << "Jokin virhe..." << endl;
	}

	system("pause");
	return 0;
}