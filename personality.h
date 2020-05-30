/* personality.h
 * consists of Personality and Warrior classes
 * Personality is Warrior's ancestor
 */
#ifndef KURS_PERSONALITY_H
#define KURS_PERSONALITY_H

#include <string.h>

/* Personality
 * is an abstract class
 */
class Personality {
    int health;
    int endurance;
    int intellect;
    int agillity;
    char instrument[20];
    size_t& Count() {static size_t c = 0; return c;}
public:
    Personality();
    ~Personality() {--Count();};
    //геттеры
    int GetHealth() const {return health;}
    int GetEndurance() const {return endurance;}
    int GetIntellect() const {return intellect;}
    int GetAgility() const {return agillity;}
    char* GetInstrument() {return instrument;}
    size_t GetCountPersonality() {return Count();}
    //сеттеры
    int SetHealth(int data) {health = data; return health;}
    int SetEndurance(int data) {endurance = data; return endurance;}
    int SetIntellect(int data) {intellect = data; return intellect;}
    int SetAgility(int data) {agillity = data; return agillity;}
    char* SetInstrument(char* data) {strcpy(instrument, data); return instrument;}
    virtual int Train() = 0; // pure virtual func
};

class Warrior : public Personality {
public:
    Warrior();
    ~Warrior() = default;
    virtual int Train() {SetHealth(GetHealth()+10); return GetHealth();}
};

class Mage : public Personality {
public:
    Mage();
    ~Mage() = default;
    virtual int Train() {SetIntellect(GetIntellect()+10); return GetIntellect();}
};

class Thief : public Personality {
public:
    Thief();
    ~Thief() = default;
    virtual int Train() {SetAgility(GetAgility()+10); return GetAgility();}
};

class Hobbit : public Personality {
public:
    Hobbit();
    ~Hobbit() = default;
    virtual int Train() {SetEndurance(GetEndurance()+10); return GetEndurance();}
};

#endif //KURS_PERSONALITY_H