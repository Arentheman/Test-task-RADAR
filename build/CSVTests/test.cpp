#include "pch.h"
#include "../CSVTESTER/CSVTable.h"
#include "../CSVTESTER/CSVTable.cpp"
#include "../CSVTESTER/main.cpp"

TEST(FormulaEvaluatorTest, SimpleAddition) {
    CSVTable table;
    double result = evaluate("=2+3", table);
    EXPECT_EQ(result, 5);
}

TEST(FormulaEvaluatorTest, NegativeNumbers) {
    CSVTable table;
    double result = evaluate("=-4+9", table);
    EXPECT_EQ(result, 5);
}

TEST(FormulaEvaluatorTest, DivisionByZero) {
    CSVTable table;
    double result = evaluate("=10/0", table);
    EXPECT_EQ(result, 0);
}

TEST(FormulaEvaluatorTest, InvalidCellReference) {
    CSVTable table;
    table.load("test.csv");
    double result = evaluate("=A1+X1", table);
    EXPECT_EQ(result, 1);
}