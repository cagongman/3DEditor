#include "Scene.h"
#include "Object.h"

Scene::Scene() {}

void Scene::addObject(std::shared_ptr<Object> obj) {
    m_objects.push_back(std::move(obj));
}

const std::vector<std::shared_ptr<Object>>& Scene::objects() const {
    return m_objects;
}