#ifndef SINTACTICO_H_INCLUDED
#define SINTACTICO_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Lexico.h"
#include "Asignacion.h"
#include "Bloque.h"
#include "Entero.h"
#include "Expresion.h"
#include "ExpresionRelacional.h"
#include "Identificador.h"
#include "Mientras.h"
#include "Operacion.h"
#include "Otro.h"
#include "Real.h"
#include "Si.h"
#include "Signo.h"

class Sintactico
{
public:
	Sintactico(std::ifstream& ifs)
	{
		lexico.asignaEntrada(ifs);
		lexico.sigSimbolo();
	}

	void analiza(std::vector<Nodo*>& v);
private:
	Lexico lexico;

	void comprueba(std::string simbolo)
	{
		(lexico.dameSimbolo() == simbolo) ? lexico.sigSimbolo() : throw ExcepcionSintactica();
	}

	void comprueba(int tipo)
	{
		(lexico.dameTipo() == tipo) ? lexico.sigSimbolo() : throw ExcepcionSintactica();
	}

	Asignacion* generaAsignacion(void);

	Mientras* generaMientras(void);

	Si* generaSi(void);

	Expresion* expresion(void);

	Expresion* multiplicacion(void);

	Expresion* factor(void);

	Nodo* sentencias(void);

	ExpresionRelacional* expresionRelacional(void);

	ExpresionRelacional* otraExpresion(void);

	Otro* otro(void);
};

#endif //SINTACTICO_H_INCLUDED
