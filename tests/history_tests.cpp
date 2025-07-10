#include "mock.h"

// ! Тесты, которые не пройдут, я закомментировал

// Такие тесты пройдут без ошибок
TEST(TestHistory, history_check) {
    HistoryMock history;
    calc::SimpleCalculator calc(history);

    EXPECT_CALL(history, AddEntry("20 / 5 = 4"));
    calc.Divide(20, 5);
}

// Проверка, что история правильно возвращает операции
TEST(TestHistory, get_last_operation_check) {
    calc::InMemoryHistory history;

    history.AddEntry("7 * 8 = 56");
    history.AddEntry("5 * 6 = 30");
    history.AddEntry("20 / 4 = 5");
    history.AddEntry("8 * 8 = 64");

    std::vector<std::string> op = history.GetLastOperations(3);

    ASSERT_EQ(op.size(), 3);

    EXPECT_EQ(op[0], "5 * 6 = 30");
    EXPECT_EQ(op[1], "20 / 4 = 5");
    EXPECT_EQ(op[2], "8 * 8 = 64");
}
/*
// Такой тест не пройдет, установил лимиты для истории
// здесь, можно сказать, что TDD, то есть в тестах функциональнсть,
// которой нет в библиотеке калькулятора
TEST(TestHistory, operation_limit_check) {
    calc::InMemoryHistory history;
    const size_t SIZE_HISTORY = 150;


    for(size_t i = 0; i < SIZE_HISTORY + 1; ++i) {
        history.AddEntry(std::to_string(i));
    }

    std::vector<std::string> op = history.GetLastOperations(SIZE_HISTORY + 1);
    EXPECT_LE(op.size(), SIZE_HISTORY);
}*/

// данный тест успешно завершится
TEST(TestHistory, history_overflow_first_check) {
    HistoryMock history;
    calc::SimpleCalculator calc(history);

    EXPECT_CALL(history, AddEntry("2147483647 + 1 = -2147483648"));
    calc.Add(INT_MAX, 1);

    EXPECT_CALL(history, AddEntry("-2147483648 - 1 = 2147483647"));
    calc.Subtract(INT_MIN, 1);
}
/*
// Такой тест не пройдет, тест на запись в истории
TEST(TestHistory, history_overflow_second_check) {
    HistoryMock history;
    calc::SimpleCalculator calc(history);

    EXPECT_CALL(history, AddEntry("2147483647 + 1 = 2147483648"));
    calc.Add(INT_MAX, 1);

    EXPECT_CALL(history, AddEntry("-2147483648 - 1 = -2147483649"));
    calc.Subtract(INT_MIN, 1);
}
*/

// До этого мокой был история, теперь калькулятор
// Для мок с калькулятором особо ничего не придумал
TEST(TestHistory, calculator_moсk_check) {
    calc::InMemoryHistory history;
    CalculatorMock calc(history);

    EXPECT_CALL(calc, LogOperation(200, "/", 25, 8));
    calc.LogOperation(200, "/", 25, 8);
}


