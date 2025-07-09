#include <iostream>
#include "SimpleCalculator.h"
#include "InMemoryHistory.h"


int main() {
    calc::InMemoryHistory history;
    calc::SimpleCalculator calc(history);

    std::cout << "сложение " << calc.Add(4,5) << std::endl;
    std::cout << "вычитание " << calc.Subtract(4,5) << std::endl;
    std::cout << "Деление " << calc.Divide(4,5) << std::endl;
    std::cout << "умножение " << calc.Multiply(4,5) << std::endl;

    std::vector<std::string> last_op = history.GetLastOperations(4);

    for (int i = 0; i < last_op.size(); ++i) {
        std::cout << last_op[i] << std::endl;
    }
}