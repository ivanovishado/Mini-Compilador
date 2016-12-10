#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <sstream>
#include <iostream>
#include "Util.h"
#include "Excepciones.h"

class Lexico
{
public:
	Lexico(void) { indiceCaracterRevisado = 0; }

	void sigSimbolo (void);

	void asignaEntrada (std::ifstream& ifs)
	{
		std::stringstream ss;
		ss << ifs.rdbuf();
		ifs.close();

		entrada = ss.str();
	}

	std::string dameSimbolo (void) { return simbolo; }

	int dameTipo (void) { return tipo; }

	bool fin (void) { return (indiceCaracterRevisado >= entrada.size()); }

private:
	std::size_t indiceCaracterRevisado;
	std::string entrada;
	std::string simbolo;
	bool continua;
	int estado;
	int tipo;
	char c;

	void sigEstado(int edo)
	{
		estado = edo;
		simbolo += c;
	}
	void aceptacion(int edo)
	{
		sigEstado(edo);
		tipo = edo;
		continua = false;
	}

	bool esDelimitador(char c) 			{ return (c == ';' || c == '\n'); }
	bool esOpRelacional(char c) 		{ return (c == '>' || c == '<'); }
	bool esOpAdic(char c) 				{ return (c == '+' || c == '-'); }
	bool esOpMult(char c) 				{ return (c == '*' || c == '/'); }
	bool esParentesis(char c) 			{ return (c == '(' || c == ')'); }
	bool esCaracterPuntuacion(char c) 	{ return (c == '_'); }
	bool esOpAsignacion(char c) 		{ return (c == '='); }
	bool esOpLogico(char c) 			{ return (c == '!'); }
	bool esCaracter(char c)				{ return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)); }
	bool esFijo(char c)
	{
		return (esOpAdic(c) || esOpMult(c) || esOpAsignacion(c) || esOpRelacional(c)
				|| esOpLogico(c) || esDelimitador(c) || esParentesis(c) || esCaracterPuntuacion(c));
	}

	void aceptacionTemporal (void)
	{
		simbolo += c;
		c = entrada[indiceCaracterRevisado++];
	}
	void retrocedeCaracter (void)
	{
		indiceCaracterRevisado--;
		simbolo.pop_back();
	}
};

#endif //LEXICO_H_INCLUDED
