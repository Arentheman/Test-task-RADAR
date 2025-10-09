#pragma once
#include "CSVTable.h"

class FormulaEvaluator {
public:
    static double evaluate(const string& formula, const CSVTable& table);
};
