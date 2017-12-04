#include <QtCore>
#include <TreeFrogView>
#include "item.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT item_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  item_createView() : TActionView() { }
  QString toString();
};

QString item_createView::toString()
{
  responsebody.reserve(1394);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, item);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Item</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Space<br /><input name=\"item[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(item["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input name=\"item[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(item["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Url<br /><input name=\"item[url]\" value=\"");
  responsebody += THttpUtility::htmlEscape(item["url"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(item_createView)

#include "item_createView.moc"
