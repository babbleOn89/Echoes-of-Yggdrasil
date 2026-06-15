#pragma once

//tracks a character's health and handles damage/death checks
class Health
{
public:
    //creates a health pool with an optional max value
    Health(int maxHealth = 100);

    int GetCurrent() const;
    int GetMax() const;

    void TakeDamage(int amount);
    //void Heal(int amount); //add healing later

    bool IsDead() const;

private:
    int currentHealth;
    int maxHealth;
};

