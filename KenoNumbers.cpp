#include "KenoNumbers.h"
#include <iostream>
#include <algorithm>
#include <random>
// generates the 20 keno numbers
//(abstraction) this function will handel the generating  numbers so game doesnt have to
void KenoNumbers::generateNumbers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(0);

    std::uniform_int_distribution<int> distribution(1, 80);

    int number;

    for (int i = 1; i <= 20; i++) {
        number = distribution(gen);

        if (std::find(m_numbers.begin(), m_numbers.end(), number) == m_numbers.end()) {
            m_numbers.push_back(number);// saves the numbers
        }
        else {
            i--; // this would try again if the number was already picked
        }
    }
}
std::vector<int> KenoNumbers::getKenoNumbers() const {
    return m_numbers; // this will return keno numbers :)

}
void KenoNumbers::printKenoNumbers() {
    std::sort(m_numbers.begin(), m_numbers.end());
    std::cout << "Keno Numbers: "; // sorts the numbers from small to big

    for (int number : m_numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void KenoNumbers::clearKenoNumbers() {
    m_numbers.clear();
}

