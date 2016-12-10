#ifndef DOWHILE_H_INCLUDED
#define DOWHILE_H_INCLUDED

class DoWhile : public Nodo {
public:
	DoWhile(Nodo* bloque, Nodo* expr)
	{
		simbolo = "";
		izquierdo = bloque;
		derecho = expr;
	}
	std::string generaCodigo(void)
	{
		std::string codigo, inicioDo;

		inicioDo = sigEtiqueta();
		codigo = inicioDo + ":\n";
		codigo += izquierdo->generaCodigo();
		codigo += derecho->generaCodigo();
		codigo += derecho->opEnASM() + inicioDo + "\n";

		return codigo;
	}
};

#endif /* end of include guard: DOWHILE_H_INCLUDED */
