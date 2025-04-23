#include "Geometry.h"
#include <QOpenGLFunctions>

Geometry::Geometry(const std::vector<float>& vertices,
    const std::vector<float>& normals,
    const std::vector<unsigned int>& indices)
    : m_vbo(QOpenGLBuffer::VertexBuffer),
    m_ebo(QOpenGLBuffer::IndexBuffer),
    m_indexCount(indices.size()) {
    m_vao.create();
    m_vao.bind();
    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vertices.data(), vertices.size() * sizeof(float));
    // TODO: setup vertex attributes
    m_ebo.create();
    m_ebo.bind();
    m_ebo.allocate(indices.data(), indices.size() * sizeof(unsigned int));
    m_vao.release();
}

Geometry::~Geometry() 
{

}

void Geometry::draw() {
    m_vao.bind();
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
    f->glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
    m_vao.release();
}