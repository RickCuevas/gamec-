#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_equipView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_equipView() : TActionView() { }
  QString toString();
};

QString game_equipView::toString()
{
  responsebody.reserve(776);
  responsebody += QLatin1String("\n");
  tfetch(QString, name);
  tfetch(QString, url);
  responsebody += QLatin1String("\n    <tr>\n      <td class=\"pika\"> <img src=\"https://files.gamebanana.com/img/ico/sprays/pokemon_running_side_animated.gif\" alt=\"\" /> </td>\n      <td class=\"chrm\"> <img src=\"");
  responsebody += THttpUtility::htmlEscape(url);
  responsebody += QLatin1String("\" alt=\"\" /> </td>\n\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\"> You found a .....");
  responsebody += THttpUtility::htmlEscape(name);
  responsebody += QLatin1String("!</a><br>\n          <a href=\"http://localhost:8800/Game/dice_roll\">> Continue?</a> <br>\n\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_equipView)

#include "game_equipView.moc"
