#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED

#include <vector>
#include <memory>
#include "Nodo.h"

class Bloque : public Nodo {
public:
	Bloque (void) {}
	std::string xml(void)
	{
		std::string codigo;

		codigo = "<BLOQUE>\n";

		for (auto const& instruccion : instrucciones) if (instruccion) codigo += instruccion->xml();

		codigo += "</BLOQUE>\n";

		return codigo;
	}
	void validacionSemantica(void)
	{
		for (auto const& instruccion : instrucciones)
			if (instruccion) instruccion->validacionSemantica();
	}
	std::string generaCodigo(void)
	{
		std::string codigo = "";

		for (auto const& instruccion : instrucciones)
		{
			if (instruccion)
				codigo += instruccion->generaCodigo();
		}

		return codigo;
	}
	void agregaInstruccion (Nodo* ins)
	{
		std::shared_ptr<Nodo> instruccion(ins);
		instrucciones.push_back(instruccion);
	}
protected:
	std::vector<std::shared_ptr<Nodo>> instrucciones;
};

#endif /* end of include guard: BLOQUE_H_INCLUDED */
