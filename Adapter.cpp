/*

The Adapter Pattern allows two incompatible classes to work together by acting as a bridge.
It's useful when you integrate third-party libraries or legacy code into your game.

Example in Games
Imagine your game originally used DirectX for rendering, but now you want to support OpenGL as well.
Instead of rewriting all rendering code, you can use an Adapter to make OpenGL calls compatible with your existing DirectX-based game engine.

Why Use Adapter?

Allows seamless integration of new APIs or libraries
Prevents rewriting existing code
Helps in legacy system compatibility

*/

#include <iostream>

// Old rendering system
class DirectXRenderer
{
public:
    virtual void renderDirectX()
    {
        std::cout << "Rendering using DirectX \n.";
    }
};

class OpenGLRenderer
{
public:
    void renderOpenGL()
    {
        std::cout << "Rendering using OpenGL \n";
    }
};

// Adapter -> Converts OpenGL calls to DirectX format
class OpenGLAdapter : public DirectXRenderer
{
private:
    OpenGLRenderer* openGL;
public:
    OpenGLAdapter(OpenGLRenderer* gl) : openGL(gl) {}

    void renderDirectX() override
    {
        openGL->renderOpenGL(); // Convert OpenGL call to DirectX compatible function
    }
};

int main()
{
    OpenGLRenderer opengl;
    OpenGLAdapter adapter(&opengl);

    adapter.renderDirectX(); // Calls OpenGL, but behaves like DirectX
}