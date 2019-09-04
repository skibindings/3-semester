set(SOURCES matrix.cpp matrix.h)

add_library(matrix ${SOURCES})
set_property(TARGET rational PROPERTY CXX_STANDARD 14)
