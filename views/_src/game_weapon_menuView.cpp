#include <QtCore>
#include <TreeFrogView>
#include "weapon.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT game_weapon_menuView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_weapon_menuView() : TActionView() { }
  QString toString();
};

QString game_weapon_menuView::toString()
{
  responsebody.reserve(1130);
    responsebody += QLatin1String("\n\n\n");
  int weapon_length = Weapon::count();
  QList<Weapon> weapons = Weapon::getAll();
  responsebody += QLatin1String("\n\n\n    <tr>\n        ");
  for(int i = 0; i < weapon_length; i++) {
  responsebody += QLatin1String("\n            ");
  if( weapons[i].equipped() == "true") {
  responsebody += QLatin1String("                ");
  QString name = weapons[i].name();
  responsebody += QLatin1String("\n                <a href=\"http://localhost:8800/Game/select_primary_weapon?key=");
  responsebody += THttpUtility::htmlEscape(name);
  responsebody += QLatin1String("\"><img src=\"");
  responsebody += THttpUtility::htmlEscape(weapons[i].url());
  responsebody += QLatin1String("\" alt=\"\" ></a>\n            ");
  };
  responsebody += QLatin1String("\n        ");
  };
  responsebody += QLatin1String("\n\n\n\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">....Select your weapon</a><br>\n          <a href=\"http://localhost:8800/Game/staging\">> Return</a><br>\n\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_weapon_menuView)

#include "game_weapon_menuView.moc"
