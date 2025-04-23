#pragma once
#include <memory>

class Geometry;
class Material;

class Object {
public:
    Object(std::shared_ptr<Geometry> geometry, std::shared_ptr<Material> material);
    ~Object();
    void draw();
private:
    std::shared_ptr<Geometry> m_geometry;
    std::shared_ptr<Material> m_material;
};