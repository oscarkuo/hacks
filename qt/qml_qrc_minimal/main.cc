#include <QPushButton>
#include <QQuickView>
#include <QApplication>

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QQuickView view;
  view.setSource(QUrl("qrc:/qmlFiles/main.qml"));
  view.show();
  return app.exec();
}

