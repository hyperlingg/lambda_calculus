#include "definitions.h"

/* term constructors */
Term::~Term(){};

Variable::Variable(std::string name) : name(name) {}
Variable::~Variable(){};

std::string Variable::getName()
{
    return name;
}

Application::Application(Term lterm, Term rterm) : lterm(lterm), rterm(rterm) {}

Application::~Application(){};

Term Application::getLTerm()
{
    return lterm;
}

Abstraction::Abstraction(Variable var, Term *rterm) : var(var), rterm(rterm) {}
Abstraction::~Abstraction(){};


