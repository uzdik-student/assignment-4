#include "GameStates.h"
#include "State.h"
#include "Game.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//--------------------------------------methods for GuessNumber

GuessNumber* GuessNumber::Instance()
{
  static GuessNumber instance;

  return &instance;
}

void GuessNumber::Enter(Game* pGame)
{
  system("clear");
}


void GuessNumber::Execute(Game* pGame)
{
  cout << "Think of a number between 0 and 63, but don't tell me 🤫" << endl;
  cout << "I’ll try to guess it 👀" << endl << endl;
  pGame->ResetBit();
  pGame->ChangeState(ShowFirstBit::Instance());
}


void GuessNumber::Exit(Game* pGame)
{
  system("read -p 'Press ENTER when you are ready to play...'");
}

//--------------------------------------methods for ShowFirstBit

ShowFirstBit* ShowFirstBit::Instance()
{
  static ShowFirstBit instance;

  return &instance;
}

void ShowFirstBit::Enter(Game* pGame)
{
  system("clear");
  cout << "Round " << pGame->CurrentBit() + 1 << endl;
}


void ShowFirstBit::Execute(Game* pGame)
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


void ShowFirstBit::Exit(Game* pGame)
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
    pGame->ChangeState(ShowFirstBit::Instance());
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
  pGame->ChangeState(GuessNumber::Instance());
}


void FinalState::Exit(Game* pGame)
{
  system("read -p 'Press ENTER to start again...'");
}