#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_stagingView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_stagingView() : TActionView() { }
  QString toString();
};

QString game_stagingView::toString()
{
  responsebody.reserve(731);
  responsebody += QLatin1String("\n\n");
  tfetch(int, dice);
  responsebody += QLatin1String("\n    <tr>\n\n\n      <td class=\"pika\"> <img src=\"https://files.gamebanana.com/img/ico/sprays/pokemon_running_side_animated.gif\" alt=\"\" /> </td>\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">> Dice rolls.....</a><br>\n          <a href=\"#\">> You rolled a ...");
  responsebody += THttpUtility::htmlEscape(dice);
  responsebody += QLatin1String("   !</a><br>\n          <a href=\"http://localhost:8800/Game/loop\">> Explore</a><br>\n          <a href=\"http://localhost:8800/Game/staging\">> Continue</a> <br>\n\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_stagingView)

#include "game_stagingView.moc"
