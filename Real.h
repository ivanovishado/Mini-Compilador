#ifndef REAL_H_INCLUDED
#define REAL_H_INCLUDED

class Real : public Expresion {
public:
	Real (std::string sim) { simbolo = sim; }
	std::string xml(void) { return "<REAL>" + simbolo + "</REAL>\n"; }
	void validacionSemantica(void) { tipo = 'r'; }
	std::string generaCodigo(void) { return "\tpush " + simbolo + "\n"; }
};

#endif // REAL_H_INCLUDED
