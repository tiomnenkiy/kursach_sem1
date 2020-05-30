#include "personality.h"

Personality::Personality() {
    health = 0;
    endurance = 0;
    intellect = 0;
    agillity = 0;
    ++Count();
}

Warrior::Warrior() {
    SetHealth(80);
    SetEndurance(60);
    SetIntellect(30);
    SetAgility(40);
    SetInstrument("sword");
}

Mage::Mage() {
    SetHealth(30);
    SetEndurance(40);
    SetIntellect(80);
    SetAgility(50);
    SetInstrument("staff");
}

Thief::Thief() {
    SetHealth(50);
    SetEndurance(30);
    SetIntellect(60);
    SetAgility(80);
    SetInstrument("dagger");
}

Hobbit::Hobbit() {
    SetHealth(40);
    SetEndurance(80);
    SetIntellect(50);
    SetAgility(30);
    SetInstrument("ring");
}