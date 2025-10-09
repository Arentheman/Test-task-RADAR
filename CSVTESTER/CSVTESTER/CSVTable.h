#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Cell {
    string raw;
    double value = 0;
    bool isFormula = false;
};

class CSVTable {
private:
    vector<vector<Cell>> table;
    map<int, int> rowMap;
    map<string, int> colMap;
    vector<string> header;

public:
    bool load(const string& filename);

    const vector<vector<Cell>>& getData() const { return table; }
    const map<int, int>& getRowMap() const { return rowMap; }
    const map<string, int>& getColMap() const { return colMap; }
    const vector<string>& getHeader() const { return header; }

    void print() const;
};
