#pragma once

#include "Definitions.h"
#include <iostream>
#include <set>

using VariableString = std::string;
using VariableSet = std::set<VariableString>;
// using Vars = std::pair<FreeVars, BoundVars>;

// class VarAnalysis
// {
// public:
//     VarAnalysis(Term term);
//     ~VarAnalysis();
//     Vars getResults();

// private:
//     FreeVars free_vars;
//     BoundVars bound_vars;
//     Term term;
// };

class VariableAnalysis
{
public:
    virtual VariableSet execute(Term term) = 0;
};

class FreeVariableAnalysis : VariableAnalysis
{
public:
    VariableSet execute();
};

class BoundVariableAnalysis : VariableAnalysis
{
public:
    VariableSet execute();
};


