set(SOURCES dynamic_array_t.cpp dynamic_array_t.h)

add_library(dynamic_array_t ${SOURCES})
set_property(TARGET dynamic_array_t PROPERTY CXX_STANDARD 14)
