#include "Si.h"

std::string Si::generaCodigo (void)
{
	std::string codigo, other, fin;

	other = sigEtiqueta();
	fin = sigEtiqueta();

	codigo = expresion->generaCodigo();
	codigo += expresion->opEnASMNegado();
	if (otro)
	{
		codigo += other + "\n";
		codigo += bloque->generaCodigo();
		codigo += "\tjmp " + fin + "\n";
		codigo += other + ":\n";
		codigo += otro->generaCodigo();
	}
	else
	{
		codigo += fin + "\n";
		codigo += bloque->generaCodigo();
	}

	codigo += fin + ":\n";

	return codigo;
}
