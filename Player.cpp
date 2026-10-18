#include "Player.h"
#include <iostream>
#include <algorithm>



void Player::inputPlayerNumbers() {
    bool error;
    int number = 0 ;
    for (int i = 0; i < 10; i++)
    {
        error = false;

        std::cout << "Enter your pick #" << i + 1 << ": ";
        std::cin >> number;

        if (std::cin.fail())
        {
            error = true;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid data input! Try again. ";
        }
        else if (number < 1 || number > 80)
        {
            error = true;
            std::cout << number << " is out of range! Try again. ";
        }
        else if (std::find(m_playerNumbers.begin(), m_playerNumbers.end(), number)
                 != m_playerNumbers.end())
        {
            error = true;
            std::cout << number << " was already picked! Try again. ";
        }

        if (error)
        {
            i--; //  this repeats the same pick if there was an error
        }
        else
        {
            m_playerNumbers.push_back(number); // this will save the number
        }
    }
}

std::vector<int> Player::getPlayerNumbers() const {
    return m_playerNumbers;
}

void Player::printPlayerNumbers() {
    std::sort(m_playerNumbers.begin(), m_playerNumbers.end());
    std::cout << "Player Picks: ";

    for (int number : m_playerNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}
void Player::clearPlayerNumbers() {
    m_playerNumbers.clear(); // this clears numbers for net round
}
