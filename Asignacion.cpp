#include "Asignacion.h"

std::map<std::string, char> variables;

void Asignacion::validacionSemantica (void)
{
	std::string sim = id->dameSimbolo();

	expresion->validacionSemantica();
	if (variables.find(sim) == variables.end())
	{
		variables.insert(std::pair<std::string, char> (sim, expresion->dameTipo()));
		tipo = 'v';
	}
}
