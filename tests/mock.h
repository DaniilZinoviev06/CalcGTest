#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../ICalculator.h"
#include "../IHistory.h"
#include "../SimpleCalculator.h"
#include "../InMemoryHistory.h"
#include "mock.h"

class CalculatorMock : public calc::ICalculator {
public:
    CalculatorMock(calc::IHistory& history) : history(&history) {}

    MOCK_METHOD(int, Add, (int a, int b), (override));
    MOCK_METHOD(int, Subtract, (int a, int b), (override));
    MOCK_METHOD(int, Multiply, (int a, int b), (override));
    MOCK_METHOD(int, Divide, (int a, int b), (override));
    MOCK_METHOD(void, SetHistory, (calc::IHistory& history), (override));

    MOCK_METHOD(void, LogOperation, (int a, const char* op, int b, int result));

private:
    calc::IHistory* history;
};

class HistoryMock : public calc::IHistory {
public:
    MOCK_METHOD(void, AddEntry, (const std::string&), (override));
    MOCK_METHOD(std::vector<std::string>, GetLastOperations, (size_t), (const, override));
};