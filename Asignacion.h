#ifndef ASIGNACION_H_INCLUDED
#define ASIGNACION_H_INCLUDED

#include <map>
#include <vector>
#include "Nodo.h"
#include "Expresion.h"
#include "Identificador.h"

class Asignacion : public Nodo {
public:
	Asignacion(Identificador* id, Expresion* expresion, bool seImprime)
	{
		this->id = id;
		this->expresion = expresion;
		this->seImprime = seImprime;
	}
	std::string xml(void)
	{
		return "<ASIGNACION>\n" + id->xml() + expresion->xml() + "</ASIGNACION>\n";
	}
	void validacionSemantica(void);
	std::string generaCodigo(void)
	{
		std::string codigo, sim;

		sim = id->dameSimbolo();

		codigo = expresion->generaCodigo();
		codigo += "\tpop " + sim + "\n";
		if (seImprime)
		{
			codigo += "\tprint str$(" + sim + ")\n"
					+ "\tprint chr$(10)\n";
		}
		return codigo;
	}
private:
	bool seImprime;
	Identificador* id;
	Expresion* expresion;
};

#endif // ASIGNACION_H_INCLUDED
