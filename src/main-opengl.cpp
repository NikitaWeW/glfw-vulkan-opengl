#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <thread>

class TriangleApplication {
public:
    void run() {
        initWindow();
        initOpengl();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;

    void initOpengl() {
        std::cout << "gladLoadGLLoader: " << gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) << '\n';

        std::cout << "gl version: " << glGetString(GL_VERSION) << '\n' << '\n';
    }

    void initWindow() {
        std::cout << "glfwInit: " << glfwInit() << '\n';

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(640, 480, "OpenGL", nullptr, nullptr);

        glfwMakeContextCurrent(window);

    }
    void mainLoop() {
        int iteration = 0;
        while(!glfwWindowShouldClose(window)) {
            std::cout << "loop " << iteration << " | gl error: " << glGetError() << '\n';

            glBegin(GL_TRIANGLES);

            glColor3d(1, 0, 0); glVertex2d(-0.5, -0.5);
            glColor3d(0, 1, 0); glVertex2d(0.5, -0.5);
            glColor3d(0, 0, 1); glVertex2d(0, 0.5);

            glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();

            iteration++;

            _sleep(1);
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
        
        std::cout << "\ncleanup completed.\n";
    }
};

int main() {
    TriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}