#include <iostream>
#include <vector>
#include "Equipment.h"

Armor* IronEquipment::createArmor() {
    return new IronArmor;
}

Boots* IronEquipment::createBoots() {
    return new IronBoots;
}

Swords* IronEquipment::createSword() {
    return new IronSword;
}

int IronSword::UseSword() {
    static int k = 40;
    return k;
}

int IronArmor::UseArmor() {
    static int k = 80;
    return k;
}

int IronBoots::UseBoots() {
    static int k = -30;
    return k;
}

Swords* LeatherEquipment::createSword(){
    return new WoodSword;
}

Armor* LeatherEquipment::createArmor(){
    return new LeatherArmor;
}

Boots* LeatherEquipment::createBoots(){
    return new LeatherBoots;
}

int WoodSword::UseSword(){
    static int k = 20;
    return k;
}

int LeatherArmor::UseArmor(){
    static int k = 40;
    return k;
}

int LeatherBoots::UseBoots(){
    static int k = 30;
    return k;
}
