#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H

#include "State.h"

class Game;


//------------------------------------------------------------------------
//
//  Initial state of the game, where user need to hide number
//------------------------------------------------------------------------
class InitialState : public State
{
private:

  InitialState(){}

  //copy ctor and assignment should be private
  InitialState(const InitialState&);
  InitialState& operator=(const InitialState&);

public:

  //this is a singleton
  static InitialState* Instance();
  
  virtual void Enter(Game* game);

  virtual void Execute(Game* game);

  virtual void Exit(Game* game);
};

//------------------------------------------------------------------------
//
//  Question state, where user is being asked a question
//------------------------------------------------------------------------
class QuestionState : public State
{
private:

  QuestionState(){}

  //copy ctor and assignment should be private
  QuestionState(const QuestionState&);
  QuestionState& operator=(const QuestionState&);

public:

  //this is a singleton
  static QuestionState* Instance();
  
  virtual void Enter(Game* game);

  virtual void Execute(Game* game);

  virtual void Exit(Game* game);
};

//------------------------------------------------------------------------
//
//  Answer state, where user inputs Yes or No
//------------------------------------------------------------------------
class WaitingForUserInput : public State
{
private:

  WaitingForUserInput(){}

  //copy ctor and assignment should be private
  WaitingForUserInput(const WaitingForUserInput&);
  WaitingForUserInput& operator=(const WaitingForUserInput&);

public:

  //this is a singleton
  static WaitingForUserInput* Instance();
  
  virtual void Enter(Game* game);

  virtual void Execute(Game* game);

  virtual void Exit(Game* game);
};

//------------------------------------------------------------------------
//
//  Final state, where answer is revealed
//------------------------------------------------------------------------
class FinalState : public State
{
private:

  FinalState(){}

  //copy ctor and assignment should be private
  FinalState(const FinalState&);
  FinalState& operator=(const FinalState&);

public:

  //this is a singleton
  static FinalState* Instance();
  
  virtual void Enter(Game* game);

  virtual void Execute(Game* game);

  virtual void Exit(Game* game);
};


#endif
