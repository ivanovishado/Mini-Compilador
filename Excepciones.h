#ifndef EXCEPCION_SEMANTICA_H_INCLUDED
#define EXCEPCION_SEMANTICA_H_INCLUDED

#include <exception>

class ExcepcionLexica : public std::exception {
	virtual const char* what() const throw()
	{
		return "Ha ocurrido un error lexico.";
	}
};

class ExcepcionSintactica : public std::exception {
	virtual const char* what() const throw()
	{
		return "Ha ocurrido un error sintactico.";
	}
};

class ExcepcionSemantica : public std::exception {
public:
	explicit ExcepcionSemantica(const std::string& msg):
		mensaje("ERROR SEMANTICO: " + msg)
		{}
	virtual const char* what() const throw()
	{
		return mensaje.c_str();
	}
private:
	std::string mensaje;
};

#endif /* end of include guard: EXCEPCION_SEMANTICA_H_INCLUDED */
