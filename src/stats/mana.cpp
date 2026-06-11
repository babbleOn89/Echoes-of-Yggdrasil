#include "stats/mana.hpp"

Mana::Mana(int maxMana)
{
    this->maxMana = maxMana;
    currentMana = maxMana;

    rechargeTimer = 0.0f;
}

int Mana::GetCurrent() const
{
    return currentMana;
}

int Mana::GetMax() const
{
    return maxMana;
}

bool Mana::HasEnough(int cost) const
{
    return currentMana >= cost;
}

bool Mana::Spend(int cost)
{
    if(!HasEnough(cost))
        return false;

    currentMana -= cost;
    return true;
}

void Mana::Recharge(int amount)
{
    currentMana += amount;

    if(currentMana > maxMana)
        currentMana = maxMana;
}

void Mana::Update(float dt)
{
    rechargeTimer+= dt;

    if(rechargeTimer >= 2.0f)
    {
        Recharge(10);
        rechargeTimer = 0.0f;
    }
}

