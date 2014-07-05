#include "variablefactory.h"
#include <QDebug>
#include <QStringList>

VariableFactory::VariableFactory(QObject *parent) : QObject(parent)
{
}

void VariableFactory::createNewVariable(const QString &name)
{
    if(mVariables.find(name) != mVariables.end()) {
        //qDebug() << "VariableFactory::createNewVariable() - Var " << name << " already exists";
        //qDebug() << "var "<<name<<" has value "<<mVariables[name];
    } else {
        //qDebug() << "VariableFactory::createNewVariable() - Creating var " << name << " already exists";
        mVariables[name] = 0;
        emit newVariableCreated(name);
    }
}

void VariableFactory::setValue(const QString &name, double value)
{
    mVariables[name] = value;
    emit variableChanged(name);
}

void VariableFactory::deleteOthers(const QStringList& varsInUse)
{
    foreach(QString key, mVariables.keys()) {
        if(!varsInUse.contains(key)) {
            qDebug() << "VariableFactory::deleteOthers() - removing var " << key;
            mVariables.remove(key);
        }
    }
}
