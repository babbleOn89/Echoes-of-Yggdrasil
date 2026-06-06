#include "player.hpp"

Player::Player()
{
    position = {700.0f, 500.0f};
    speed = 3.0f;
    scale = 0.20f;

    equippedItem = ItemType::NONE;
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

void Player::AddItem(ItemType item)
{
    inventory.push_back(item);
}

bool Player::HasItem(ItemType item) const
{
    for(ItemType currentItem : inventory)
    {
        if(currentItem == item)
            return true;
    }

    return false;
}

void Player::EquipItem(ItemType item)
{
    if(HasItem(item))
    {
        equippedItem = item;
    }
}

ItemType Player::GetEquippedItem() const
{
    return equippedItem;
}

const std::vector<ItemType>& Player::GetInventory() const
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
