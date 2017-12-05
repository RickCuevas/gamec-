#include <QtCore>
#include <TreeFrogView>
#include "place.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT place_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  place_saveView() : TActionView() { }
  QString toString();
};

QString place_saveView::toString()
{
  responsebody.reserve(1791);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, place);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Place</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", place["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"place[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(place["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input type=\"text\" name=\"place[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(place["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"place[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(place["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Url<br /><input type=\"text\" name=\"place[url]\" value=\"");
  responsebody += THttpUtility::htmlEscape(place["url"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", place["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(place_saveView)

#include "place_saveView.moc"
