#include "GameStates.h"
#include "State.h"
#include "Game.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//--------------------------------------methods for InitialState

InitialState* InitialState::Instance()
{
  static InitialState instance;

  return &instance;
}

void InitialState::Enter(Game* pGame)
{
  system("clear");
}


void InitialState::Execute(Game* pGame)
{
  cout << "Think of a number between 0 and 63, but don't tell me 🤫" << endl;
  cout << "I’ll try to guess it 👀" << endl << endl;
  pGame->ResetBit();
  pGame->ChangeState(QuestionState::Instance());
}


void InitialState::Exit(Game* pGame)
{
  system("read -p 'Press ENTER when you are ready to play...'");
}

//--------------------------------------methods for QuestionState

QuestionState* QuestionState::Instance()
{
  static QuestionState instance;

  return &instance;
}

void QuestionState::Enter(Game* pGame)
{
  system("clear");
  cout << "Round " << pGame->CurrentBit() + 1 << endl;
}


void QuestionState::Execute(Game* pGame)
{
  cout << "Do you see your number in this list? 👀" << endl;
  for (int i=0; i<64; i++) {
    if (i & (1 << pGame->CurrentBit())) {
      cout << i << " ";
    }
  }
  cout << endl;
  pGame->ChangeState(WaitingForUserInput::Instance());
}


void QuestionState::Exit(Game* pGame)
{
  cout << endl;
}


//--------------------------------------methods for WaitingForUserInput

WaitingForUserInput* WaitingForUserInput::Instance()
{
  static WaitingForUserInput instance;

  return &instance;
}

void WaitingForUserInput::Enter(Game* pGame)
{
  cout << "[Y]es/[N]o" << endl;
  cout << "Your choice: ";
}


void WaitingForUserInput::Execute(Game* pGame)
{
  char response;
  cin >> response;
  if (toupper(response) == 'Y')
  {
    pGame->SetLeastSignificantBit(pGame->CurrentBit());
  } else {
    pGame->UnsetLeastSignificantBit(pGame->CurrentBit());
  }

  if (pGame->FinalBit()) {
    pGame->ChangeState(FinalState::Instance());
  } else {
    pGame->ChangeState(QuestionState::Instance());
  }
}


void WaitingForUserInput::Exit(Game* pGame)
{
  pGame->ShiftBit();
}

//--------------------------------------methods for FinalState

FinalState* FinalState::Instance()
{
  static FinalState instance;

  return &instance;
}

void FinalState::Enter(Game* pGame)
{
  system("clear");
  cout << "The number you have guessed is " << pGame->Answer() << endl << endl;
}


void FinalState::Execute(Game* pGame)
{
  pGame->ChangeState(InitialState::Instance());
}


void FinalState::Exit(Game* pGame)
{
  system("read -p 'Press ENTER to start again...'");
}
