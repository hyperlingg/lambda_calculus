/* inductive definition of lambda terms */
/* author: jonas lingg */

#include <string>

/* concrete class serving as base type */
class Term
{
public:
    Term(){};
    ~Term();
};

/* every named variable is a term */
class Variable : public Term
{
private:
    std::string name;

public:
    Variable(std::string name);
    ~Variable();
};

/* if lterm and rterm are terms, then Application(lterm, rterm) is a term */
/* e.g. for terms M,N => (MN) is a term */
class Application : public Term
{
private:
    Term lterm;
    Term rterm;

public:
    Application(Term M, Term N);
    ~Application();
};

/* If var is a variable and rterm a term, then Abstraction(var,rterm) is a term */
/* e.g. for variable x and term M => (lambda x.M) is a term */
class Abstraction : public Term
{
private:
    Variable var;
    Term rterm;

public:
    Abstraction(Variable var, Term rterm);
    ~Abstraction();
};
