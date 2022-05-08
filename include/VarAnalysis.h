#pragma once

#include "Definitions.h"
#include <iostream>
#include <memory>
#include <set>

using VariableChar = char;
using VariableSet = std::set<VariableChar>;
using FreeAndBoundVariables = std::pair<VariableSet, VariableSet>;

class VariableAnalysis
{
public:
    VariableAnalysis() : free_variables(nullptr), bound_variables(nullptr){};
    ~VariableAnalysis()
    {
        delete free_variables;
        delete bound_variables;
    }

    void execute(Term term);
    VariableSet *getFreeVariables();
    VariableSet *getBoundVariables();

private:
    VariableSet *free_variables;
    VariableSet *bound_variables;
    FreeAndBoundVariables freeVariableAnalysis(SymbolicExpression symbolic_expression, FreeAndBoundVariables variables);
    FreeAndBoundVariables pairwise_set_merge(FreeAndBoundVariables left_term_variables, FreeAndBoundVariables right_term_variables);
    SymbolicExpression getSubExpression(SymbolicExpression symbolic_expression, int left_index, int right_index);
};
