#pragma once
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <vector>

class Geometry {
public:
    Geometry(const std::vector<float>& vertices,
        const std::vector<float>& normals,
        const std::vector<unsigned int>& indices);
    ~Geometry();
    void draw();
private:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLBuffer m_ebo;
    int m_indexCount;
};
