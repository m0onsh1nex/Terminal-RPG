#pragma once
#include"entity.h"
#include <string>

class Enemy : public Entity {
public:
  using Entity::Entity;
  Enemy(std::string name, int hp, int lvl, int atk, int def) : Entity(name, hp, lvl,atk, def) {}

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

   virtual ~Enemy() = default;
};
