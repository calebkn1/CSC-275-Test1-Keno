#ifndef Game_h
#define Game_h

#include <vector>
#include "Player.h"
#include "KenoNumbers.h"

class Game {
private:
    KenoNumbers m_keno;
    Player m_player; // game has a player object
    std::vector<int> m_matches; // this will store the numbers that match

public:
    Game();
    void printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers);
    void displayResults();
    void playGame();
};

#endif