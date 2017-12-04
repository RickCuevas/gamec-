#include <QtCore>
#include <TreeFrogView>
#include "game.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT game_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_createView() : TActionView() { }
  QString toString();
};

QString game_createView::toString()
{
  responsebody.reserve(851);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, game);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Game</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_createView)

#include "game_createView.moc"
