#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>
#include <sstream>

namespace patch
{
	template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

class Nodo {
public:
	virtual std::string xml (void) 			{ return ""; }
	virtual ~Nodo(void) 					{}
	virtual void validacionSemantica(void) 	{}
	virtual std::string generaCodigo(void) 	{ return ""; }
	char dameTipo(void)						{ return tipo; }
	std::string sigEtiqueta (void)
	{
		return "Etiqueta" + patch::to_string(numEtiqueta++);
	}
protected:
	static int 	numEtiqueta;
	char		tipo;
};

#endif /* end of include guard: NODO_H_INCLUDED */
