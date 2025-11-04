//
// Created by Taj Miller on 11/2/25.
//

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

struct Pokemon {
    std::string imgURL; // http://www.serebii.net/xy/pokemon/[Pokemon.num].png  - have to figure out how to do that in SFML :3
    int num;
    std::string name;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int spd;
    int total;
    std::string type1;
    std::string type2;
    std::string ability1;
    std::string ability2;
    std::string abilityHidden;
    std::string ev; // effort value
    std::string gender; // "M/F (percentage)" MAYBE DON'T DISPLAY, IRRELEVANT
    std::string eg1; // egg group 1 MAYBE DON'T DISPLAY, IRRELEVANT
    std::string eg2; // egg group 2 MAYBE DON'T DISPLAY, IRRELEVANT
    std::string catchNum; // MAYBE DONT DISPLAY, IRRELEVANT
    std::string evolution; // condition/s to evolve
    int generation;
    std::string region; // first region in which it appears
};

#endif //POKEMON_H
