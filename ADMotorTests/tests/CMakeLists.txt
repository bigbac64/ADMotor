include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(ADSOURCE "")
message("start foreach")
foreach(FILE ${SOURCE})
    message(STATUS "file found ../../${FILE}")
    set(ADSOURCE ${ADSOURCE} "../../${FILE}" ADObjectTest.cpp)
endforeach()
message("end foreach")

add_executable(runADMotorTest ${ADSOURCE}
        ADComponentTest.cpp ADManagerComponentTest.cpp ComponentTest.h ADManagerObjectTest.cpp RandomTest.cpp ADTransformTest.cpp)

target_link_libraries(runADMotorTest gtest gtest_main SDL2main SDL2)