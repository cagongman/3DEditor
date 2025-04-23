#pragma once
#include <vector>
#include <memory>

class Object;

class Scene 
{
public:
    Scene();
    void addObject(std::shared_ptr<Object> obj);
    const std::vector<std::shared_ptr<Object>>& objects() const;

private:
    std::vector<std::shared_ptr<Object>> m_objects;
};