#include "Lexico.h"

void Lexico::sigSimbolo(void)
{
	estado = INICIAL;
	simbolo = "";
	continua = true;

	while(continua)
	{
		do
		{
			c = entrada[indiceCaracterRevisado++];
		}while(c == ' ' || c == '\t');

		if (c == '\0') c = '$';

		// printf("Char= %d\n", c);

		// std::cout << "Char= " << c << std::endl;

		switch(estado)
		{
		case INICIAL:
			if (c == 'm')
				sigEstado(MIENTRAS);
			else if (c == 's')
				sigEstado(SI);
			else if (c == 'o')
				sigEstado(OTRO);
			else if (c == 'f')
				sigEstado(FIN);
			else if (esOpAdic(c))
				aceptacion(OP_ADIC);
			else if (esOpMult(c))
				aceptacion(OP_MULT);
			else if (esDelimitador(c))
				aceptacion(DELIMITADOR);
			else if (esParentesis(c))
				aceptacion(PARENTESIS);
			else if (esOpLogico(c))
				sigEstado(OP_LOGICO);
			else if (esOpAsignacion(c))
				sigEstado(OP_ASIGNACION);
			else if (esOpRelacional(c))
				sigEstado(OP_RELACIONAL);
			else if (c == '\"')
				sigEstado(CADENA);
			else if (esCaracterPuntuacion(c) || isalpha(c))
				sigEstado(IDENTIFICADOR);
			else if (isdigit(c))
				sigEstado(ENTERO);
			else if (c == '&')
				sigEstado(AND);
			else if (c == '|')
				sigEstado(OR);
			else if (c == '$')
				aceptacion(FINAL);
			else
				throw ExcepcionLexica();
			break;

		case IDENTIFICADOR:
			if (isalpha(c) || isdigit(c) || esCaracterPuntuacion(c))
				sigEstado(IDENTIFICADOR);
			else if (esFijo(c))
			{
				aceptacion(IDENTIFICADOR);
				retrocedeCaracter();
			}
			else
				throw ExcepcionLexica();
			break;

		case ENTERO:
			if (isdigit(c))
				sigEstado(ENTERO);
			else if (c == '.')
				sigEstado(REAL);
			else if (esFijo(c))
			{
				aceptacion(ENTERO);
				retrocedeCaracter();
			}
			else
				throw ExcepcionLexica();
			break;

		case REAL:
			if (isdigit(c))
				sigEstado(REAL);
			else if (esFijo(c))
			{
				aceptacion(REAL);
				retrocedeCaracter();
			}
			else
				throw ExcepcionLexica();
			break;

		case CADENA: (c == '\"') ? aceptacion(CADENA) : sigEstado(CADENA); break;

		case MIENTRAS:
			if (c == 'i')
			{
				aceptacionTemporal();
				if (c == 'e')
				{
					aceptacionTemporal();
					if (c == 'n')
					{
						aceptacionTemporal();
						if (c == 't')
						{
							aceptacionTemporal();
							if (c == 'r')
							{
								aceptacionTemporal();
								if (c == 'a')
								{
									aceptacionTemporal();
									if (c == 's') aceptacion(MIENTRAS);
									else
									{
										sigEstado(IDENTIFICADOR);
										retrocedeCaracter();
									}
								}
								else
								{
									sigEstado(IDENTIFICADOR);
									retrocedeCaracter();
								}
							}
							else
							{
								sigEstado(IDENTIFICADOR);
								retrocedeCaracter();
							}
						}
						else
						{
							sigEstado(IDENTIFICADOR);
							retrocedeCaracter();
						}
					}
					else
					{
						sigEstado(IDENTIFICADOR);
						retrocedeCaracter();
					}
				}
				else
				{
					sigEstado(IDENTIFICADOR);
					retrocedeCaracter();
				}
			}
			else
			{
				sigEstado(IDENTIFICADOR);
				retrocedeCaracter();
			}
			break;

		case SI:
			if (c == 'i') aceptacion(SI);
			else
			{
				sigEstado(IDENTIFICADOR);
				retrocedeCaracter();
			}
			break;

		case OTRO:
			if (c == 't')
			{
				aceptacionTemporal();
				if (c == 'r')
				{
					aceptacionTemporal();
					if (c == 'o') aceptacion(OTRO);
					else
					{
						sigEstado(IDENTIFICADOR);
						retrocedeCaracter();
					}
				}
				else
				{
					sigEstado(IDENTIFICADOR);
					retrocedeCaracter();
				}
			}
			else
			{
				sigEstado(IDENTIFICADOR);
				retrocedeCaracter();
			}
			break;

		case FIN:
			if (c == 'i')
			{
				aceptacionTemporal();
				if (c == 'n')
				{
					aceptacion(FIN);
				}
				else
				{
					sigEstado(IDENTIFICADOR);
					retrocedeCaracter();
				}
			}
			else
			{
				sigEstado(IDENTIFICADOR);
				retrocedeCaracter();
			}
			break;

		case OP_LOGICO:
			if (esOpAsignacion(c))
				aceptacion(OP_RELACIONAL);
			else
			{
				aceptacion(OP_LOGICO);
				retrocedeCaracter();
			}
			break;

		case OP_ASIGNACION:
			if (esOpAsignacion(c))
				aceptacion(OP_RELACIONAL);
			else
			{
				aceptacion(OP_ASIGNACION);
				retrocedeCaracter();
			}
			break;

		case OP_RELACIONAL:
			if (esOpAsignacion(c))
				aceptacion(OP_RELACIONAL);
			else
			{
				aceptacion(OP_RELACIONAL);
				retrocedeCaracter();
			}
			break;

		case AND: (c == '&') ? aceptacion(AND) : throw ExcepcionLexica(); break;
		case OR: (c == '|') ? aceptacion(OR) : throw ExcepcionLexica(); break;
		}
	}
}
