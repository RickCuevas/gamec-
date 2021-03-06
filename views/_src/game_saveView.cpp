#include <QtCore>
#include <TreeFrogView>
#include "game.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT game_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_saveView() : TActionView() { }
  QString toString();
};

QString game_saveView::toString()
{
  responsebody.reserve(1194);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, game);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Game</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", game["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"game[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(game["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", game["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_saveView)

#include "game_saveView.moc"
