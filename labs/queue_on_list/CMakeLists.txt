set(SOURCES queue_on_list.cpp queue_on_list.h)

add_library(queue_on_list ${SOURCES})
set_property(TARGET queue_on_list PROPERTY CXX_STANDARD 14)
