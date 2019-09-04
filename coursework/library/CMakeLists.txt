set(SOURCES entrance.h json.h dirent.h 
layer.cpp layer.h 
placeholder.cpp placeholder.h 
placeholder_storage.cpp placeholder_storage.h 
actions_factory.cpp actions_factory.h 
base_action.cpp base_action.h 
data_action.cpp data_action.h
save_action.cpp save_action.h
grayscale_action.cpp grayscale_action.h
flip_action.cpp flip_action.h
rotate_action.cpp rotate_action.h
blur_action.cpp blur_action.h
pick_channels_action.cpp pick_channels_action.h
logger.cpp logger.h)
FIND_PACKAGE( OpenCV REQUIRED ) 
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
add_library(coursework  ${SOURCES})
#set_property(TARGET coursework PROPERTY CXX_STANDARD 14)
TARGET_LINK_LIBRARIES (coursework ${OpenCV_LIBS})  
