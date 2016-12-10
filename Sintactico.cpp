#include "Sintactico.h"

int Nodo::numEtiqueta = 0;

void Sintactico::analiza(std::vector<Nodo*>& v)
{
	Nodo* aux;

	if (lexico.dameTipo() == FINAL)
		return;

	aux = sentencias();

	if (aux)
		v.push_back(aux);

	analiza(v);
}

Nodo* Sintactico::sentencias(void)
{
	if (lexico.dameSimbolo() == "\n")
	{
		lexico.sigSimbolo();
		return NULL;
	}

	switch (lexico.dameTipo())
	{
	case IDENTIFICADOR:	return generaAsignacion();
	case MIENTRAS:		return generaMientras();
	case SI:			return generaSi();
	default: 			throw ExcepcionSintactica();
	}
}

Asignacion* Sintactico::generaAsignacion(void)
{
	Expresion* expr;
	bool seImprime;
	Identificador* id = new Identificador (lexico.dameSimbolo());

	lexico.sigSimbolo();
	comprueba(OP_ASIGNACION);
	expr = expresion();
	if (lexico.dameSimbolo() == ";")
	{
		lexico.sigSimbolo();
		seImprime = false;
	}
	else
	{
		comprueba("\n");
		seImprime = true;
	}

	return new Asignacion(id, expr, seImprime);
}

Mientras* Sintactico::generaMientras(void)
{
	ExpresionRelacional* exprRel;
	Bloque* bloque = new Bloque();

	lexico.sigSimbolo();
	exprRel = expresionRelacional();
	comprueba("\n");
	while (lexico.dameTipo() != FIN)
		bloque->agregaInstruccion(sentencias());
	comprueba(FIN);

	return new Mientras(exprRel, bloque);
}

Si* Sintactico::generaSi(void)
{
	ExpresionRelacional* exprRel;
	Otro* other;
	int tipo;
	Bloque* bloque = new Bloque();

	lexico.sigSimbolo();
	exprRel = expresionRelacional();
	comprueba("\n");
	tipo = lexico.dameTipo();
	while (tipo != OTRO && tipo != FIN)
	{
		bloque->agregaInstruccion(sentencias());
		tipo = lexico.dameTipo();
	}
	other = otro();
	comprueba(FIN);

	return new Si(exprRel, bloque, other);
}

Expresion* Sintactico::expresion(void)
{
	Expresion* aux = multiplicacion();
	std::string sim = lexico.dameSimbolo();

	while (sim == "+" || sim == "-")
	{
		lexico.sigSimbolo();
		aux = new Operacion(aux, multiplicacion(), sim);
		sim = lexico.dameSimbolo();
	}

	return aux;
}

Expresion* Sintactico::multiplicacion(void)
{
	Expresion* aux = factor();
	std::string sim = lexico.dameSimbolo();

	while (sim == "*" || sim == "/")
	{
		lexico.sigSimbolo();
		aux = new Operacion(aux, factor(), sim);
		sim = lexico.dameSimbolo();
	}

	return aux;
}

Expresion* Sintactico::factor(void)
{
	Expresion* aux;
	std::string sim = lexico.dameSimbolo();

	if (sim == "+" || sim == "-")
	{
		lexico.sigSimbolo();
		aux = new Signo(factor(), sim);
	}
	else if (sim == "(")
	{
		lexico.sigSimbolo();
		aux = expresion();
		comprueba(")");
	}
	else
	{
		switch (lexico.dameTipo())
		{
		case IDENTIFICADOR: aux = new Identificador(lexico.dameSimbolo()); 	break;
		case ENTERO: 		aux = new Entero(lexico.dameSimbolo()); 		break;
		case REAL: 			aux = new Real(lexico.dameSimbolo()); 			break;
		default: 			throw ExcepcionSintactica();
		}
		lexico.sigSimbolo();
	}

	return aux;
}

ExpresionRelacional* Sintactico::expresionRelacional(void)
{
	Expresion *expresionIzq, *expresionDer;
	std::string sim;

	expresionIzq = expresion();
	sim = lexico.dameSimbolo();
	comprueba(OP_RELACIONAL);
	expresionDer = expresion();
	// otraExpresion();

	return new ExpresionRelacional(expresionIzq, expresionDer, sim);
}

ExpresionRelacional* Sintactico::otraExpresion(void)
{
	switch (lexico.dameTipo())
	{
	case AND:
	case OR:
		lexico.sigSimbolo();
		return expresionRelacional();
	default: return NULL;
	}
}

Otro* Sintactico::otro(void)
{
	Otro* aux = NULL;

	if (lexico.dameTipo() == OTRO)
	{
		aux = new Otro();
		lexico.sigSimbolo();
		while (lexico.dameTipo() != FIN) aux->agregaInstruccion(sentencias());
	}

	return aux;
}
