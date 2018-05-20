#include <iostream>
#include <vector>
#include "Equipment.h"



int Composite_of_Material::Power_of_material(){
        int power = 0;
        if (store.size()>0){
            for (int i = 0; i < store.size(); ++i){
                power += store[i]->Power_of_material();
            }
            return power;
        } else {
            return 0;
        }
}

void Composite_of_Material::Add_Material(Material* m){
        store.push_back(m);
}

void Person::ShowEquipment(Person &p){
    p.power = 0;
    p.skill = 0;
    p.defen = 0;
    int i;
    int k = 0;
    cout << "Attack: ";
    for(i = 0; i < sw.size(); ++i){
        sw[i]->UseSword(p);
    }
    cout << p.power + p.storage->Power_of_material()<< endl;
    k = 0;
    cout << "Defense: ";
    for(i = 0; i < ar.size(); ++i){
        ar[i]->UseArmor(p);
    }
    cout << p.defen << endl;
    cout << "Skill: ";
    for(i = 0; i < bo.size(); ++i){
        bo[i]->UseBoots(p);
    }
    cout << p.skill << endl;
    cout << "Rune stone: ";
    cout << storage->Power_of_material() << endl;
    cout << "Health: ";
    cout << health << endl;
}
void Decorate_Sword::UseSword(Person& p){
    modern_sw->UseSword(p);
}

void Decorate_Armor::UseArmor(Person& p){
    modern_ar->UseArmor(p);
}
void Decorate_Boots::UseBoots(Person& p){
    modern_bo->UseBoots(p);
}

void Jagged::UseSword(Person &p){
    Decorate_Sword::UseSword(p);
    p.health -= 50;
}

void Rough::UseArmor(Person &p){
    Decorate_Armor::UseArmor(p);
    p.health -= 30;
}
void Poisonous::UseSword(Person &p){
    Decorate_Sword::UseSword(p);
        p.health  -= 100;
}

void Spiny::UseBoots(Person &p){
    Decorate_Boots::UseBoots(p);
    p.health -= 50;
}

Armor* IronEquipment::createArmor() {
    return new IronArmor;
}

Boots* IronEquipment::createBoots() {
    return new IronBoots;
}

Swords* IronEquipment::createSword() {
    return new IronSword;
}

void IronSword::UseSword(Person& p) {
    static int k = 40;
    p.power += k;
}

void IronArmor::UseArmor(Person& p) {
    static int k = 80;
    p.defen += k;
}

void IronBoots::UseBoots(Person& p) {
    static int k = -30;
    p.skill += k;
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

void WoodSword::UseSword(Person& p){
    static int k = 20;
    p.power += k;
}

void LeatherArmor::UseArmor(Person& p){
    static int k = 40;
    p.defen += k;
}

void LeatherBoots::UseBoots(Person& p){
    static int k = 30;
    p.skill += k;
}

