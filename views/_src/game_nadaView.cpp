#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_nadaView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_nadaView() : TActionView() { }
  QString toString();
};

QString game_nadaView::toString()
{
  responsebody.reserve(516);
  responsebody += QLatin1String("\n\n\n\n    <tr>\n\n\n      <td class=\"pika\"> <img src=\"https://files.gamebanana.com/img/ico/sprays/pokemon_running_side_animated.gif\" alt=\"\" /> </td>\n      <td class=\"chmr\"> <img src=\"\" alt=\"\" /> </td>\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">> Nothing here....</a><br>\n\n          <a href=\"http://localhost:8800/Game/dice_roll\">> Continue</a>\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_nadaView)

#include "game_nadaView.moc"
