#include "Engine.h"

#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "project/Project.h"

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

        spdlog::info("Loading project file...");
        // Use make_unique to create the Project instance on the heap
        m_Project = std::make_unique<Project>(Project::Load("revolt.project.json"));
        spdlog::info("Successfully loaded project '{}' (v{})", m_Project->name, m_Project->version);
        spdlog::debug("Engine minimum version required: {}", m_Project->engine_min);

        spdlog::info("Engine::Initialize() completed.");

        m_IsRunning = true;

    } catch (const std::exception& ex) {
        // This will catch errors from spdlog, file I/O, or JSON parsing.
        spdlog::critical("Fatal error during engine initialization: {}", ex.what());
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

const Project& Engine::GetProject() const {
    // A more robust implementation would check if m_Project is null.
    // For now, we assume Initialize() has been called successfully.
    return *m_Project;
}

} // namespace Revolt
