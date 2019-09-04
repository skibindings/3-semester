set(SOURCES complex.cpp complex.h)
add_library(complex ${SOURCES})
set_property(TARGET rational PROPERTY CXX_STANDARD 14)