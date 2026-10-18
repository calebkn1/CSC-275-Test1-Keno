#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Game::Game() {
    // this is the constructor for the game
}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {
    m_matches.clear(); // this will clear the matches from the last round

    for (int i = 0; i < playerPicks.size(); i++) {
        for (int j = 0; j < kenoNumbers.size(); j++) {
            if (playerPicks.at(i) == kenoNumbers.at(j)) {
                m_matches.push_back(playerPicks.at(i)); // this will save the matching number
            }
        }
    }

    std::sort(m_matches.begin(), m_matches.end()); // this will sort the matches from smallest to biggest

    std::cout << "You matched: ";

    for (int number : m_matches) {
        std::cout << number << " ";
    }

    std::cout << std::endl;
}

void Game::displayResults() {
    // this will check how many numbers matched and show the prize
    std::cout << "Matching " << m_matches.size() << " of 20 numbers wins ";

    switch (m_matches.size()) {
        case 10:
            std::cout << "$25,000";
            break;
        case 9:
            std::cout << "$2,500";
            break;
        case 8:
            std::cout << "$250";
            break;
        case 7:
            std::cout << "$50";
            break;
        case 6:
            std::cout << "$10";
            break;
        case 5:
            std::cout << "$5";
            break;
        default:
            std::cout << "$0";
    }

    std::cout << std::endl;
}

void Game::playGame() {
    char again = 'y';

    do {
        std::cout << "\nTo play Keno, select 10 unique (no repeats) "
                  << "numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";

        // (abstraction) this will let each class handle its own part of the game
        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();

        std::cout << "\n----------------------------------Results----------------------------------\n";

        m_keno.printKenoNumbers();
        m_player.printPlayerNumbers();

        // this will compare the player numbers with the keno numbers
        printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());

        displayResults(); // this will show how much the player won

        std::cout << "\nPlay another round? (y/n): ";
        std::cin >> again;

        // this will clear everything for the next round
        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();

    } while (std::tolower(again) == 'y');

    std::cout << "\nTHANKS FOR PLAYING!!\n";
}