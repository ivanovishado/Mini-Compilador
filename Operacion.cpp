#include "Operacion.h"

std::string Operacion::generaCodigo(void)
{
	std::string codigo;

	codigo = izquierdo->generaCodigo();
	codigo += derecho->generaCodigo();
	codigo += "\tpop ebx\n\tpop eax\n\t";

	if (simbolo == "+") 		codigo += "add eax, ebx";
	else if (simbolo == "-") 	codigo += "sub eax, ebx";
	else if (simbolo == "*") 	codigo += "imul ebx";
	else
	{
		codigo += std::string("mov edx, 0\n")
				+ "\tidiv ebx";
	}

	codigo += "\n\tpush eax\n";

	return codigo;
}
