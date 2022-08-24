
set(ADSOURCE "")
message("start foreach")
foreach(FILE ${SOURCE})
    message(STATUS "file found ../../${FILE}")
    set(ADSOURCE ${ADSOURCE} "../../${FILE}")
endforeach()
message("end foreach")

add_executable(runADMotorUITest  main.cpp ${ADSOURCE} SDLWindowTest.cpp SDLWindowTest.h)

target_link_libraries(runADMotorUITest SDL2main SDL2)