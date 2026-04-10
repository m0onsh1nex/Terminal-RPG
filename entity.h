#pragma once
#include<iostream>
#include<stdexcept>
#include<string>
#include<sstream>

class Entity {
protected:
  std::string _name;
  int _health;
  int _maxhealth;
  int _level;
  int _attack;
  int _defence;
  int _turns=2;

public:
  
  // --- Constructor --- 
  Entity(std::string name, float hp, int lvl, float atk, float def) {

    if (hp <= 0) throw std::invalid_argument("Invalid health\n");
    else {
      _health = hp;
      _maxhealth = hp;
    }
    if (lvl < 0) throw std::invalid_argument("Invalid level\n");
    else _level = lvl;
    
    if (atk < 0) throw std::invalid_argument("Invalid attack\n");
    else _attack = atk;

    if (def < 0) throw std::invalid_argument("Invalid defence\n");
    else _defence = def;

    if (name.empty()) throw std::invalid_argument("Invalid name\n");
    else _name = name;
  }

  //////////////////////
  ///   Functions   ///
  /////////////////////

  void lvlUp() {
    _level++;
    onLvlUp();
  }

  void a_attack(Entity * enemy) {
    onAttack(this, enemy);
  }

  void a_defence() {
    onDefence();
  }

  void a_heal() {
    onHeal();
  }

  // --- Getters --- 
  std::string getName() const {
    return _name;
  }
  int getHp() const {
    return _health;
  }
  int getLvl() const {
    return _level;
  }
  int getAtk() const {
    return _attack;
  }
  int getDef() const {
    return _defence;
  }

  std::string getInfo() const {

      std::string info = 
        "NAME:\t" + getName() + 
        "\nHP:\t" + std::to_string(getHp()) +
        "\nLVL:\t" + std::to_string(getLvl()) + 
        "\nDEF:\t" + std::to_string(getDef());
      return info;
    }

protected:

  // --- Abstracts --- 
  
  virtual void onDeath() {
    std::cout << _name << " defeated!";
  }

  virtual void onLvlUp() = 0;

  virtual void onGettingHit(int dmg) {
    _health -= (float)(dmg - _defence);
    if (floor(_health) <= 0) {
      onDeath();
    }
  }

  virtual void onAttack(Entity * attacker, Entity * enemy) {
    enemy->onGettingHit(attacker->_attack);
  }

  virtual void onDefence() {
    _defence += (1+_defence)*0.5;
  }

  virtual void onHeal() {
    _health = (_health+_health*0.1) - (int)(_health+_health*0.1) % (int)_maxhealth;
  }

  // --- Deconstructor ---
  virtual ~Entity() = default;
};
