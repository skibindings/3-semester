set(SOURCES queue_on_array.cpp queue_on_array.h)

add_library(queue_on_array ${SOURCES})
set_property(TARGET queue_on_array PROPERTY CXX_STANDARD 14)
