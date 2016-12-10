#ifndef EXPRESION_RELACIONAL_H_INCLUDED
#define EXPRESION_RELACIONAL_H_INCLUDED

#include "Expresion.h"

class ExpresionRelacional : public Expresion {
public:
	ExpresionRelacional (Expresion* izq, Expresion* der, std::string sim)
		:	Expresion(izq, der)
	{
		simbolo = sim;
	}
	std::string xml (void)
	{
		return "<EXPRESION value=\"" + deduceSimbolo() + "\">\n"
				+ izquierdo->xml()
				+ derecho->xml()
				+ "</EXPRESION>\n";
	}
	std::string generaCodigo (void)
	{
		return izquierdo->generaCodigo()
				+ derecho->generaCodigo()
				+ "\tpop ebx\n"
				+ "\tpop eax\n"
				+ "\tcmp eax, ebx\n";
	}
	std::string opEnASM(void)
	{
		std::string operacion = "\t";

		if 		(simbolo == ">"	) 	operacion += "jg "	;
		else if (simbolo == ">=") 	operacion += "jge "	;
		else if (simbolo == "<"	) 	operacion += "jl "	;
		else if (simbolo == "<=") 	operacion += "jle "	;
		else if (simbolo == "==") 	operacion += "je "	;
		else 						operacion += "jne "	;

		return operacion;
	}
	std::string opEnASMNegado(void)
	{
		std::string operacion = "\t";

		if 		(simbolo == ">"	) 	operacion += "jng "	;
		else if (simbolo == ">=") 	operacion += "jnge ";
		else if (simbolo == "<"	) 	operacion += "jnl "	;
		else if (simbolo == "<=") 	operacion += "jnle ";
		else if (simbolo == "==") 	operacion += "jne "	;
		else 						operacion += "je "	;

		return operacion;
	}
private:
	std::string deduceSimbolo (void)
	{
		if 		(simbolo == ">"	) 	return "&gt;"	;
		else if (simbolo == ">=") 	return "&gt;="	;
		else if (simbolo == "<"	) 	return "&lt;"	;
		else if (simbolo == "<=") 	return "&lt;="	;
		else 						return simbolo	;
	}
};

#endif /* end of include guard: EXPRESION_RELACIONAL_H_INCLUDED */
