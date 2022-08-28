cmake_minimum_required(VERSION 3.22)
project(ADMotor)

set(CMAKE_CXX_STANDARD 14)

# Pour ne pas utilisé la dépendance libstdc++6.dll
set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++" )
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc" )
set(CMAKE_EXE_LINKER_FLAGS "-static" )

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(ADMotor PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(ADMotor "${CMAKE_THREAD_LIBS_INIT}")
endif()

set(SDL2_INCLUDE_DIR "D:/PROGRAMMATION/Library/SDL2-2.0.22/include")

# Ajouter SDL2.dll dans les dépendance de windows (sous C:/Windows/System32 et C:/Windows/SysWOW64)
set(SDL2_LIB_DIR "D:/PROGRAMMATION/Library/SDL2-2.0.22/lib/x64")

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(HEADER header/Component/ADComponent.h header/ADMotor/ADWindow.h header/ADMotor/ADManagerComponent.h header/ADMotor/ADComposit.h header/ADMotor/ADObject.h header/ADMotor/ADManagerObject.h header/ADMotor/ADManagerWindow.h header/ADMotor/ADApplication.h header/Component/ADTransform.h header/Structure/Point3D.h header/Component/ADSprite.h)

set(SOURCE src/Component/ADComponent.cpp src/ADMotor/ADWindow.cpp src/ADMotor/ADManagerComponent.cpp src/ADMotor/ADComposit.cpp src/ADMotor/ADObject.cpp src/ADMotor/ADManagerObject.cpp src/ADMotor/ADManagerWindow.cpp src/ADMotor/ADApplication.cpp src/Component/ADTransform.cpp src/Component/ADSprite.cpp)

add_executable(ADMotor ${HEADER} ${SOURCE} main.cpp)

include_directories(header)
add_subdirectory(header)
add_subdirectory(ADMotorTests)

target_link_libraries(ADMotor SDL2main SDL2)
