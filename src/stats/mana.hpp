#pragma once

class Mana
{
public:
    Mana(int maxMana = 100);

    int GetCurrent() const;
    int GetMax() const;

    bool HasEnough(int cost) const;
    bool Spend(int cost);
    void Recharge(int amount);

    void Update(float dt);

private:
    int currentMana;
    int maxMana;
    float rechargeTimer;
};
