#ifndef SI_H_INCLUDED
#define SI_H_INCLUDED

#include "Nodo.h"
#include "ExpresionRelacional.h"
#include "Bloque.h"
#include "Otro.h"

class Si : public Nodo {
	ExpresionRelacional* expresion;
	Bloque* bloque;
	Otro* otro;
public:
	Si (ExpresionRelacional* expr, Bloque* bloque, Otro* otro)
	{
		expresion = expr;
		this->bloque = bloque;
		this->otro = otro;
	}
	std::string xml(void)
	{
		std::string codigo;

		codigo = "<SI>\n";
		codigo += expresion->xml();
		codigo += bloque->xml();

		if (otro) codigo += otro->xml();

		codigo += "</SI>\n";

		return codigo;
	}
	void validacionSemantica(void)
	{
		expresion->validacionSemantica();
		bloque->validacionSemantica();

		if (otro)
			otro->validacionSemantica();
	}
	std::string generaCodigo (void);
};

#endif /* end of include guard: SI_H_INCLUDED */
