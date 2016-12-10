#ifndef OTRO_H_INCLUDED
#define OTRO_H_INCLUDED

class Otro : public Nodo {
public:
	Otro (void)	{}
	std::string xml(void)
	{
		std::string codigo;

		codigo = "<OTRO>\n";

		for (auto const& instruccion : instrucciones) if (instruccion) codigo += instruccion->xml();

		codigo += "</OTRO>\n";

		return codigo;
	}
	void validacionSemantica(void)
	{
		for (auto const& instruccion : instrucciones)
			if (instruccion) instruccion->validacionSemantica();
	}
	std::string generaCodigo(void)
	{
		std::string codigo;

		for(auto const& instruccion : instrucciones)
			if (instruccion) codigo += instruccion->generaCodigo();

		return codigo;
	}
	void agregaInstruccion (Nodo* ins)
	{
		std::shared_ptr<Nodo> instruccion(ins);
		instrucciones.push_back(instruccion);
	}
protected:
	std::vector<std::shared_ptr<Nodo>> instrucciones;
};

#endif /* end of include guard: OTRO_H_INCLUDED */
