#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterName;
    int characterLevel;
    int characterHealth;

public:
    Character(string name, int level, int health) 
        : characterName(name), characterLevel(level), characterHealth(health) {}

    void showStats() {
        cout << "Name: " << characterName << endl;
        cout << "Level: " << characterLevel << endl;
        cout << "Health: " << characterHealth << endl;
    }

    void receiveDamage(int damage) {
        characterHealth -= damage;
        cout << characterName << " takes " << damage << " damage!" << endl;
    }
};

class Warrior : public Character {
protected:
    int attackPower;
    string weaponType;

public:
    Warrior(string name, int level, int health, int power, string weapon) 
        : Character(name, level, health), attackPower(power), weaponType(weapon) {}

    void performSlash() {
        cout << characterName << " slashes with " << weaponType << " for " << attackPower << " damage!" << endl;
    }

    void showStats() {
        Character::showStats();
        cout << "Strength: " << attackPower << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Mage : public Character {
protected:
    int magicPower;
    string spellName;

public:
    Mage(string name, int level, int health, int power, string spell) 
        : Character(name, level, health), magicPower(power), spellName(spell) {}

    void castSpell() {
        cout << characterName << " casts " << spellName << " for " << magicPower << " damage!" << endl;
    }

    void showStats() {
        Character::showStats();
        cout << "Intelligence: " << magicPower << endl;
        cout << "Spell: " << spellName << endl;
    }
};

class Archer : public Character {
protected:
    int accuracy;
    string bowType;

public:
    Archer(string name, int level, int health, int aim, string bow) 
        : Character(name, level, health), accuracy(aim), bowType(bow) {}

    void shootArrow() {
        cout << characterName << " fires a rapid shot with " << bowType << " for " << accuracy << " damage!" << endl;
    }

    void showStats() {
        Character::showStats();
        cout << "Dexterity: " << accuracy << endl;
        cout << "Bow: " << bowType << endl;
    }
};

class NPC : public Character {
protected:
    string greeting;

public:
    NPC(string name, int level, int health, string message) 
        : Character(name, level, health), greeting(message) {}

    void talk() {
        cout << characterName << " says: \"" << greeting << "\"" << endl;
    }

    void showStats() {
        Character::showStats();
        cout << "Dialogue: " << greeting << endl;
    }
};

class HybridHero : public Warrior, public Mage {
public:
    HybridHero(string name, int level, int health, int strength, string weapon, int magic, string spell)
        : Warrior(name, level, health, strength, weapon), Mage(name, level, health, magic, spell) {}

    void showStats() {
        Warrior::showStats();
        cout << "Magic Power: " << magicPower << endl;
        cout << "Spell: " << spellName << endl;
    }
};

int main() {
    Warrior fighter("Conan", 10, 100, 15, "Greatsword");
    fighter.showStats();
    fighter.performSlash();

    Mage wizard("Gandalf", 15, 80, 20, "Fireball");
    wizard.showStats();
    wizard.castSpell();

    Archer bowman("Legolas", 12, 90, 18, "Elven Bow");
    bowman.showStats();
    bowman.shootArrow();

    NPC merchant("Bob", 1, 50, "Welcome to my shop!");
    merchant.showStats();
    merchant.talk();

    HybridHero demigod("Hercules", 20, 150, 18, "Divine Sword", 16, "Lightning Strike");
    demigod.showStats();
    demigod.performSlash();
    demigod.castSpell();

    return 0;
}
