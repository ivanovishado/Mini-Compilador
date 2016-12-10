#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED

#include <map>
#include "Expresion.h"

class Identificador : public Expresion {
public:
	Identificador (std::string sim)	{ simbolo = sim; }
	std::string xml (void) { return "<ID>" + simbolo + "</ID>\n"; }
	void validacionSemantica (void);
	std::string generaCodigo (void) { return "\tpush " + simbolo + "\n"; }
};

#endif // IDENTIFICADOR_H_INCLUDED
