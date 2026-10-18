#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {
private:
    std::vector<int> m_playerNumbers; // (encapsulation) this keeps the player numbers private

public:
    void inputPlayerNumbers();
    std::vector<int> getPlayerNumbers() const;
    void printPlayerNumbers();
    void clearPlayerNumbers();
};

#endif