#ifndef STATEMACHINE_CONTROLLER_H
#define STATEMACHINE_CONTROLLER_H

#include <QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

class StatemachineController: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.genivi.SimpleNodeStateMachine")
    Q_CLASSINFO("D-Bus Introspection", ""
        "  <interface name=\"com.genivi.SimpleNodeStateMachine\">\n"
        "    <method name=\"Shutdown\">\n"
        "      <arg direction=\"out\" type=\"u\" name=\"error\"/>\n"
        "    </method>\n"
        "  </interface>\n"
        "")

public:
    StatemachineController(QObject* parent = nullptr);
    virtual ~StatemachineController();

public slots:
    uint shutdown();
};

#endif // STATEMACHINE_CONTROLLER_H
