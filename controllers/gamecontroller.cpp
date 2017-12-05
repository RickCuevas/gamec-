#include "gamecontroller.h"
#include "game.h"
#include "monster.h"
#include "weapon.h"
#include "player.h"
#include "item.h"
#include "../models/sqlobjects/playerobject.h"
#include "../models/sqlobjects/monsterobject.h"
#include "../models/sqlobjects/weaponobject.h"
#include "../models/sqlobjects/itemobject.h"
#include<array>
#include<cmath>

//w-5,18
//c-8,15
//g-11,22
//26 entrance
//27 dragon
std::array<int, 98> things_to_map = {{ 2, 3, 4,  6, 7, 9,10,  12, 13, 14, 16, 17, 19, 20, 21, 23, 24, 25,  28, 29, 31, 32, 33, 35, 36, 38, 39,  41, 42, 43, 45, 46, 48, 49, 50,  52, 53, 54,  57, 58,  60, 61, 62,  64, 65,  67, 68,  70, 71, 72,  74, 75,  77, 79, 79,  81, 82, 83,  86, 87,  89, 90, 91, 93, 94,  96, 97, 99, 100, 101,  103, 104,  106, 107, 108, 110, 111, 112,   115, 116, 118, 119, 120,  122, 123,  125, 126, 128,129, 130, 132, 133, 135, 136, 137, 139, 140, 141}};

int my_random(int i) { return rand() % i; }
int dice;
void GameController::index()
{
    auto gameList = Game::getAll();
    texport(gameList);
    render();
}

void GameController::show(const QString &id)
{
    auto game = Game::get(id.toInt());
    texport(game);
    render();
}

void GameController::welcome()
{
    render("welcome", "hello");
}

void GameController::reboot(){

    int monster_length = Monster::count();
    int weapon_length = Weapon::count();
    int item_length = Item::count();
    QList<Monster> monsters =  Monster::getAll();
    QList<Weapon> weapons = Weapon::getAll();
    QList<Item> items = Item::getAll();
    int count = 0;
    for (int i=0; i < monster_length -1; i++) {

            monsters[i].setSpace(things_to_map[count]);
            int monst_space = monsters[i].space();
            monsters[i].setHp(round(monst_space * .3));
            monsters[i].setAttack(round(monst_space * .5));
            monsters[i].update();
            count += 1;
    }
    for (int i=0; i < weapon_length -1; i++) {

            weapons[i].setSpace(things_to_map[count]);
            int weap_space = weapons[i].space();
            weapons[i].setAttack(round(weap_space * 2));
            weapons[i].setEquipped("false");
            weapons[i].setMain("false");
             weapons[i].update();
             count +=1;

    }
    for (int i=0; i < item_length -1; i++) {

            items[i].setSpace(things_to_map[count]);
            items[i].update();
            count +=1;
    }


    Player current_player = Player::get(1);
    current_player.setSpace(1);
    current_player.update();


    redirect( urla("staging") );
}

