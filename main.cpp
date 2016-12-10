/*
 * @author Ivan Fernando Galaviz Mendoza
 * Traductores de Lenguajes II
 * Proyecto 5
 */

#include <cctype>
#include <utility>
#include "Sintactico.h"

extern std::map<std::string, char> variables;

int main(void)
{
	std::ifstream ifs(NOMBRE_ARCHIVO_ENTRADA, std::ios::in);
	std::vector<Nodo*> arboles;
	std::string codigoASM, salidaXML;

	Sintactico sintactico(ifs);

	try
	{
		sintactico.analiza(arboles);
		for (auto const& arbol : arboles)
			arbol->validacionSemantica();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		error();
	}

	for (auto const& arbol : arboles)
		codigoASM += arbol->generaCodigo();

	escribeEnArchivo(NOMBRE_ARCHIVO_SALIDA, archivoXML(arboles));

	escribeEnArchivo(NOMBRE_ARCHIVO_SALIDA_ASM, archivoASM(variables, codigoASM));

	ejecutaCodigo();

	return EXIT_SUCCESS;
}
