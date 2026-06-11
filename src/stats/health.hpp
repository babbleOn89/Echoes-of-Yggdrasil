#pragma once

class Health
{
public:
    Health(int maxHealth = 100);

    int GetCurrent() const;
    int GetMax() const;

    void TakeDamage(int amount);
    void Heal(int amount);

    bool IsDead() const;

private:
    int currentHealth;
    int maxHealth;
};

