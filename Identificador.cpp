#include "Identificador.h"

extern std::map<std::string, char> variables;

void Identificador::validacionSemantica (void)
{
	auto posVariable = variables.find(simbolo);
	if (posVariable == variables.end())
		throw ExcepcionSemantica("Variable \'" + simbolo + "\' no definida todavia.");
	else
		tipo = (*posVariable).second;
}
