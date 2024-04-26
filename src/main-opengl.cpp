#include <glad\glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        mainLoop();
        cleanup();
    }

private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
    GLFWwindow* window;

    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);
    }
    void mainLoop() {
        while(!glfwWindowShouldClose(window)) {
            glfwMakeContextCurrent(window);

            glOrtho(0, 640, 480, 0, -1, 1);
            std::cout << "loop";
            
            glClearColor(1,1,0,0);

            glClear(GL_COLOR_BUFFER_BIT);
            
            glBegin(GL_TRIANGLES);
            glVertex2d(-2, -1);
            glVertex2d(2, -1);
            glVertex2d(0, 1);
            glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}