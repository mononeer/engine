#pragma once

#include "project/Project.h" // Include the new Project header
#include <memory>             // For std::unique_ptr

namespace Revolt {

    class Engine {
    public:
        Engine();
        ~Engine();

        /**
         * @brief Initializes the engine and all its subsystems.
         */
        void Initialize();

        /**
         * @brief Starts the main engine loop.
         */
        void Run();

        /**
         * @brief Shuts down the engine and cleans up resources.
         */
        void Shutdown();

        const Project& GetProject() const;

    private:
        bool m_IsRunning = false;
        std::unique_ptr<Project> m_Project;
    };

} // namespace Revolt
