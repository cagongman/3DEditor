#include "Material.h"

Material::Material(const QString& vertexPath, const QString& fragmentPath) {
    program_.addShaderFromSourceFile(QOpenGLShader::Vertex, vertexPath);
    program_.addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentPath);
    program_.link();
}

void Material::apply() {
    program_.bind();
    // TODO: set uniforms
}

Material::~Material()
{
}