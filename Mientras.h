#ifndef MIENTRAS_H_INCLUDED
#define MIENTRAS_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ExpresionRelacional.h"
#include "Bloque.h"

class Mientras : public Nodo {
	ExpresionRelacional* expresion;
	Bloque* bloque;
public:
	Mientras (ExpresionRelacional* expr, Bloque* bloque)
	{
		expresion = expr;
		this->bloque = bloque;
	}
	std::string xml(void)
	{
		return "<MIENTRAS>\n" + expresion->xml() + bloque->xml() + "</MIENTRAS>\n";
	}
	void validacionSemantica(void)
	{
		expresion->validacionSemantica();
		bloque->validacionSemantica();
	}
	std::string generaCodigo (void);
};

#endif /* end of include guard: MIENTRAS_H_INCLUDED */
