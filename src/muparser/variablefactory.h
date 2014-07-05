#ifndef VARIABLEFACTORY_H
#define VARIABLEFACTORY_H

#include <iostream>
#include <map>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>

class VariableFactory : public QObject
{
    Q_OBJECT
public:
    VariableFactory(QObject *parent = 0);

    void createNewVariable(const QString &name);
    void setValue(const QString &name, double value);

    double* getVariableAddress(const QString &name) {
        return &(mVariables[name]);
    }

    bool hasVariable(const QString &name) const {
        return (mVariables.find(name) != mVariables.end());
    }

    QStringList getVariableNames() const {
        return mVariables.keys();
    }

    void deleteOthers(const QStringList& varsInUse);

    QMap<QString, double> saveValues() const {
        return mVariables;
    }

private:
    /**
     * Careful, encapsulation will be broken by myParser: the values will be directly manipulated.
     * When manually using this struct, you should rather use the provided functions
     **/
    QMap<QString, double> mVariables;

signals:
    void variableChanged(const QString& name);
    void newVariableCreated(const QString& name);
};

#endif // VARIABLEFACTORY_H
