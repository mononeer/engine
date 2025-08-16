#include "Engine.h"

/**
 * @brief The main entry point for the Revolt Engine application.
 *
 * @return int The exit code of the application.
 */
int main() {
    // Create the engine instance.
    // All application logic is encapsulated within the Engine class.
    Revolt::Engine engine;

    // Run the engine's lifecycle methods.
    engine.Initialize();
    engine.Run();
    engine.Shutdown();

    return 0;
}
