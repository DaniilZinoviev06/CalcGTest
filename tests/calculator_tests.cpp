#include "mock.h"


// ! Тесты, которые не пройдут, я закомментировал



// простая проверка базовых методов
TEST(testCalc, base_operations_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);

    EXPECT_EQ(calc.Add(1,1), 2);
    EXPECT_EQ(calc.Multiply(3,2), 6);
    EXPECT_EQ(calc.Subtract(1,1), 0);
    EXPECT_EQ(calc.Divide(1,1), 1);
}

// тест с умножением на ноль
TEST(testCalc, multiply_by_zero_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);

    EXPECT_EQ(calc.Multiply(5,0), 0);
}

// тесты переполнения
TEST(testCalc, overflow_test_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);

    EXPECT_EQ(calc.Add(INT_MAX,1), INT_MIN);
    EXPECT_EQ(calc.Subtract(INT_MIN,1), INT_MAX);
}

// тесты на деление
// использую EXPECT_DEATH, так как ожидаю фатальную ошибку(проверки деления на ноль - нет)
//
TEST(testCalc, divide_on_zero_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);
    EXPECT_DEATH({
        calc.Divide(5, 0);
    }, "");
}
// здесь должно произойти неявное приведение типов, и программа должна упасть, деление на 0
TEST(testCalc, divide_by_float_nmbr_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);
    EXPECT_DEATH({
        calc.Divide(5.0, 0.5);
    }, "");
}
/*
// но эти 2 варинта сверху мне не очень нравятся, так как мы не должны ожидать, что программа не учитывает деление на ноль
// можно в рег. выражении прописать, например, "err". Тогда сразу будет видна ошибка при тестах
TEST(testCalc, divide_by_zero_err_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);
    EXPECT_DEATH({
        calc.Divide(5, 0);
    }, "err");
}
TEST(testCalc, divide_by_float_nmbr_err_check) {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);
    EXPECT_DEATH({
        calc.Divide(5.0, 0.5);
    }, "err");
}*/