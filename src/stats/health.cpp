#include "stats/health.hpp"

//initializ health values when the character is created
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
    
    //prevents health from dropping below zero
    if(currentHealth < 0)
        currentHealth = 0;
}

bool Health::IsDead() const
{
    //player will need to reload a previous save
    return currentHealth <= 0;
}


