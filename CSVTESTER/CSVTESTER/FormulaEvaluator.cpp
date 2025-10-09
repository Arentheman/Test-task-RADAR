#include "FormulaEvaluator.h"
#include <cctype>

static double getValue(const string& token, const CSVTable& table)
{
    if (isdigit(token[0]) || token[0] == '-') {
        return stod(token);
    }

    size_t pos = 0;

    while (pos < token.size() && isalpha(token[pos])) ++pos;

    string colName = token.substr(0, pos);
    int rowNum = stoi(token.substr(pos));

    const auto& rowMap = table.getRowMap();
    const auto& colMap = table.getColMap();
    const auto& data = table.getData();

    if (colMap.find(colName) == colMap.end() || rowMap.find(rowNum) == rowMap.end()) {
        cerr << "Invalid reference: " << token << endl;
        return 0;
    }

    int row = rowMap.at(rowNum);
    int col = colMap.at(colName);

    const Cell& cell = data[row][col];
    if (cell.isFormula) {
        return FormulaEvaluator::evaluate(cell.raw, table);
    }
    return cell.value;
}

double FormulaEvaluator::evaluate(const string& formula, const CSVTable& table)
{
    string expr = formula.substr(1);
    size_t startPos = (expr[0] == '-') ? 1 : 0;
    size_t opPos = expr.find_first_of("+-*/", startPos);
    if (opPos == string::npos) {
        cerr << "Invalid formula: " << formula << endl;
        return 0;
    }

    char op = expr[opPos];
    string left = expr.substr(0, opPos);
    string right = expr.substr(opPos + 1);

    double a = getValue(left, table);
    double b = getValue(right, table);

    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) {
            cerr << "Division by zero in " << formula << endl;
            return 0;
        }
        return a / b;
    default:
        cerr << "Unknown operator: " << op << endl;
        return 0;
    }
}
