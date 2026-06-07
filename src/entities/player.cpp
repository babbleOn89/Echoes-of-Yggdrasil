#include "entities/player.hpp"

Player::Player()
{
    position = {700.0f, 500.0f};
    speed = 3.0f;
    scale = 0.20f;

    equippedGear = GearType::NONE;
    equippedSpell = SpellType::NONE;
}

void Player::HandleInput()
{
    if(IsKeyDown(KEY_W)) position.y -= speed;
    if(IsKeyDown(KEY_S)) position.y += speed;
    if(IsKeyDown(KEY_A)) position.x -= speed;
    if(IsKeyDown(KEY_D)) position.x += speed;
}

void Player::Draw(Texture2D sprite, float drawScale) const
{
    float drawX = position.x - (sprite.width * drawScale) / 2.0f;
    float drawY = position.y - (sprite.height * drawScale);

    DrawTextureEx(
        sprite,
        {drawX, drawY},
        0.0f,
        drawScale,
        WHITE
    );
}

Vector2 Player::GetPosition() const
{
    return position;
}

void Player::SetPosition(Vector2 newPosition)
{
    position = newPosition;
}

void Player::AddGear(GearType gear)
{
    inventory.push_back(gear);
}

bool Player::HasGear(GearType gear) const
{
    for(GearType currentGear : inventory)
    {
        if(currentGear == gear)
            return true;
    }

    return false;
}

void Player::EquipGear(GearType gear)
{
    if(HasGear(gear))
    {
        equippedGear = gear;
    }
}

GearType Player::GetEquippedGear() const
{
    return equippedGear;
}

const std::vector<GearType>& Player::GetInventory() const
{
    return inventory;
}

void Player::AddSpell(SpellType spell)
{
    spellbook.push_back(spell);
}

bool Player::HasSpell(SpellType spell) const
{
    for(SpellType currentSpell : spellbook)
    {
        if(currentSpell == spell)
            return true;
    }

    return false;
}

void Player::EquipSpell(SpellType spell)
{
    if(HasSpell(spell))
    {
        equippedSpell = spell;
    }
}

SpellType Player::GetEquippedSpell() const
{
    return equippedSpell;
}

const std::vector<SpellType>& Player::GetSpells() const
{
    return spellbook;
}
