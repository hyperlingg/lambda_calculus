#include "definitions.h"

/* term constructors */
Term::~Term(){};

Variable::Variable(std::string name) : name(name) {}
Variable::~Variable(){};

Application::Application(Term lterm, Term rterm) : lterm(lterm), rterm(rterm) {}
Application::~Application(){};

Abstraction::Abstraction(Variable var, Term rterm) : var(var), rterm(rterm) {}
Abstraction::~Abstraction(){};