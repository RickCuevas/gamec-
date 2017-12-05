#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_battleView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_battleView() : TActionView() { }
  QString toString();
};

QString game_battleView::toString()
{
  responsebody.reserve(1525);
  responsebody += QLatin1String("\n\n");
  tfetch(QString, monst_name);
  tfetch(QString, url);
  tfetch(QString, monst_hp);
  tfetch(QString, monst_attack);
  tfetch(QString, player_hp);
  tfetch(QString, player_attack);
  responsebody += QLatin1String("\n\n\n    <tr>\n      <td class=\"pika\"> <img src=\"https://files.gamebanana.com/img/ico/sprays/pokemon_running_side_animated.gif\" alt=\"\" /> </td>\n      <td class=\"chmr\"> <img src=\"");
  responsebody += THttpUtility::htmlEscape(url);
  responsebody += QLatin1String("\" alt=\"\" /> </td>\n      <!-- human -->\n\n\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">>>>>> Defeat ");
  responsebody += THttpUtility::htmlEscape(monst_name);
  responsebody += QLatin1String("  hp: ");
  responsebody += THttpUtility::htmlEscape(monst_hp);
  responsebody += QLatin1String(" attack: ");
  responsebody += THttpUtility::htmlEscape(monst_attack);
  responsebody += QLatin1String("</a><br>\n          <a href=\"#\">>>>>>   Player hp:");
  responsebody += THttpUtility::htmlEscape(player_hp);
  responsebody += QLatin1String(" attack:");
  responsebody += THttpUtility::htmlEscape(player_attack);
  responsebody += QLatin1String("</a><br>\n          <a href=\"http://localhost:8800/Game/player_attack\">> Attack</a><br>\n          <a href=\"http://localhost:8800/Game/item_menu\">> Item</a> <br>\n          <a href=\"http://localhost:8800/Game/run\">> Run</a>\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_battleView)

#include "game_battleView.moc"
