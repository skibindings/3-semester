set(SOURCES dynamic_array.cpp dynamic_array.h)

add_library(dynamic_array ${SOURCES})
set_property(TARGET dynamic_array PROPERTY CXX_STANDARD 14)
