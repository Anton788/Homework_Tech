#include<iostream>

class Swords
{
  public:
    virtual int UseSword() = 0;
    virtual ~Swords() {}
};

class Armor
{
  public:
    virtual int UseArmor() = 0;
    virtual ~Armor() {}
};

class Boots
{
  public:
    virtual int UseBoots() = 0;
    virtual ~Boots() {}
};

class Equipment
{
  public:
    virtual Swords* createSword() = 0;
    virtual Armor* createArmor() = 0;
    virtual Boots* createBoots() = 0;
    virtual ~Equipment() {}
};

class IronSword: public Swords {
public:
    int UseSword();
};

class IronArmor: public Armor {
  public:
    int UseArmor();
};

class IronBoots: public Boots {
  public:
    int UseBoots();
};

class IronEquipment: public Equipment {
  public:
    Swords* createSword();
    Armor* createArmor();
    Boots* createBoots();
};

class WoodSword: public Swords
{
  public:
    int UseSword();
};

class LeatherArmor: public Armor
{
  public:
    int UseArmor();
};

class LeatherBoots: public Boots
{
  public:
    int UseBoots();
};

class LeatherEquipment: public Equipment {
  public:
    Swords* createSword();
    Armor* createArmor();
    Boots* createBoots();
};

