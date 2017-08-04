#set(CMAKE_CXX_FLAGS "-fpermissive -p -O2")
set(CMAKE_CXX_FLAGS "-fpermissive -p -g -Wall -pthread -DCC_TARGET_PLATFORM=linux")
#SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_BUILD_TYPE Debug)
file(GLOB_RECURSE sources_SERVER_SHARE ../pitayaserver/framework/*.cpp ../pitayaserver/framework/*.h)
file(GLOB sources_GAMESERVER ../gameserver/*.cpp ../gameserver/*.h)
file(GLOB_RECURSE sources_SHARE ../../share/*.cpp ../../share/*.h)
file(GLOB_RECURSE sources_except ../pitayaserver/framework/main.cpp ../Lua* ../gameserver/Lua*)
list(REMOVE_ITEM sources_GAMESERVER ${sources_except})
list(REMOVE_ITEM sources_SERVER_SHARE ${sources_except})

file(GLOB sources *.cpp *.h)

set(Gameserver_STAT_SRCS
  ${sources}
  ${sources_SERVER_SHARE}
  ${sources_GAMESERVER}
  ${sources_SHARE}
)

#message(status " ================= ")
#message(status " This is the server_share srcs:" ${sources_SERVER_SHARE})
#message(status " This is the share srcs:" ${sources_SHARE})
#message(status " This is the gameserver srcs:" ${sources_GAMESERVER})
#message(status " ================= ")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../pitayaserver/framework
  ${CMAKE_CURRENT_SOURCE_DIR}/../../share
  ${CMAKE_CURRENT_SOURCE_DIR}/../dep/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../gameserver
  # /usr/include/lua5.1
)
LINK_DIRECTORIES(
  /usr/local/lib
)
add_executable(test ${Gameserver_STAT_SRCS})
target_link_libraries(test event)
target_link_libraries(test zthread)
target_link_libraries(test mysqlclient)
target_link_libraries(test miniini)
#target_link_libraries(test tolua++5.1)
#target_link_libraries(test lua5.1)
target_link_libraries(test event_pthreads)
target_link_libraries(test tcmalloc) 
