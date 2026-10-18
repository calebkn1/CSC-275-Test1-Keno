#ifndef KenoNumbers_h
#define KenoNumbers_h
#include <vector>


class KenoNumbers {
private:
    std::vector<int> m_numbers; //(another encapsulation) keeps the keno numbers private.

public:
    void generateNumbers();
    std::vector<int> getKenoNumbers() const;
    void printKenoNumbers();
    void clearKenoNumbers();
};
#endif