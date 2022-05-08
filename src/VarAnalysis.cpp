#include "../include/VarAnalysis.h"
#include <algorithm>

SymbolicExpression VariableAnalysis::getSubExpression(SymbolicExpression symbolic_expression, int left_index, int right_index)
{
    SymbolicExpression sub_expression;
    int delta = symbolic_expression.at(left_index).getLocation().first;
    Symbol temp_symbol;

    for (int i = left_index; i <= right_index; i++)
    {
        temp_symbol = symbolic_expression.at(i);
        temp_symbol.shiftLocation(delta);
        sub_expression.push_back(temp_symbol);
    }

    return sub_expression;
}

FreeAndBoundVariables VariableAnalysis::pairwise_set_merge(FreeAndBoundVariables left_term_variables, FreeAndBoundVariables right_term_variables)
{
    std::set<char> left_term_set, right_term_set;

    std::merge(left_term_variables.first.begin(), left_term_variables.first.end(),
               right_term_variables.first.begin(), right_term_variables.first.end(),
               std::inserter(left_term_set, left_term_set.begin()));

    std::merge(left_term_variables.second.begin(), left_term_variables.second.end(),
               right_term_variables.second.begin(), right_term_variables.second.end(),
               std::inserter(right_term_set, right_term_set.begin()));

    return {left_term_set, right_term_set};
}

FreeAndBoundVariables VariableAnalysis::freeVariableAnalysis(SymbolicExpression symbolic_expression, FreeAndBoundVariables variables)
{
    if (symbolic_expression.empty())
    {
        return {variables.first, variables.second};
    }
    else
    {
        SymbolicExpression left_term, right_term;
        Symbol first_symbol = symbolic_expression.at(0);
        Location second_symbol_location = {};

        int open_left, close_left;
        int open_right, close_right;
        char var;

        switch (first_symbol.getSymbolType())
        {
        case OpenApplication:
            if (symbolic_expression.size() < 2)
            {
                return {{}, {}};
            }

            second_symbol_location = symbolic_expression.at(1).getLocation();

            open_left = second_symbol_location.first;
            close_left = second_symbol_location.second;

            open_right = close_left + 1;
            close_right = symbolic_expression.at(open_right).getLocation().second;

            left_term = getSubExpression(symbolic_expression, open_left, close_left);

            right_term = getSubExpression(symbolic_expression, open_right, close_right);

            variables = pairwise_set_merge(freeVariableAnalysis(left_term, variables), freeVariableAnalysis(right_term, variables));
            break;

        case OpenAbstraction:
            var = symbolic_expression.at(1).getAsString().at(0);

            variables.second.insert(var);
            variables.first.erase(var);

            open_right = symbolic_expression.at(2).getLocation().first;
            close_right = symbolic_expression.at(2).getLocation().second;
            right_term = getSubExpression(symbolic_expression, open_right, close_right);

            variables = freeVariableAnalysis(right_term, variables);
            break;

        case Variable:
            var = first_symbol.getAsString().at(0);

            if (variables.second.find(var) == variables.second.end())
            {
                variables.first.insert(var);
            }

            break;
        default:
            break;
        }
    }
    return variables;
}

void VariableAnalysis::execute(Term term)
{
    auto symbolic_expression = term.getSymbolicExpression();

    auto free_and_bound_variables = freeVariableAnalysis(symbolic_expression, {});
    *free_variables = free_and_bound_variables.first;
    *bound_variables = free_and_bound_variables.second;
}

VariableSet *VariableAnalysis::getFreeVariables()
{
    return free_variables;
}

VariableSet *VariableAnalysis::getBoundVariables()
{
    return bound_variables;
}
