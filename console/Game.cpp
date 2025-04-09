#include "Game.h"
#include "GameStates.h"

Game::Game():m_pCurrentState(GuessNumber::Instance()),
                     m_answer(0),
                     m_bit(0)
                                                                  
{}

//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void Game::ChangeState(State* pNewState)
{
  //make sure both states are both valid before attempting to 
  //call their methods
  assert (m_pCurrentState && pNewState);

  //call the exit method of the existing state
  m_pCurrentState->Exit(this);

  //change state to the new state
  m_pCurrentState = pNewState;

  //call the entry method of the new state
  m_pCurrentState->Enter(this);
}

//-----------------------------------------------------------------------------
void Game::Update()
{
  if (m_pCurrentState)
  {
    m_pCurrentState->Execute(this);
  }
}

//-----------------------------------------------------------------------------
void Game::SetLeastSignificantBit(const int bit)
{
  // Set LSB to 1
  m_answer = m_answer | (1 << bit);
}

//-----------------------------------------------------------------------------
void Game::UnsetLeastSignificantBit(const int bit)
{
  // Set LSB to 0
  m_answer = m_answer & ~(1 << bit);
}