void GameController::seed()
{

    int weapon_length = Weapon::count();
    if (weapon_length > 3){
        redirect( urla("randomize_things_to_map") );
    }
    else {

    // Player current_player = Player::get(1);
    //
    // current_player.setSpace(1);
    // current_player.update();



    // if(weapon_length < 3) {
    // make player
    PlayerObject player1;
    player1.hp = 100;
    player1.space = 0;
    player1.alignment = "good";
    player1.name = "Rick";
    player1.create();



    //make monsters
    MonsterObject Polywhirl;
    Polywhirl.name = "Polywhirl";
    Polywhirl.space = things_to_map[0];
    Polywhirl.hp = 2 ;
    Polywhirl.attack = 2 ;
    Polywhirl.battle = "false" ;
    Polywhirl.url = "http://www.oocities.org/tokyo/blossom/9377/Koffing_Misc/Poliwhirl.gif" ;
    Polywhirl.create();
    MonsterObject Charmander;
    Charmander.name = "Charmander";
    Charmander.space = things_to_map[1];
    Charmander.hp = 2 ;
    Charmander.attack = 2 ;
    Charmander.battle = "false" ;
    Charmander.url = "http://fc02.deviantart.net/fs70/f/2011/174/0/d/charmander_by_sageraziel-d3jt9kq.gif" ;
    Charmander.create();
    MonsterObject Serpent;
    Serpent.name = "Serpent";
    Serpent.space = things_to_map[2];
    Serpent.hp = 2 ;
    Serpent.attack = 2 ;
    Serpent.battle = "false" ;
    Serpent.url = "https://pa1.narvii.com/6642/bcd71eb8ca74a8af0561b54e82a8d531e04af48e_128.gif" ;
    Serpent.create();
    MonsterObject Robot;
    Robot.name = "Robot";
    Robot.space = things_to_map[3];
    Robot.hp = 2 ;
    Robot.attack = 2 ;
    Robot.battle = "false" ;
    Robot.url = "http://www.animatedimages.org/data/media/118/animated-robot-image-0014.gif" ;
    Robot.create();
    MonsterObject Knight;
    Knight.name =  "Knight";
    Knight.space = things_to_map[4];
    Knight.hp = 2 ;
    Knight.attack = 2 ;
    Knight.battle = "false" ;
    Knight.url = "http://www.oocities.org/kevins_killa_gifs/warrior01.gif" ;
    Knight.create();
    MonsterObject SeaMonster;
    SeaMonster.name = "SeaMonster";
    SeaMonster.space = things_to_map[5];
    SeaMonster.hp = 2 ;
    SeaMonster.attack = 2 ;
    SeaMonster.battle = "false" ;
    SeaMonster.url = "https://orig00.deviantart.net/b32d/f/2017/038/1/2/1259aba8597166d46af82ded72f254f3-dayaa7q.gif" ;
    SeaMonster.create();
    MonsterObject EvilMushroom;
    EvilMushroom.name =  "EvilMushroom";
    EvilMushroom.space = things_to_map[6];
    EvilMushroom.hp = 2 ;
    EvilMushroom.attack = 2 ;
    EvilMushroom.battle = "false" ;
    EvilMushroom.url = "http://ludumdare.com/compo/wp-content/uploads/2015/09/BAD-MUSHROOM-walk2.gif" ;
    EvilMushroom.create();
    MonsterObject DarkGenie;
    DarkGenie.name = "DarkGenie";
    DarkGenie.space = things_to_map[7];
    DarkGenie.hp = 2 ;
    DarkGenie.attack = 2 ;
    DarkGenie.battle = "false" ;
    DarkGenie.url = "http://francoisegamma.computersclub.org/gifs/genie_e0.gif" ;
    DarkGenie.create();
    MonsterObject Rexy;
    Rexy.name = "Rexy" ;
    Rexy.space = things_to_map[8];
    Rexy.hp = 2 ;
    Rexy.attack = 2 ;
    Rexy.battle = "false" ;
    Rexy.url = "http://buttonshy.com/championland/PL-TDBG/TrexJump.gif" ;
    Rexy.create();
    MonsterObject DarkKnight;
    DarkKnight.name = "DarkKnight";
    DarkKnight.space = things_to_map[9];
    DarkKnight.hp = 2 ;
    DarkKnight.attack = 2 ;
    DarkKnight.battle = "false" ;
    DarkKnight.url = "https://orig00.deviantart.net/f150/f/2016/077/b/0/dark_souls_3___red_knight_by_zedotagger-d9vknnd.gif" ;
    DarkKnight.create();
    MonsterObject LordKnight;
    LordKnight.name = "LordKnight";
    LordKnight.space = things_to_map[10];
    LordKnight.hp = 2 ;
    LordKnight.attack = 2 ;
    LordKnight.battle = "false" ;
    LordKnight.url = "https://i.imgur.com/ZmMQJwB.gif" ;
    LordKnight.create();
    MonsterObject EvilKirby;
    EvilKirby.name = "EvilKirby" ;
    EvilKirby.space = things_to_map[11];
    EvilKirby.hp = 2 ;
    EvilKirby.attack = 2 ;
    EvilKirby.battle = "false" ;
    EvilKirby.url = "http://3.bp.blogspot.com/_IrdEB7DnyGc/Si76otEI4LI/AAAAAAAAALA/xtrxZSWWz2E/s400/sword-kirby.gif" ;
    EvilKirby.create();
    MonsterObject ElItaliano;
    ElItaliano.name = "ElItaliano";
    ElItaliano.space = things_to_map[12];
    ElItaliano.hp = 2 ;
    ElItaliano.attack = 2 ;
    ElItaliano.battle = "false" ;
    ElItaliano.url = "https://orig00.deviantart.net/de7a/f/2016/345/c/d/super_mario_run_by_t_free-daraj8q.gif" ;
    ElItaliano.create();
    MonsterObject Dragon;
    Dragon.name = "Dragon";
    Dragon.space = 27 ;
    Dragon.hp = 2 ;
    Dragon.attack = 2 ;
    Dragon.battle = "false" ;
    Dragon.url = "http://media.giphy.com/media/3o85xFeUIuMDHsLmFi/giphy.gif" ;
    Dragon.create();



    //
    //make weapons
    WeaponObject BroadSword;
    BroadSword.name = "BroadSword";
    BroadSword.space = things_to_map[15];
    BroadSword.attack = 2 ;
    BroadSword.equipped = "false" ;
    BroadSword.main = "false" ;
    BroadSword.url = "http://i.imgur.com/3p0tmCI.gif" ;
    BroadSword.create();
	WeaponObject Mace;
    Mace.name = "Mace";
    Mace.space = things_to_map[16];
    Mace.attack = 2 ;
    Mace.equipped = "false" ;
    Mace.main = "false" ;
    Mace.url = "https://www.shareicon.net/data/128x128/2015/11/01/665365_golf_512x512.png" ;
    Mace.create();
	WeaponObject Crossbow;
    Crossbow.name = "Crossbow";
    Crossbow.space = things_to_map[17];
    Crossbow.attack = 2 ;
    Crossbow.equipped = "false" ;
    Crossbow.main = "false" ;
    Crossbow.url = "https://www.shareicon.net/data/128x128/2016/09/02/823983_arrow_512x512.png" ;
    Crossbow.create();
	WeaponObject Flail;
    Flail.name = "Flail";
    Flail.space = things_to_map[18];
    Flail.attack = 2 ;
    Flail.equipped = "false" ;
    Flail.main = "false" ;
    Flail.url = "https://cdn1.iconfinder.com/data/icons/outlined-medieval-icons-pack/200/weapons_flail-128.png" ;
    Flail.create();
    WeaponObject Whip;
    Whip.name = "Whip";
    Whip.space = things_to_map[19];
    Whip.attack = 2 ;
    Whip.equipped = "false" ;
    Whip.main = "false" ;
    Whip.url= "https://findicons.com/files/icons/1236/indiana_jones_and_the_raiders_of_the_lost_ark/128/whip.png" ;
    Whip.create();
    WeaponObject Staff;
    Staff.name = "Staff";
    Staff.space = things_to_map[20];
    Staff.attack = 2 ;
    Staff.equipped = "false" ;
    Staff.main = "false" ;
    Staff.url = "https://cdn4.iconfinder.com/data/icons/witchcraft-icons/200/magic_staff-128.png" ;
    Staff.create();

    // make items

    ItemObject Curse1;
    Curse1.name = "Curse";
    Curse1.space = things_to_map[21];
    Curse1.url = "http://icons.iconarchive.com/icons/designcontest/vintage/128/Magic-Wand-icon.png";
    Curse1.create();
    ItemObject Curse2;
    Curse2.name = "Curse";
    Curse2.space = things_to_map[22];
    Curse2.url = "http://icons.iconarchive.com/icons/designcontest/vintage/128/Magic-Wand-icon.png";
    Curse2.create();
    ItemObject MagicRelic;
    MagicRelic.name = "MagicRelic";
    MagicRelic.space = things_to_map[23];
    MagicRelic.url = "https://cdn4.iconfinder.com/data/icons/free-crystal-icons/128/Citrine.png";
    MagicRelic.create();
    ItemObject Potion1;
    Potion1.name = "Potion";
    Potion1.space = things_to_map[24];
    Potion1.url = "http://dryicons.com/uploads/icon/preview/11351/icon_grid_1x_0fd38ac8-5986-4376-ae64-a831c663f194.png";
    Potion1.create();
    ItemObject Potion2;
    Potion2.name = "Potion";
    Potion2.space = things_to_map[25];
    Potion2.url = "http://dryicons.com/uploads/icon/preview/11351/icon_grid_1x_0fd38ac8-5986-4376-ae64-a831c663f194.png";
    Potion2.create();
}

 redirect( urla("staging") );

    // redirect_to *******
}

