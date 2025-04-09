#ifndef MINER_H
#define MINER_H

#include <string>
#include <cassert>

class State;

//the amount of gold a miner must have before he feels comfortable
const int ComfortLevel       = 5;
//the amount of nuggets a miner can carry
const int MaxNuggets         = 3;
//above this value a miner is thirsty
const int ThirstLevel        = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;



class Game
{
private:

  State*                m_pCurrentState;
  int                   m_answer;
  int                   m_bit;

public:

  Game();

  //this must be implemented
  void Update();

  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to m_pCurrentState and finally calls the Entry()
  //method of the new state.
  void ChangeState(State* new_state);

  void          SetLeastSignificantBit(const int bit);
  void          UnsetLeastSignificantBit(const int bit);
  int           CurrentBit()const{return m_bit;}
  void          ShiftBit(){ m_bit += 1;}
  void          ResetBit(){ m_bit = 0;}
  bool          FinalBit()const{return m_bit == 5;}
  int           Answer()const{return m_answer;}

};




#endif
