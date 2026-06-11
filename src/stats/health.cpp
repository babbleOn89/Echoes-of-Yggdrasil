#include "stats/health.hpp"

Health::Health(int maxHealth)
{
    this->maxHealth = maxHealth;
    currentHealth = maxHealth;
}

int Health::GetCurrent() const
{
    return currentHealth;
}

int Health::GetMax() const
{
    return maxHealth;
}

void Health::TakeDamage(int amount)
{
    currentHealth -= amount;

    if(currentHealth < 0)
        currentHealth = 0;
}

bool Health::IsDead() const
{
    return currentHealth <= 0;
}


