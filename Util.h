#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "Nodo.h"
#include "Defs.h"

void escribeEnArchivo(const std::string& nombreArchivo, const std::string& mensaje);
void error(void);
void escribeExitoEnArchivo(void);
std::string dameNombreTipo(int tipo);
std::string archivoASM(std::map<std::string, char>& variables, std::string codigo);
std::string generaCodigoVariables(std::map<std::string, char>& variables);
void borrarArboles(std::vector<Nodo*>& v);
void borraArbol(Nodo* raiz);
std::string archivoXML(std::vector<Nodo*> arboles);
void ejecutaCodigo(void);

#endif //UTIL_H_INCLUDED