void GameController::loop()
{
//  int dice = rand() % 6 + 1;
Player current_player = Player::get(1);
// int current_player_space = current_player.space();
// current_player.setSpace(current_player_space += dice);

int monster_length = Monster::count();
int weapon_length = Weapon::count();
int item_length = Item::count();
QList<Monster> monsters =  Monster::getAll();
QList<Weapon> weapons = Weapon::getAll();
QList<Item> items = Item::getAll();

bool mfound = false;
bool wfound = false;
bool ifound = false;



for (int i=0; i < monster_length -1; i++) {
    if (monsters[i].space() == current_player.space()) {
        monsters[i].setBattle("true");
        monsters[i].update();

        mfound = true;
        // redirect( urla("battle") );
    }
}
for (int i=0; i < weapon_length -1; i++) {
    if (weapons[i].space() == current_player.space()) {
        // weapons[i].setEquipped("true");
        // weapons[i].update();

        wfound = true;
        // redirect( urla("equip_option") );
    }
}
for (int i=0; i < item_length -1; i++) {
    if (items[i].space() == current_player.space()) {
        ifound = true;


        // redirect( urla("equip_option") );
    }
}
if (){
    redirect( urla("reserved_space") );
}

else if (mfound == true){
    redirect( urla("battle") );
}
else if (wfound == true){
    redirect( urla("equip") );
}
else if (ifound == true){
    redirect( urla("equip") );
}


else  {
    redirect(urla("nada"));

}


}
void GemeController::reserved_space(){
    Player current_player = Player::get(1);
    int current_space =  current_player.space();
    if (current_space <= 30){
        modifier = 1;
    }
    else if (current_space<= 59){
        modifier = 2;
    }
    else if (current_space<= 88){
        modifier = 3;
    }
    else if (current_space<= 117){
        modifier = 4;
    }
    else if (current_space<= 146){
        modifier = 5;
    }
    else if (current_space<= 175){
        modifier = 6;
    }
    else if (current_space<= 204){
        modifier = 7;
    }
    else if (current_space<= 233){
        modifier = 8;
    }
    else if (current_space<= 262){
        modifier = 9;
    }
    else {
        modifier = 10;
    }

    //w-5,18
    //c-8,15
    //g-11,22
    //26 entrance
    //27 dragon

    if (current_space == ){

    }
    if(current_player.alignment() == "good"){
        current_player.setHp(round(current_player.hp() * 1.20));
        current_player.update();
    }
    else {
        current_player.setHp(round(current_player.hp() * .80));
        current_player.update();


    }
    render()
}
void GameController::nada() {
    render();
}

