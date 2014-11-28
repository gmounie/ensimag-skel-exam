cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(Ensisepc)
enable_testing()
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Werror -O3 -std=gnu99")

#########
# Gestion des logins
#########
# Vous devez editer la ligne suivante pour y mettre votre login
#########
set(LOGINS login1)
list(SORT LOGINS)

if (LOGINS MATCHES "login1")
  message(FATAL_ERROR "** ERREUR / ERROR **: Vous devez modifier CMakeLists.txt pour remplacer login1 par votre login / Substitute login1 with your own login in CMakeLists.txt")
endif()



#####
# Détection de la bibliothèque de threads et de la bibliothèque de math
#####
find_package(Threads)
find_library(MISC_LIBRARY NAMES m libm rt librt)


##
# Si vous utilisez d'autres fichiers .c, en plus de ceux listés,
# il faut les ajouter ici
##
add_executable(ensisepc src/main.c  src/prodconso.c)
target_link_libraries(ensisepc ${CMAKE_THREAD_LIBS_INIT} m rt)
add_executable(validateur tests/validateur.c)


##
# Programme de test
##
add_test(TestNoValgrind ../tests/validite.pl 0)
add_test(TestValgrindMemcheck ../tests/validite.pl 1)
add_test(TestValgrindHelgrind ../tests/validite.pl 2)
add_test(TestValgrindDrd ../tests/validite.pl 3)
add_custom_target(check ../tests/validite.pl 0)

##
# Construction de l'archive (inutile ?)
##
string(REPLACE ";" "-" LOGINS_SANS_POINTVIRGULE "${LOGINS}")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH ${LOGINS_SANS_POINTVIRGULE})
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES
  "~$"
  "\\\\.o$"
  "^${PROJECT_SOURCE_DIR}/build/"
  "^${PROJECT_SOURCE_DIR}/.git/"
)
include(CPack)
