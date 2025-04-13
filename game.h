#ifndef GAME_H
#define GAME_H
#include <cassert>

class State;

class Game
{
private:
    int m_answer;
    int m_bit;
public:
    Game();

    void SetLeastSignificantBit(const int bit);
    void UnsetLeastSignificantBit(const int bit);
    int CurrentBit()const{return m_bit;}
    void ShiftBit(){ m_bit += 1;}
    void ResetBit(){ m_bit = 0;}
    bool FinalBit()const{return m_bit == 5;}
    int Answer()const{return m_answer;}
};

#endif // GAME_H
