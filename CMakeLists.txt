cmake_minimum_required(VERSION 3.18)
set(CMAKE_BUILD_TYPE  "Release")
set(CMAKE_CXX_FLAGS   "-O3")
set(CMAKE_C_FLAGS     "-O3")
# add_definitions("-w")
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_install_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_install_RPATH "$ENV{HOME}/lib")
set(CMAKE_install_NAME_DIR "$ENV{HOME}/lib")



macro(DATE RESULT)
    if(WIN32)
        execute_process(COMMAND "cmd" " /C date /T" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE)
        string(REGEX REPLACE "(..)/(..)/(....).*" "\\3-\\2-\\1" ${RESULT} ${${RESULT}})
    elseif(UNIX)
        execute_process(COMMAND "date" "+%Y-%m-%d" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE)
    else()
        message(SEND_ERROR "Unable to detect date")
        set(${RESULT} UNKNOWN)
    endif()
endmacro()
macro(TIME RESULT)
    if(WIN32)
        execute_process(COMMAND "cmd" " /C echo %TIME%" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE)
        string(REGEX REPLACE "(..:..:..),(..)" "\\1" ${RESULT} ${${RESULT}})
    elseif(UNIX)
        execute_process(COMMAND "date" "+%H:%M:%S" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE)
    else()
        message(SEND_ERROR "Unable to detect time")
        set(${RESULT} UNKNOWN)
    endif()
endmacro()



project(libMedit)
#string(TIMESTAMP time "%Y-%m-%d %H:%M:%S")
DATE(day)
TIME(hour)
file(WRITE src/compil.date "#define COMPIL  \"${day} ${hour}\"")
file(                  GLOB_RECURSE sources src/*.c)
file(                  GLOB_RECURSE hea src/*.h)


include_directories( ./src/ )
include_directories( ./src/drawing/ )
# include_directories( ./src/formats/ )
include_directories( ./src/utilities/ )

if (APPLE)
        add_library(Medit3D STATIC ${sources})
        include_directories( /System/Library/Frameworks )
        find_library(COCOA_LIBRARY Cocoa)
        find_library(GLUT_LIBRARY GLUT )
        find_library(OpenGL_LIBRARY OpenGL )
        MARK_AS_ADVANCED(COCOA_LIBRARY
                         GLUT_LIBRARY
                         OpenGL_LIBRARY)
        SET(GL_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})

        target_link_libraries( Medit3D ${GL_LIBS})

elseif (EMSCRIPTEN)
        add_library(           Medit3D STATIC ${sources})
        set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s EXPORT_ALL=1 -s USE_GLFW=3 -s LLD_REPORT_UNDEFINED -s ERROR_ON_UNDEFINED_SYMBOLS=0") # -s LEGACY_GL_EMULATION=1 -s GL_UNSAFE_OPTS=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0") #"
        
        # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s BINARYEN_ASYNC_COMPILATION=1 -s WASM=1 -s BINARYEN=1 -s \"BINARYEN_METHOD='native-wasm'\" -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 -o app_wasm2.html")
        # Enable js output (no html).
        # set(CMAKE_EXECUTABLE_SUFFIX "_wasm.js")
        set(CMAKE_EXECUTABLE_SUFFIX "_emsdk.html")
        # add_definitions(-DUSE_WASM)
        add_executable(medit.html src/medit.c ${sources})


elseif (UNIX)
      add_compile_options(-Wall)
      add_library(Medit3D SHARED ${sources})
      find_package(GLUT REQUIRED)
      include_directories(${GLUT_INCLUDE_DIRS})
      link_directories(${GLUT_LIBRARY_DIRS})
      add_definitions(${GLUT_DEFINITIONS})
      if(NOT GLUT_FOUND)
            message(ERROR " GLUT not found!")
      endif(NOT GLUT_FOUND)
      find_package(OpenGL REQUIRED)
      include_directories(${OpenGL_INCLUDE_DIRS})
      link_directories(${OpenGL_LIBRARY_DIRS})
      add_definitions(${OpenGL_DEFINITIONS})
      if(NOT OPENGL_FOUND)
              message(ERROR " OPENGL not found!")
      endif(NOT OPENGL_FOUND)
      set(GL_LIBS ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

      target_link_libraries( Medit3D ${GL_LIBS})
      install(               TARGETS Medit3D LIBRARY  DESTINATION "$ENV{HOME}/lib")
      install(               FILES ${hea} DESTINATION "$ENV{HOME}/include")

ENDIF()

target_link_libraries( Medit3D ${GL_LIBS})


project(medit)
add_executable(        medit src/medit.c)
target_link_libraries( medit Medit3D ${GL_LIBS} -lglut)
install(               TARGETS medit RUNTIME DESTINATION "$ENV{HOME}/bin")

