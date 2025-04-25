#pragma once

#include <QObject>
#include <QString>

class Scene;

class FileManager : public QObject {
    Q_OBJECT
public:
    explicit FileManager(QObject* parent = nullptr);
    bool loadOBJ(const QString& path, Scene* scene);
    bool loadPLY(const QString& path, Scene* scene);
 
private:
    bool parsingPlyToObject(const QString& filePath, Object* obj);

signals:
    void sceneUpdated();
};
