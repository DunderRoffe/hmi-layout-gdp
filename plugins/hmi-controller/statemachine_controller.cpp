#include "statemachine_controller.h"

#include <QDebug>

StatemachineController::StatemachineController(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    setAutoRelaySignals(true);
}

StatemachineController::~StatemachineController()
{
}

uint StatemachineController::shutdown()
{
    qDebug() << "Calling com.genivi.SimpleNodeStateMachine.Shutdown";
    // handle method call com.genivi.SimpleNodeStateMachine.Shutdown
    uint error;
    QMetaObject::invokeMethod(parent(), "Shutdown", Q_RETURN_ARG(uint, error));
    qDebug() << "Got response: " << error;
    return error;
}
