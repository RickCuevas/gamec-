#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  layouts_applicationView() : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(508);
  responsebody += QLatin1String("<!DOCTYPE html>\n\n\n\n<html lang=\"en\" >\n<head>\n  <meta charset=\"UTF-8\">\n  <title>Knight Rider</title>\n\n\n\n      <link rel=\"stylesheet\" href=\"/css/style.css\">\n\n\n</head>\n\n<body>\n  <table>\n      ");
  responsebody += QVariant(yield()).toString();
  responsebody += QLatin1String("\n\n</table>\n  <script src='http://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>\n\n    <script  src=\"js/index.js\"></script>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
