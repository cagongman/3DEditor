#pragma once

#include <QObject>

class EditorMain;
class ViewerWidget;
class FileManager;

class UIController : public QObject {
    Q_OBJECT
public:
    explicit UIController(QObject* parent = nullptr);
    void setupConnections(EditorMain* window, ViewerWidget* viewer, FileManager* fileManager);
};
