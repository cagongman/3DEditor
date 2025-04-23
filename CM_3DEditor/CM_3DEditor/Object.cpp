#include "Object.h"
#include "Geometry.h"
#include "Material.h"

Object::Object(std::shared_ptr<Geometry> geometry, std::shared_ptr<Material> material)
    : m_geometry(std::move(geometry)),
    m_material(std::move(material)) 
{

}

Object::~Object()
{
}

void Object::draw() {
    m_material->apply();
    m_geometry->draw();
}