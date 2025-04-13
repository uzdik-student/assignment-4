#include "game.h"

Game::Game():
    m_answer(0),
    m_bit(0)
{}

void Game::SetLeastSignificantBit(const int bit)
{
    // Set LSB to 1
    m_answer = m_answer | (1 << bit);
}

void Game::UnsetLeastSignificantBit(const int bit)
{
    // Set LSB to 0
    m_answer = m_answer & ~(1 << bit);
}
