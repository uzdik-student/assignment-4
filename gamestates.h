#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "State.h"

//------------------------------------------------------------------------
//
//  Todo: guess number description
//------------------------------------------------------------------------
class GuessNumber : public State
{
private:

    GuessNumber(){}

    //copy ctor and assignment should be private
    GuessNumber(const GuessNumber&);
    GuessNumber& operator=(const GuessNumber&);

public:

    //this is a singleton
    static GuessNumber* Instance();

    virtual void Enter(Game* game);

    virtual void Execute(Game* game);

    virtual void Exit(Game* game);
};

//------------------------------------------------------------------------
//
//  Todo: first state description
//------------------------------------------------------------------------
class ShowFirstBit : public State
{
private:

    ShowFirstBit(){}

    //copy ctor and assignment should be private
    ShowFirstBit(const ShowFirstBit&);
    ShowFirstBit& operator=(const ShowFirstBit&);

public:

    //this is a singleton
    static ShowFirstBit* Instance();

    virtual void Enter(Game* game);

    virtual void Execute(Game* game);

    virtual void Exit(Game* game);
};

//------------------------------------------------------------------------
//
//  Todo: waiting for user state description
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
//  Todo: final state description
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

#endif // GAMESTATES_H
