#include "Engine.h"

#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Revolt {

Engine::Engine() = default;

Engine::~Engine() = default;

void Engine::Initialize() {
    try {
        // Setup a multi-threaded, color-enabled console logger
        auto console = spdlog::stdout_color_mt("console");
        spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
        spdlog::set_level(spdlog::level::trace);

        spdlog::info("Logger initialized.");
        spdlog::info("Engine::Initialize() completed.");

        m_IsRunning = true;

    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
        m_IsRunning = false;
    }
}

void Engine::Run() {
    spdlog::info("Engine main loop started.");

    while (m_IsRunning) {
        // This is the main game loop.
        // For now, we will just log a message and exit to demonstrate functionality.
        spdlog::trace("Engine loop tick...");

        // In a real engine, this loop would handle:
        // 1. Input processing
        // 2. Game state updates (physics, AI, etc.)
        // 3. Rendering
        // 4. Frame timing and synchronization

        // For this example, we stop the loop immediately.
        m_IsRunning = false;
    }

    spdlog::info("Engine main loop finished.");
}

void Engine::Shutdown() {
    spdlog::info("Engine::Shutdown() called. Cleaning up resources.");
    // In a real engine, all subsystems would be terminated here.
    spdlog::info("Goodbye!");
}

} // namespace Revolt
