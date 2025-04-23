#include "FileManager.h"
#include "Scene.h"
#include <Qt3DRender/QMesh>
#include <QUrl>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <QDebug>

FileManager::FileManager(QObject* parent)
    : QObject(parent) {}

bool FileManager::loadOBJ(const QString& path, Scene* scene) {
    // TODO: parse OBJ and add to scene

    Assimp::Importer importer;
    const aiScene* aiScene = importer.ReadFile(
        path.toStdString(),
        aiProcess_Triangulate |
        aiProcess_GenSmoothNormals |
        aiProcess_JoinIdenticalVertices
    );

    if (!aiScene || aiScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || aiScene->mNumMeshes == 0) {
        qWarning() << "Assimp OBJ load error: " << importer.GetErrorString();
        return false;
    }

    emit sceneUpdated();
    return true;
}

bool FileManager::loadPLY(const QString& path, Scene* scene) {
    // TODO: parse PLY and add to scene
    emit sceneUpdated();
    return true;
}