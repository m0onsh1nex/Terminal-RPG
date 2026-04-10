#pragma once
#include"entity.h"

class Hero : public Entity {
public:
  using Entity::Entity;
  Hero(u32 id, string name, int hp, int lvl, int atk, int def) : Entity(id, name, hp, lvl, atk, def) {
    _type = "hero";
  }

  // --- Overrides --- 
  
  void onDeath() override {
    Entity::onDeath();
  }

  void onLvlUp() override {}

  void onGettingHit(int dmg) override {
    Entity::onGettingHit(dmg);
  }

   void onAttack(Entity * attacker, Entity * enemy) override {
     Entity::onAttack(attacker, enemy);
  }

  void onDefence() override {
    Entity::onDefence();   
  }

  void onHeal() override {
    Entity::onHeal();
  }
 
  // --- Deconstructor ---
  virtual ~Hero() = default;
};
