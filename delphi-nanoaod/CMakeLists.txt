set (CMAKE_CXX_STANDARD 17)

configure_file(src/skelana.cra.in skelana.cra)
ypatchy(skelana.f ${CMAKE_CURRENT_BINARY_DIR}/skelana.cra)


add_executable(delphi-nanoaod src/delphi-nanoaod.cpp src/nanoaod_writer.cpp ${CMAKE_CURRENT_BINARY_DIR}/skelana.f)

target_compile_options(delphi-nanoaod PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-ftemplate-depth=50>) # argpase
target_include_directories(delphi-nanoaod PRIVATE ${ROOT_INCLUDE_DIRS})
target_include_directories(delphi-nanoaod PRIVATE ${CMAKE_BINARY_DIR}/delphi-nanoaod/include) # version header
target_include_directories(delphi-nanoaod PRIVATE ${CMAKE_SOURCE_DIR}/delphi-nanoaod/include)

target_link_libraries(delphi-nanoaod argparse yaml-cpp delphi-analysis)
target_link_libraries(delphi-nanoaod ROOT::Core ROOT::RIO ROOT::ROOTNTuple)
target_link_dellibs(delphi-nanoaod skelana phdst dstana pxdst vfclap vdclap ufield bsaurus herlib trigger uhlib dstana)
target_link_cernlibs(delphi-nanoaod genlib packlib kernlib ariadne herwig jetset74)
target_link_libraries(delphi-nanoaod gfortran)


# version header
add_custom_target(version ALL
    COMMAND ${CMAKE_COMMAND} 
      -D PROJECT_SOURCE_DIR=${CMAKE_SOURCE_DIR}
      -D SRC=${CMAKE_SOURCE_DIR}/delphi-nanoaod/include/delphi-nanoaod_version.hpp.in
      -D DST=${CMAKE_BINARY_DIR}/delphi-nanoaod/include/delphi-nanoaod_version.hpp 
      -P ${CMAKE_SOURCE_DIR}/cmake/version.cmake
    COMMENT "Creating version header"
    VERBATIM
    )

add_dependencies(delphi-nanoaod version)