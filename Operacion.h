#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED

#include "Expresion.h"

class Operacion : public Expresion {
public:
	Operacion (Expresion* izq, Expresion* der, std::string sim)
		:	Expresion(izq, der)
	{
		simbolo = sim;
	}

	std::string xml(void)
	{
		return (simbolo == "+" || simbolo == "-") ?
		"<SUMA value=\"" + simbolo + "\">\n"
		+ izquierdo->xml()
		+ derecho->xml()
		+ "</SUMA>\n"
		:
		"<MULT value=\"" + simbolo + "\">\n"
		+ izquierdo->xml()
		+ derecho->xml()
		+ "</MULT>\n";
	}
	std::string generaCodigo (void);
};

#endif // OPERACION_H_INCLUDED
