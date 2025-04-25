#include "FileManager.h"
#include "Scene.h"
#include <Qt3DRender/QMesh>
#include <QUrl>
#include <qbuffer.h>
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

bool FileManager::parsingPlyToObject(const QString& filePath, Object* obj)
{
    //QFile file(filePath);
    //if (!file.open(QIODevice::ReadOnly)) {
    //    MessageBox(NULL, L"Filed to open file.", L"Warning", MB_OK);
    //    return false;
    //}

    //qDebug() << "Load PLY Model from Qt Resource: " << filePath;

    //QByteArray raw = file.readAll();
    //file.close();

    //struct PLY_info {
    //    bool bIsAscii = false;
    //    unsigned long ulVertexCount = 0;
    //    unsigned long ulFaceCount = 0;
    //    bool bHasNx = false, bHasNy = false, bHasNz = false;
    //    bool bHasRed = false, bHasGreen = false, bHasBlue = false;
    //    bool bHasIndices = false;
    //};

    //PLY_info stPLYinfo;

    //int iEndHeaderIdx = raw.indexOf("end_header\n");
    //if (iEndHeaderIdx < 0) {
    //    MessageBox(NULL, L"Unsupported file, PLY: end_header not found.", L"Warning", MB_OK);
    //    return false;
    //}

    //int iHeaderEndOffset = iEndHeaderIdx + QByteArray("end_header\n").size();

    //{
    //    QBuffer buf;
    //    buf.setData(raw.left(iHeaderEndOffset));
    //    buf.open(QIODevice::ReadOnly);
    //    QTextStream in(&buf);
    //    while (!in.atEnd()) {
    //        QString line = in.readLine().trimmed();
    //        if (line.startsWith("format ascii"))
    //            stPLYinfo.bIsAscii = true;
    //        else if (line.startsWith("element vertex")) {
    //            auto tok = line.split(' ', QString::SkipEmptyParts);
    //            stPLYinfo.ulVertexCount = tok[2].toULongLong();
    //        }
    //        else if (line.startsWith("element face")) {
    //            auto tok = line.split(' ', QString::SkipEmptyParts);
    //            stPLYinfo.ulFaceCount = tok[2].toULongLong();
    //        }
    //        else if (line.startsWith("property")) {
    //            auto tok = line.split(' ', QString::SkipEmptyParts);
    //            QString name = tok.last();

    //            if (name == "nx")
    //                stPLYinfo.bHasNx = true;
    //            else if (name == "ny")
    //                stPLYinfo.bHasNy = true;
    //            else if (name == "nz")
    //                stPLYinfo.bHasNz = true;
    //            else if (name == "red")
    //                stPLYinfo.bHasRed = true;
    //            else if (name == "green")
    //                stPLYinfo.bHasGreen = true;
    //            else if (name == "blue")
    //                stPLYinfo.bHasBlue = true;
    //            else if (name == "vertex_indices")
    //                stPLYinfo.bHasIndices = true;
    //        }
    //    }
    //    buf.close();
    //}

    //if (bIsMeshType) {
    //    if (stPLYinfo.ulFaceCount == 0 || !stPLYinfo.bHasIndices) {
    //        MessageBox(NULL, L"Unsupported file, PLY missing face ro indices.", L"Warning", MB_OK);
    //        return false;
    //    }
    //}
    //else {
    //    if (!(stPLYinfo.bHasNx && stPLYinfo.bHasNy && stPLYinfo.bHasNz)) {
    //        MessageBox(NULL, L"Unsupported file, PLY missing normals", L"Warning", MB_OK);
    //        return false;
    //    }
    //}

    //QVector<QVector3D> vcPosition;
    //QVector<QVector3D> vcNormal;
    //QVector<Eigen::Vector3b> vcDiffusion;
    //QVector<GLuint> vcMeshIdx;

    //const char* base = raw.constData();
    //const char* ptr = base + iHeaderEndOffset;

    //if (stPLYinfo.bIsAscii) {
    //    QBuffer buf;
    //    buf.setData(raw.mid(iHeaderEndOffset));
    //    buf.open(QIODevice::ReadOnly);
    //    QTextStream ts(&buf);

    //    for (unsigned long i = 0; i < stPLYinfo.ulVertexCount; ++i) {
    //        double dx, dy, dz;
    //        ts >> dx >> dy >> dz;
    //        vcPosition.append(QVector3D(float(dx), float(dy), float(dz)));

    //        QVector3D n(0, 0, 0);
    //        if (stPLYinfo.bHasNx) {
    //            ts >> dx >> dy >> dz;
    //            n = QVector3D(float(dx), float(dy), float(dz));
    //        }
    //        vcNormal.append(n);

    //        Eigen::Vector3b c(204, 204, 204);
    //        if (stPLYinfo.bHasRed) {
    //            int r, g, b;
    //            ts >> r >> g >> b;
    //            c = Eigen::Vector3b(unsigned char(r), unsigned char(g), unsigned char(b));
    //        }
    //        vcDiffusion.append(c);
    //    }
    //    for (unsigned long f = 0; f < stPLYinfo.ulFaceCount; ++f) {
    //        int cnt;
    //        ts >> cnt;
    //        if (cnt == 3) {
    //            int i0, i1, i2;
    //            ts >> i0 >> i1 >> i2;
    //            vcMeshIdx.append(GLuint(i0));
    //            vcMeshIdx.append(GLuint(i1));
    //            vcMeshIdx.append(GLuint(i2));
    //        }
    //        else {
    //            MessageBox(NULL, L"Unsupported file, PLY face is not triangular", L"Warning", MB_OK);
    //            return false;
    //        }
    //    }
    //    buf.close();
    //}
    //else {
    //    auto readF = [&](float& v) {
    //        memcpy(&v, ptr, 4);
    //        ptr += 4;
    //    };

    //    for (unsigned long i = 0; i < stPLYinfo.ulVertexCount; ++i) {
    //        float x, y, z;
    //        readF(x);
    //        readF(y);
    //        readF(z);

    //        vcPosition.append(QVector3D(x, y, z));

    //        QVector3D n(0, 0, 0);
    //        if (stPLYinfo.bHasNx) {
    //            float nx, ny, nz;
    //            readF(nx);
    //            readF(ny);
    //            readF(nz);
    //            n = QVector3D(nx, ny, nz);
    //        }
    //        vcNormal.append(n);

    //        unsigned char r = 204, g = 204, b = 204;
    //        if (stPLYinfo.bHasRed) {
    //            r = *ptr++;
    //            g = *ptr++;
    //            b = *ptr++;
    //        }
    //        vcDiffusion.append(Eigen::Vector3b(r, g, b));
    //    }

    //    for (unsigned long f = 0; f < stPLYinfo.ulFaceCount; ++f) {
    //        unsigned char cnt = *ptr++;
    //        if (cnt == 3) {
    //            int i0, i1, i2;
    //            memcpy(&i0, ptr, 4);
    //            ptr += 4;
    //            memcpy(&i1, ptr, 4);
    //            ptr += 4;
    //            memcpy(&i2, ptr, 4);
    //            ptr += 4;
    //            vcMeshIdx += {GLuint(i0), GLuint(i1), GLuint(i2)};
    //        }
    //        else {
    //            MessageBox(NULL, L"Unsupported file, PLY face is not triangular", L"Warning", MB_OK);
    //            return false;
    //        }
    //    }
    //}

    //kpNode->SetVertexCount(vcPosition.size());
    //kpNode->SetPrimitiveType(bIsMeshType ? PT_TRIANGLE_LIST_COLOR : PT_POINTS);
    //kpNode->SetMeshIndexCount(vcMeshIdx.size());
    //kpNode->SetPointIndexCount(vcPosition.size());

    //// position
    //kpNode->m_fpPositionBuffer = new float[3 * vcPosition.size()];
    //for (int i = 0; i < vcPosition.size(); ++i) {
    //    kpNode->m_fpPositionBuffer[3 * i + 0] = vcPosition[i].x();
    //    kpNode->m_fpPositionBuffer[3 * i + 1] = vcPosition[i].y();
    //    kpNode->m_fpPositionBuffer[3 * i + 2] = vcPosition[i].z();
    //}

    //// normal
    //if (!vcNormal.isEmpty()) {
    //    kpNode->m_fpNormalBuffer = new float[3 * vcNormal.size()];
    //    for (int i = 0; i < vcNormal.size(); ++i) {
    //        kpNode->m_fpNormalBuffer[3 * i + 0] = vcNormal[i].x();
    //        kpNode->m_fpNormalBuffer[3 * i + 1] = vcNormal[i].y();
    //        kpNode->m_fpNormalBuffer[3 * i + 2] = vcNormal[i].z();
    //    }
    //}

    //// diffuse
    //if (!vcDiffusion.isEmpty()) {
    //    kpNode->m_kpDiffuseBuffer = new Eigen::Vector3b[vcDiffusion.size()];
    //    memcpy(kpNode->m_kpDiffuseBuffer, vcDiffusion.constData(), sizeof(Eigen::Vector3b) * vcDiffusion.size());
    //}

    //// mesh index
    //if (!vcMeshIdx.isEmpty()) {
    //    kpNode->m_uipMeshIndexBuffer = new GLuint[vcMeshIdx.size()];
    //    memcpy(kpNode->m_uipMeshIndexBuffer, vcMeshIdx.constData(), sizeof(GLuint) * vcMeshIdx.size());
    //}

    //// point index
    //kpNode->m_uipPointIndexBuffer = new GLuint[vcPosition.size()];
    //for (int i = 0; i < vcPosition.size(); ++i)
    //    kpNode->m_uipPointIndexBuffer[i] = i;

    //if (bIsMeshType) {
    //    kpNode->SetOpacity(1.0f);
    //    kpNode->UpdateBoundingBox();
    //}

    //return true;
}