#pragma once

#include "Definitions.h"
#include <iostream>
#include <set>

using FreeVars = std::set<char>;
using BoundVars = std::set<char>;
using Vars = std::pair<FreeVars, BoundVars>;

class VarAnalysis
{
private:
    FreeVars free_vars;
    BoundVars bound_vars;
    Term term;

public:
    VarAnalysis(Term term);
    ~VarAnalysis();
    Vars getResults();
};
