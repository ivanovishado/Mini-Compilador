#include "Mientras.h"

std::string Mientras::generaCodigo(void)
{
	std::string codigo, inicio, fin;

	inicio = sigEtiqueta();
	fin = sigEtiqueta();

	codigo = inicio + ":\n";
	codigo += expresion->generaCodigo();
	codigo += expresion->opEnASMNegado() + fin + "\n";
	codigo += bloque->generaCodigo();
	codigo += "\tjmp " + inicio + "\n";
	codigo += fin + ":\n";

	return codigo;
}
