cmake_minimum_required(VERSION 2.8)
project (intialApp)

add_executable(app.out main.cpp)
target_link_libraries(app.out ${Boost_LIBRARIES})
target_link_libraries(app.out ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES})
if (Tcmalloc_FOUND)
	target_link_libraries(app.out ${Tcmalloc_LIBRARIES})
endif(Tcmalloc_FOUND)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -pg" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g -pg" )