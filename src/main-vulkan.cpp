#include <vulkan/vulkan.hpp>
#include <KHR/khrplatform.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
public:
    void run() {
        initGLFW();
        createVulkanInstance();
        createWindow();

        mainLoop();

        cleanup();
    }

private:
    GLFWwindow* window;
    VkInstance instance;

    void initGLFW() {
        glfwInitVulkanLoader(vkGetInstanceProcAddr);
        std::cout << "glfw init result (bool): " << glfwInit() << '\n';
    }
    void createVulkanInstance() {
        VkApplicationInfo appInfo = {};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.apiVersion = VK_API_VERSION_1_3;

        const char* instanceExtenstions[2] = { "VK_KHR_surface", "VK_KHR_win32_surface" };
        const char* enabledLayers[1] = { "VK_LAYER_KHRONOS_validation" };

        VkInstanceCreateInfo createInfo = {};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;
            createInfo.enabledExtensionCount = 2;
            createInfo.ppEnabledExtensionNames = instanceExtenstions;
            createInfo.enabledLayerCount = 1;
            createInfo.ppEnabledLayerNames = enabledLayers;

        VkResult instanceResult = vkCreateInstance(&createInfo, nullptr, &instance);
            std::cout << "vk instance result (bool): " << (instanceResult == VK_SUCCESS) << '\n';
            if(instanceResult != VK_SUCCESS) throw std::exception();
    }
    void createWindow() {
        if(window) glfwSetWindowShouldClose(window, GLFW_TRUE); //window exists

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(640, 480, "Vulkan", nullptr, nullptr);
        std::cout << "window: " << window << '\n';
        if(!window) throw std::exception();
    }

    void mainLoop() {
        while(!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
        std::cout << "window closed" << '\n';
    }

    void cleanup() {
        vkDestroyInstance(instance, nullptr);
        
        glfwDestroyWindow(window);

        glfwTerminate();

        std::cout << "cleanup sucsessful" << '\n';
    }
};

int main() {
    HelloTriangleApplication app;

    try { app.run(); } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}