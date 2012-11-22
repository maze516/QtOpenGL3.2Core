#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtGlobal>

#if defined(Q_OS_WIN32) || defined(Q_OS_WIN64)
#include <GL/glew.h>
#else
#include <OpenGL/gl3.h>
#endif

#include <QGLContext>
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget( const QGLFormat& format, QWidget* parent = 0 );

protected:
    virtual void initializeGL();
    virtual void resizeGL( int w, int h );
    virtual void paintGL();


private:
    GLuint prepareShaderProgram( const QString& vertexShaderPath,
                               const QString& fragmentShaderPath );

    GLuint m_shader;
    GLuint m_vertexBuffer;
};

#if defined(Q_OS_MAC)
void* select_3_2_mac_visual(GDHandle handle);
#endif

struct Core3_2_context : public QGLContext {
    Core3_2_context(const QGLFormat& format, QPaintDevice* device) : QGLContext(format,device) {}
    Core3_2_context(const QGLFormat& format) : QGLContext(format) {}

#if defined(Q_OS_MAC)
    virtual void* chooseMacVisual(GDHandle handle) {
        return select_3_2_mac_visual(handle);
    }
#endif
};

#endif // GLWIDGET_H