void GameController::equip(){
    Player current_player = Player::get(1);

    int weapon_length = Weapon::count();
    int item_length = Item::count();
    QList<Weapon> weapons = Weapon::getAll();
    QList<Item> items = Item::getAll();
    for (int i=0; i < weapon_length -1; i++) {
        if (weapons[i].space() == current_player.space()) {
            QString name = weapons[i].name();
            QString url = weapons[i].url();
            weapons[i].setEquipped("true");
            weapons[i].update();
            texport(name);
            texport(url);



        }
    }
    for (int i=0; i < item_length -1; i++) {
        if (items[i].space() == current_player.space()) {
            QString name = items[i].name();
            QString url = items[i].url();
            texport(name);
            texport(url);
            items[i].setSpace(1);
            items[i].update();




        }
    }


    render();

    // redirect(urla("loop"));
}

void GameController::staging() {
   dice = rand() % 6 + 1;
   Player current_player = Player::get(1);
   int current_player_space = current_player.space();
   current_player.setSpace(current_player_space += dice);
   current_player.update();
   int updated_player_space = current_player.space();
   texport(updated_player_space);
   texport(dice);
   render();
}

void GameController::battle()
{
    int monster_length = Monster::count();
    QList<Monster> monsters =  Monster::getAll();
    for (int i=0; i < monster_length -1; i++) {
        if (monsters[i].battle() == "true") {
            QString url = monsters[i].url();
            QString name = monsters[i].name();
            texport(url);
            texport(name);
            monsters[i].setBattle("false");
            monsters[i].update();


        }
    }
    // query to find  the monster that you will be fighting





    render();
}

void GameController::randomize_things_to_map() {


	std::random_shuffle(things_to_map.begin(), things_to_map.end(), my_random);
    redirect(urla("reboot"));

}

void GameController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto game = httpRequest().formItems("game");
        auto model = Game::create(game);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(game);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void GameController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Game::get(id.toInt());
        if (!model.isNull()) {
            session().insert("game_lockRevision", model.lockRevision());
            auto game = model.toVariantMap();
            texport(game);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("game_lockRevision").toInt();
        auto model = Game::get(id.toInt(), rev);

        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto game = httpRequest().formItems("game");
        model.setProperties(game);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(game);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void GameController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto game = Game::get(id.toInt());
    game.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(GameController)
