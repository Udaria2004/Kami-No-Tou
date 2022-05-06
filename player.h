#include<bits/stdc++.h>

#ifndef KAMI_NO_TOU_PLAYER_H
#define KAMI_NO_TOU_PLAYER_H

using namespace std;

struct stats {
    int hp, mp, luck, potion, damage;
};

class player {
public:
    string name;
    stats player_stat;

    void print_stats();

    void get_char_type();

    void get_name();

    static void print_character_art();

    void assign_stats(int type);

    void init();
};

#endif
