#ifndef STATE_H
#define STATE_H

class Game;

class State
{
public:

    virtual ~State(){}

    //this will execute when the state is entered
    virtual void Enter(Game*)=0;

    //this is the state's normal update function
    virtual void Execute(Game*)=0;

    //this will execute when the state is exited
    virtual void Exit(Game*)=0;

};

#endif // STATE_H
