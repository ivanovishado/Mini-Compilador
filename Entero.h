#ifndef ENTERO_H_INCLUDED
#define ENTERO_H_INCLUDED

#include "Expresion.h"

class Entero : public Expresion {
public:
	Entero (std::string sim) { simbolo = sim; }
	std::string xml(void) { return "<ENTERO>" + simbolo + "</ENTERO>\n"; }
	void validacionSemantica(void) { tipo = 'i'; }
	std::string generaCodigo(void) { return "\tpush " + simbolo + "\n"; }
};

#endif // ENTERO_H_INCLUDED
