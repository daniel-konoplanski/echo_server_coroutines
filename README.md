# echo_server_coroutines

A simple echo server implemented in C++ using Boost.Asio and Boost.Cobalt for coroutine-based asynchronous I/O. The server listens on port 31415, accepts incoming TCP connections, reads data from clients, and echoes it back.

## Features

- **Coroutine-based asynchronous accepting, reading, and writing.** </br>
- **Handles multiple connections concurrently.** </br>
- **Logs connection details and data transfer sizes to the console.** </br>
- **Uses C++20 features like std::println for output.** </br>

## Dependencies

- GCC
- [vcpkg](https://github.com/Microsoft/vcpkg)
- [CMake](https://cmake.org/)
- [Ninja](https://ninja-build.org/)

Make sure all dependencies are installed and properly configured in your PATH.

## How to Build
<!-- 
```bash
1. Clone the repo
   # git clone https://github.com/yourname/bf_memhack_v2.git
   # cd bf_memhack_v2
2. Clone and bootstrap vcpkg
3. Run the build.sh script at the root of the project
``` -->

## Third-Party Libraries

**Boost.Asio**: For asynchronous I/O operations and TCP socket handling.
**Boost.Cobalt**: For coroutine support integrated with Asio, enabling co_await syntax.

## Screenshots

<!-- ![Menu](resources/images/menu.jpg)
![Nametags](resources/images/nametags.jpg)
![Maphack](resources/images/maphack.jpg)
![Nametags and Maphack](resources/images/nametags_and_maphack.jpg) -->
