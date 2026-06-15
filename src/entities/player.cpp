#include "entities/player.hpp"

Player::Player()
{
    //default spawn position
    position = {700.0f, 500.0f};

    //movement speed in ppf
    speed = 3.0f;

    //default sprite scale
    scale = 0.20f;
    
    //player starts with no equipment
    equippedGear = GearType::NONE;
    equippedSpell = SpellType::NONE;
}

// basic WASD movement

void Player::HandleInput()
{
    if(IsKeyDown(KEY_W)) position.y -= speed;
    if(IsKeyDown(KEY_S)) position.y += speed;
    if(IsKeyDown(KEY_A)) position.x -= speed;
    if(IsKeyDown(KEY_D)) position.x += speed;
}

void Player::Draw(Texture2D sprite, float drawScale) const
{
    //player position represents the sprite's feet.
    //offset sprite so it draws centered above that point
    //DrawTextureEx uses the sprites top-left corner,
    //so the draw position is adjusted manually
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

//Gear information

void Player::AddGear(GearType gear)
{
    inventory.push_back(gear);
}

//search inventory for requested gear
//check every item in inventory until a match is found
bool Player::HasGear(GearType gear) const
{
    for(GearType currentGear : inventory)
    {
        if(currentGear == gear)
            return true;
    }

    return false;
}

//only equip gear the player actually owns
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

//Spell information

void Player::AddSpell(SpellType spell)
{
    spellbook.push_back(spell);
}

//search spellbook for the requested spell
bool Player::HasSpell(SpellType spell) const
{
    for(SpellType currentSpell : spellbook)
    {
        if(currentSpell == spell)
            return true;
    }

    return false;
}

//only equip spells the player has learned
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
