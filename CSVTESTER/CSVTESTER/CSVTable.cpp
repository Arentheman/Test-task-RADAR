#include "CSVTable.h"

bool CSVTable::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return false;
    }

    string line;
    bool firstLine = true;
    int rowIndex = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string cellText;
        vector<Cell> row;
        vector<string> tokens;

        while (getline(ss, cellText, ',')) {
            tokens.push_back(cellText);
        }

        if (firstLine) {
            header = tokens;
            for (size_t i = 1; i < header.size(); ++i) {
                colMap[header[i]] = static_cast<int>(i);
            }
            firstLine = false;
            continue;
        }

        if (tokens.empty()) continue;
        int rowNumber = stoi(tokens[0]);
        rowMap[rowNumber] = rowIndex++;

        for (size_t i = 0; i < tokens.size(); ++i) {
            Cell c;
            c.raw = tokens[i];
            if (!c.raw.empty() && c.raw[0] == '=') {
                c.isFormula = true;
            }
            else if (!c.raw.empty() && (isdigit(c.raw[0]) || c.raw[0] == '-')) {
                c.value = stod(c.raw);
            }
            row.push_back(c);
        }

        table.push_back(row);
    }

    file.close();
    return true;
}

void CSVTable::print() const {
    for (size_t i = 0; i < header.size(); ++i) {
        cout << header[i];
        if (i != header.size() - 1) cout << ",";
    }
    cout << endl;

    for (const auto& row : table) {
        for (size_t i = 0; i < row.size(); ++i) {
            const auto& cell = row[i];
            if (cell.isFormula || (!cell.raw.empty() && (isdigit(cell.raw[0]) || cell.raw[0] == '-'))) {
                cout << cell.value;
            }
            else {
                cout << cell.raw;
            }
            if (i != row.size() - 1) cout << ",";
        }
        cout << endl;
    }
}
