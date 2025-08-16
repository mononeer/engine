# Revolt Engine

Revolt Engine (RE) is a modern, high-performance, cross-platform game engine designed for desktop platforms (Windows and Linux). It is built with a data-oriented, modular, and performance-first philosophy.

## Core Design

*   **Language**: C++20, utilizing modern features like concepts, `constexpr`, coroutines, and ranges for performance, control, and safety.
*   **Engine Core**:
    *   **ECS (Entity-Component-System)**: A data-oriented design for cache-friendly and efficient game logic.
    *   **Job System**: A lock-free task graph for massively parallel and scalable multithreaded workloads.
    *   **Plugin Architecture**: All major subsystems (rendering, physics, audio, networking) are modular and can be extended or replaced.

## Features & Technology

Revolt Engine integrates a suite of best-in-class, battle-tested libraries for all major functionalities:

*   **Rendering**:
    *   Primary Backend: **Vulkan** for modern, explicit GPU control.
    *   Legacy Fallback: **OpenGL 4.6**.
    *   Libraries: **ShaderC**, **SPIRV-Cross**, **glm**, and **Dear ImGui** for debug UI.
*   **Physics**:
    *   Default: **Bullet Physics**.
    *   Optional: **NVIDIA PhysX**.
*   **Audio**:
    *   Default: **OpenAL Soft** for 3D positional audio.
    *   Optional: **miniaudio**.
*   **Asset Management**:
    *   Model Importing: **Assimp**.
    *   Texture/Audio Decoding: **stb_image**, **stb_vorbis**.
    *   GPU Texture Compression: **Basis Universal**.
*   **Scripting**:
    *   **LuaJIT** for lightweight, high-performance embedded scripting.
    *   **Python** for tooling and asset processing pipelines.
*   **Core Utilities**:
    *   Logging: **spdlog**.
    *   ECS: **EnTT** or a custom implementation.
    *   Job System: **Taskflow**, **folly**, or a custom implementation.

## Project Layout

The engine is organized into a modular structure:

```
/revolt
  /engine        # Core engine (ECS, job system, resource graph)
/modules
  /render        # Rendering backends (Vulkan, OpenGL)
  /physics       # Bullet/PhysX wrappers
  /audio         # OpenAL/miniaudio layer
  /scripting     # Lua/Python integration
/tools
  /editor        # Scene editor + material graph
  /profiler      # In-engine diagnostics
/assets          # Asset pipeline + importers
/tests           # Unit + integration tests
/docs            # Documentation
```

## Building from Source

The project uses **CMake** for a unified build system across Windows and Linux. Dependencies can be managed with **vcpkg** or **Conan**.

**Example Build (Linux):**

```bash
# 1. Clone the repository
git clone https://github.com/revolt/revolt-engine.git
cd revolt-engine

# 2. Configure CMake
# (Using Release mode for performance)
cmake -B build -DCMAKE_BUILD_TYPE=Release

# 3. Build the project
# This will use all available processor cores
cmake --build build -j$(nproc)
```

## Extending the Engine

Revolt's plugin architecture makes it highly extensible:

*   **New Backends**: Implement a new rendering backend (e.g., DirectX 12) by extending the RHI plugin.
*   **Gameplay Systems**: Add new ECS components and systems in C++ or Lua.
*   **AI/ML Integration**: Use the ECS and job system as a high-performance simulation framework. A Python bridge allows for easy connection to libraries like PyTorch or TensorFlow.
*   **Custom Tools**: Extend the editor with new panels and windows using Dear ImGui and the scripting layer.

---

*This README was generated based on the project's Build & Architecture Guide.*
