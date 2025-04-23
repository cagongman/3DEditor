#include "FileManager.h"
#include "Scene.h"

FileManager::FileManager(QObject* parent)
    : QObject(parent) {}

bool FileManager::loadOBJ(const QString& path, Scene* scene) {
    // TODO: parse OBJ and add to scene
    emit sceneUpdated();
    return true;
}

bool FileManager::loadPLY(const QString& path, Scene* scene) {
    // TODO: parse PLY and add to scene
    emit sceneUpdated();
    return true;
}