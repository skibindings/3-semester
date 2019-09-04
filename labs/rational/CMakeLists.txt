set(SOURCES rational.cpp rational.h)

add_library(rational ${SOURCES})
set_property(TARGET rational PROPERTY CXX_STANDARD 14)
