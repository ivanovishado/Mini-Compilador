#ifndef SIGNO_H_INCLUDED
#define SIGNO_H_INCLUDED

class Signo : public Expresion {
public:
	Signo (Expresion* izq, std::string sim)
		:	Expresion(izq)
	{
		simbolo = sim;
	}
	std::string xml(void)
	{
		return "<SIGNO value=\""
				+ simbolo + "\">\n"
				+ izquierdo->xml()
				+ "</SIGNO>\n";
	}
	void validacionSemantica(void)
	{
		izquierdo->validacionSemantica();
		tipo = izquierdo->dameTipo();
	}
	std::string generaCodigo(void)
	{
		std::string codigo;

		codigo = izquierdo->generaCodigo();

		if (simbolo == "-")
		{
			codigo += std::string("\tpop eax\n")
					+ "\tneg eax\n"
					+ "\tpush eax\n";
		}

		return codigo;
	}
};

#endif // SIGNO_H_INCLUDED
