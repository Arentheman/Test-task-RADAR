#include "CSVTable.h"
#include "FormulaEvaluator.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
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
                cell.value = FormulaEvaluator::evaluate(cell.raw, table);
            }
        }
    }

    table.print();
    return 0;
}
