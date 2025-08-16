#pragma once

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

    private:
        bool m_IsRunning = false;
    };

} // namespace Revolt
