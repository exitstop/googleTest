set(SOIL_ROOT ${CMAKE_BINARY_DIR}/extern/SOIL)

include (ExternalProject)
ExternalProject_Add(SOIL
    PREFIX ${SOIL_ROOT}
    GIT_REPOSITORY git@github.com:exitstop/googleTest.git
    GIT_TAG master
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    )
# Показываем где лежат исходники
ExternalProject_Get_Property(SOIL source_dir)
set(SOIL_INCLUDE_DIRS ${source_dir}/main)

# Записываем здесь адрес где лежит скопиленная либа
ExternalProject_Get_Property(SOIL binary_dir)

set(SOIL_MY_COPYIF_LIBRARY_PATH ${binary_dir}/main/libmy_copyif.a)

file(MAKE_DIRECTORY ${SOIL_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${binary_dir}/main)
# Если не создать этот файл заглушку, то не соберется ничего
file(WRITE ${SOIL_MY_COPYIF_LIBRARY_PATH} "empty")

set(MY_SOIL my_soil)
add_library(${MY_SOIL} UNKNOWN IMPORTED)
add_dependencies(${MY_SOIL} SOIL)
set_target_properties(${MY_SOIL} PROPERTIES
    "IMPORTED_LOCATION" "${SOIL_MY_COPYIF_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${SOIL_INCLUDE_DIRS}")
