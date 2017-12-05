#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT GameController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    GameController() : ApplicationController() {}

public slots:
    void index();
    void welcome();
    void loop();
    void seed();
    void battle();
    void equip();
    void nada();
    void dice_roll();
    void staging();
    void reboot();
    void player_attack();
    void monster_attack();
    void select_primary_weapon();
    void game_over();
    void run();
    void item_menu();
    void reserved_space();
    void weapon_menu();
    void randomize_things_to_map();
    void monster_defeated();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // GAMECONTROLLER_H
