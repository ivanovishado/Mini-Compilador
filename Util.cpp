#include "Util.h"

std::string archivoASM(std::map<std::string, char>& variables, std::string codigo)
{
	return std::string(".386\n")
			+ ".model flat, stdcall\n"
			+ "option casemap:none ;labels are case-sensitive now\n\n"
			+ "  include \\masm32\\macros\\macros.asm\n"
			+ "  include \\masm32\\include\\masm32.inc\n"
			+ "  include \\masm32\\include\\kernel32.inc\n\n"
			+ "  includelib \\masm32\\lib\\masm32.lib\n"
			+ "  includelib \\masm32\\lib\\kernel32.lib\n\n"
			+ ".data\n"
			+ generaCodigoVariables(variables)
			+ ".data?\n\n"
			+ ".code\n"
			+ "inicio:\n"
			+ codigo
			+ "\texit\n"
			+ "end inicio\n";
}

std::string generaCodigoVariables(std::map<std::string, char>& variables)
{
	std::string codigo;

	for (auto const& variable : variables)
		codigo += "\t" + variable.first + " dword 0\n";

	return codigo;
}

std::string archivoXML(std::vector<Nodo*> arboles)
{
	std::string xml;
	xml = "<PROGRAMA>\n";

	for (auto const& arbol : arboles) xml += arbol->xml();

	xml += "</PROGRAMA\n";

	return xml;
}

void borrarArboles(std::vector<Nodo*>& arboles)
{
	for (auto const& arbol : arboles) borraArbol(arbol);
}

void borraArbol(Nodo* raiz)
{
	/*
	if (raiz->dameIzquierdo() != NULL) borraArbol(raiz->dameIzquierdo());
	if (raiz->dameDerecho() != NULL) borraArbol(raiz->dameDerecho());
	delete raiz;
	*/
}

void escribeEnArchivo(const std::string& nombreArchivo, const std::string& mensaje)
{
	std::ofstream ofs(nombreArchivo, std::ios::out | std::ios::trunc);
	ofs << mensaje;
	ofs.close();
}

void error(void)
{
	escribeEnArchivo(NOMBRE_ARCHIVO_SALIDA, MENSAJE_ERROR);

	exit(EXIT_FAILURE);
}

void ejecutaCodigo (void)
{
	// system("\\masm32\\bin\\ml argumentos salida.asm");
	// system("\\masm32\\bin\\link argumentos salida");
	// system("salida")
}

void escribeExitoEnArchivo(void)
{
	escribeEnArchivo(NOMBRE_ARCHIVO_SALIDA, MENSAJE_EXITO);
}

std::string dameNombreTipo(int tipo)
{
	switch (tipo)
	{
	case INICIAL: 			return "INICIAL";
	case OP_ADIC: 			return "Operador de Adicion";
	case OP_MULT: 			return "Operador de Multiplicacion";
	case OP_RELACIONAL: 	return "Operador relacional";
	case DELIMITADOR: 		return "Delimitador";
	case PARENTESIS: 		return "Parentesis";
	case OP_LOGICO: 		return "Operador logico";
	case OP_ASIGNACION: 	return "Operador de asignacion";
	case AND: 				return "AND";
	case OR: 				return "OR";
	case CADENA: 			return "Cadena";
	case IDENTIFICADOR: 	return "Identificador";
	case ENTERO: 			return "Entero";
	case REAL: 				return "Real";
	case MIENTRAS:			return "Mientras";
	case SI:				return "Si";
	case OTRO:				return "Otro";
	case FIN: 				return "Fin";
	case FINAL:				return "Final";
	default: 				return "Tipo no definido";
	}
}
