project(wxApp CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows -s")

set(wxWidgets_ROOT_DIR "C:/portableapps/msys64/mingw32/wx_install")

find_package(wxWidgets)

include_directories(
		includes
		C:/portableapps/msys64/mingw32/wx_install/include
		C:/portableapps/msys64/mingw32/wx_install/lib/gcc_lib/mswu
)


add_executable(${PROJECT_NAME}
	src/base.cpp
	src/includes/base.h
)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
