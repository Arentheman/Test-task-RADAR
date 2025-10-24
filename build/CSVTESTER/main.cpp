#include "CSVTable.h"
#include <set>
//#include <cctype>

string evaluate(const string& formula, const CSVTable& table, set<string>& visited);

string getValue(const string& token, const CSVTable& table, set<string>& visited)
{
    if (isdigit(token[0]) || token[0] == '-') {
        return token;
    }

    size_t pos = 0;

    while (pos < token.size() && isalpha(token[pos])) ++pos;

    string colName = token.substr(0, pos);
    int rowNum = stoi(token.substr(pos));

    string id = colName + to_string(rowNum);
    if (visited.count(id)) {
        cerr << "Cycle detected at: " << id << endl;
        return "#CYCLE";
    }
    visited.insert(id);

    const auto& rowMap = table.getRowMap();
    const auto& colMap = table.getColMap();
    const auto& data = table.getData();

    if (colMap.find(colName) == colMap.end() || rowMap.find(rowNum) == rowMap.end()) {
        cerr << "Invalid reference: " << token << endl;
        return "#REF!";
    }

    int row = rowMap.at(rowNum);
    int col = colMap.at(colName);
    const Cell& cell = data[row][col];

    string result;
    if (cell.isFormula)
        result = evaluate(cell.raw, table, visited);
    else if (!cell.raw.empty())
        result = cell.raw;
    else
        result = "0";

    visited.erase(id);
    return result;
}

string evaluate(const string& formula, const CSVTable& table, set<string>& visited)
{
    string expr = formula.substr(1);
    size_t startPos = (expr[0] == '-') ? 1 : 0;
    size_t opPos = expr.find_first_of("+-*/", startPos);
    if (opPos == string::npos) {
        cerr << "Invalid formula: " << formula << endl;
        return "0";
    }

    char op = expr[opPos];
    string left = expr.substr(0, opPos);
    string right = expr.substr(opPos + 1);

    string a_str = getValue(left, table, visited);
    string b_str = getValue(right, table, visited);

    if (!isdigit(a_str[0]) && a_str[0] != '-' || !isdigit(b_str[0]) && b_str[0] != '-') {
        return (a_str[0] == '#' ? a_str : b_str);
    }

    double a = stod(getValue(left, table, visited));
    double b = stod(getValue(right, table, visited));

    double res = 0;
    switch (op) {
    case '+': res = a + b; break;
    case '-': res = a - b; break;
    case '*': res = a * b; break;
    case '/':
        if (b == 0) {
            cerr << "Division by zero in " << formula << endl;
            return "#DIV/0!";
        }
        res = a / b; break;
    default:
        cerr << "Unknown operator: " << op << endl;
        return "0";
    }
    return to_string(res);
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    if (argc < 2) {
        /*static const char* fakeArgv[] = { "csvreader.exe", "C:\\Users\\АРЕНАЙК\\Desktop\\Тестовое задание\\CSVTESTER\\x64\\Debug\\тест.csv" };
        argv = const_cast<char**>(fakeArgv);
        argc = 2;*/
        cerr << "Usage: " << argv[0] << " file.csv" << endl;
        return 1;
    }

    CSVTable table;
    if (!table.load(argv[1])) {
        return 1;
    }

    for (auto& row : const_cast<vector<vector<Cell>>&>(table.getData())) {
        for (auto& cell : row) {
            if (cell.isFormula) {
                set<string> visited;
                cell.raw = evaluate(cell.raw, table, visited);
                cell.isFormula = false;
            }
        }
    }

    table.print();
    return 0;
}