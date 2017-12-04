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
  responsebody.reserve(864);
  responsebody += QLatin1String("\n\n");
  tfetch(QString, name);
  tfetch(QString, url);
  responsebody += QLatin1String("\n\n    <tr>\n      <td class=\"pika\"> <img src=\"https://files.gamebanana.com/img/ico/sprays/pokemon_running_side_animated.gif\" alt=\"\" /> </td>\n      <td class=\"chmr\"> <img src=\"");
  responsebody += THttpUtility::htmlEscape(url);
  responsebody += QLatin1String("\" alt=\"\" /> </td>\n      <!-- human -->\n\n\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">....Defeat ");
  responsebody += THttpUtility::htmlEscape(name);
  responsebody += QLatin1String("</a><br>\n          <a href=\"#\">> Attack</a><br>\n          <a href=\"#\">> Item</a> <br>\n          <a href=\"http://localhost:8800/Game/staging\">> Run</a>\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_battleView)

#include "game_battleView.moc"
