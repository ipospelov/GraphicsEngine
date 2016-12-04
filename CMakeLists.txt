cmake_minimum_required(VERSION 3.6)
project(GraphicsEngine)
#include_directories ("${PROJECT_SOURCE_DIR}/GraphicsEngine")
# add extra include directories
include_directories("${PROJECT_SOURCE_DIR}/Sources")
#include_directories("${PROJECT_SOURCE_DIR}/FreeImage")

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ) #${FREEIMAGE_LIBRARY_DIRRECTORY})



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lfreeimage -lglut -lGL -lGLU -lGLEW")



set(SOURCE_FILES
    SDKs/OpenGL/include/GL/freeglut.h
    SDKs/OpenGL/include/GL/freeglut_ext.h
    SDKs/OpenGL/include/GL/freeglut_std.h
    SDKs/OpenGL/include/GL/glew.h
    SDKs/OpenGL/include/GL/glut.h
    SDKs/OpenGL/include/GL/glxew.h
    SDKs/OpenGL/include/GL/wglew.h
    SDKs/OpenGL/include/FreeImage.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Convert.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngine.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngine.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngineFabric.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngineFabric.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GUI.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GUI.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Material.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Material.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Mesh.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Mesh.h
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Texture2D.cpp
    Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Texture2D.h
    Sources/GraphicsEngine/GraphicsApi/FixedFunctionPipelineImpl.h
    Sources/GraphicsEngine/GraphicsApi/GraphicsEngineContext.h
    Sources/GraphicsEngine/GraphicsApi/GraphicsEngineFabricImpl.h
    Sources/GraphicsEngine/GraphicsApi/GraphicsEngineImpl.h
    Sources/GraphicsEngine/GraphicsApi/GUIImpl.h
    Sources/GraphicsEngine/GraphicsApi/MaterialImpl.h
    Sources/GraphicsEngine/GraphicsApi/MeshImpl.h
    Sources/GraphicsEngine/GraphicsApi/PixelShaderImpl.h
    Sources/GraphicsEngine/GraphicsApi/Texture2DImpl.h
    Sources/GraphicsEngine/GraphicsApi/VertexShaderImpl.h
    Sources/GraphicsEngine/Materials/Material.cpp
    Sources/GraphicsEngine/Materials/Material.h
    Sources/GraphicsEngine/Materials/MaterialDiffuse.cpp
    Sources/GraphicsEngine/Materials/MaterialDiffuse.h
    Sources/GraphicsEngine/Materials/MaterialSand.cpp
    Sources/GraphicsEngine/Materials/MaterialSand.h
    Sources/GraphicsEngine/Materials/MaterialTask01.cpp
    Sources/GraphicsEngine/Materials/MaterialTask01.h
    Sources/GraphicsEngine/Materials/MaterialUnlit.cpp
    Sources/GraphicsEngine/Materials/MaterialUnlit.h
    Sources/GraphicsEngine/Meshes/Mesh.cpp
    Sources/GraphicsEngine/Meshes/Mesh.h
    Sources/GraphicsEngine/Meshes/MeshCube.cpp
    Sources/GraphicsEngine/Meshes/MeshCube.h
    Sources/GraphicsEngine/Meshes/MeshCylinder.cpp
    Sources/GraphicsEngine/Meshes/MeshCylinder.h
    Sources/GraphicsEngine/Meshes/MeshObjFile.cpp
    Sources/GraphicsEngine/Meshes/MeshObjFile.h
    Sources/GraphicsEngine/Meshes/MeshQuad.cpp
    Sources/GraphicsEngine/Meshes/MeshQuad.h
    Sources/GraphicsEngine/Meshes/MeshSphere.cpp
    Sources/GraphicsEngine/Meshes/MeshSphere.h
    Sources/GraphicsEngine/Meshes/MeshTriangle.cpp
    Sources/GraphicsEngine/Meshes/MeshTriangle.h
    Sources/GraphicsEngine/PlatformApi/Windows/WinWindow.cpp
    Sources/GraphicsEngine/PlatformApi/Windows/WinWindow.h
    Sources/GraphicsEngine/PlatformApi/Platform.h
    Sources/GraphicsEngine/Application.cpp
    Sources/GraphicsEngine/Application.h
    Sources/GraphicsEngine/Camera.cpp
    Sources/GraphicsEngine/Camera.h
    Sources/GraphicsEngine/Component.h
    Sources/GraphicsEngine/Directory.cpp
    Sources/GraphicsEngine/Directory.h
    Sources/GraphicsEngine/File.h
    Sources/GraphicsEngine/GraphicsEngine.cpp
    Sources/GraphicsEngine/GraphicsEngine.h
    Sources/GraphicsEngine/GraphicsEngineFabric.cpp
    Sources/GraphicsEngine/GraphicsEngineFabric.h
    Sources/GraphicsEngine/GUI.cpp
    Sources/GraphicsEngine/GUI.h
    Sources/GraphicsEngine/KeyCode.h
    Sources/GraphicsEngine/Light.h
    Sources/GraphicsEngine/Math.h
    Sources/GraphicsEngine/MathConstants.h
    Sources/GraphicsEngine/MathUtils.h
    Sources/GraphicsEngine/Matrix4x4.h
    Sources/GraphicsEngine/Object.cpp
    Sources/GraphicsEngine/Object.h
    Sources/GraphicsEngine/Rect.h
    Sources/GraphicsEngine/resource.h
    Sources/GraphicsEngine/Scene.cpp
    Sources/GraphicsEngine/Scene.h
    Sources/GraphicsEngine/SceneUtils.h
    Sources/GraphicsEngine/Screen.cpp
    Sources/GraphicsEngine/Screen.h
    Sources/GraphicsEngine/Texture2D.cpp
    Sources/GraphicsEngine/Texture2D.h
    Sources/GraphicsEngine/Time.cpp
    Sources/GraphicsEngine/Time.h
    Sources/GraphicsEngine/Transform.cpp
    Sources/GraphicsEngine/Transform.h
    Sources/GraphicsEngine/tstring.h
    Sources/GraphicsEngine/Vector3.cpp
    Sources/GraphicsEngine/Vector3.h
    Sources/GraphicsEngine/Vector4.h
    Sources/Tasks/ObjectRotator.h
    Sources/Tasks/Task.h
    Sources/Tasks/Task01.h
    Sources/Tasks/Task04.h
    Sources/Tasks/Task05_01.h
    Sources/main.cpp Sources/Tasks/Task02.h Sources/GraphicsEngine/Materials/MaterialSphere.h Sources/GraphicsEngine/Materials/MaterialSphere.cpp Sources/GraphicsEngine/Materials/MaterialCylinder.h Sources/GraphicsEngine/Materials/MaterialCylinder.cpp Sources/GraphicsEngine/Materials/MaterialSpecular.h Sources/GraphicsEngine/Materials/MaterialSpecular.cpp Sources/Tasks/Task05_02.h Sources/GraphicsEngine/Materials/MaterialRoad.cpp Sources/GraphicsEngine/Materials/MaterialRoad.h Sources/Tasks/Task05_03.h Sources/GraphicsEngine/Materials/MaterialEarth.cpp Sources/GraphicsEngine/Materials/MaterialEarth.h Sources/Tasks/Task6.h)

find_package( OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
#FIND_LIBRARY(FREEIMAGE REQUIRED)
link_libraries(freeimage)
#[[add_library(freeimage STATIC IMPORTED)
set_property(TARGET freeimage PROPERTY
        IMPORTED_LOCATION FreeImage/libfreeimage.a)]]
#find_package(FREEIMAGE)

#find_package(FreeImage REQUIRED)


add_executable(GraphicsEngine ${SOURCE_FILES})

target_link_libraries(GraphicsEngine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES})#${freeimageplus})