#include<bits/stdc++.h>

#ifndef KAMI_NO_TOU_PLAYER_H
#define KAMI_NO_TOU_PLAYER_H

using namespace std;

struct stats {
    int hp, mp, luck, potion, damage;
};

class player {
public:
    int location = 0, c_type;
    bool guild_quest = false;
    string name, char_type;
    stats player_stat;

    void print_stats() const;

    void get_char_type();

    void get_name();

    static void print_character_art();

    void assign_stats(int type);

    void init();

    void get_location(bool print_locs);
};

#endif
