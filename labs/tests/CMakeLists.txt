﻿add_executable(test_complex test_complex.cpp catch.hpp)
target_link_libraries(test_complex complex)

add_executable(test_dynamic_array test_dynamic_array.cpp catch.hpp)
target_link_libraries(test_dynamic_array dynamic_array)

add_executable(test_dynamic_array_t test_dynamic_array_t.cpp catch.hpp)
target_link_libraries(test_dynamic_array_t dynamic_array_t)

add_executable(test_matrix test_matrix.cpp catch.hpp)
target_link_libraries(test_matrix matrix)

add_executable(test_queue_on_array test_queue_on_array.cpp catch.hpp)
target_link_libraries(test_queue_on_array queue_on_array)

add_executable(test_queue_on_list test_queue_on_list.cpp catch.hpp)
target_link_libraries(test_queue_on_list queue_on_list)

add_executable(test_rational test_rational.cpp catch.hpp)
target_link_libraries(test_rational rational)

add_executable(test_stack_on_list test_stack_on_list.cpp catch.hpp)
target_link_libraries(test_stack_on_list stack_on_list)

add_executable(test_stack_on_array test_stack_on_array catch.hpp)
target_link_libraries(test_stack_on_array stack_on_array)

add_executable(test_priority_queue_on_list test_priority_queue_on_list.cpp catch.hpp)
target_link_libraries(test_priority_queue_on_list priority_queue_on_list)