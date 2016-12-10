#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include "Nodo.h"
#include "Excepciones.h"

class Expresion : public Nodo {
protected:
	Expresion* izquierdo;
	Expresion* derecho;
	std::string simbolo;
public:
	Expresion(void)
	{
		simbolo = "";
		izquierdo = derecho = NULL;
	}
	Expresion(Expresion* izq, Expresion* der)
	{
		simbolo = "";
		izquierdo = izq;
		derecho = der;
	}
	Expresion(Expresion* izq)
	{
		simbolo = "";
		izquierdo = izq;
		derecho = NULL;
	}
	std::string dameSimbolo(void) { return simbolo; }
	virtual std::string xml(void) { return ""; }
	virtual void validacionSemantica(void)
	{
		izquierdo->validacionSemantica();
		derecho->validacionSemantica();
		if (izquierdo->dameTipo() == 'i' && derecho->dameTipo() == 'i')
			tipo = 'i';
		else if (izquierdo->dameTipo() == 'r' && derecho->dameTipo() == 'r')
			tipo = 'r';
		else
		{
			tipo = 'e';
			throw ExcepcionSemantica("Combinacion de tipos no valida.");
		}
	}
	virtual std::string generaCodigo(void) 	{ return ""; }
	void fijaTipo(char tipo)				{ this->tipo = tipo; }
};

#endif /* end of include guard: EXPRESION_H_INCLUDED */
