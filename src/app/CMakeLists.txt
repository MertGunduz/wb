add_executable(wb wb.c)
target_link_libraries(wb wbgen wbinfo)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )
target_link_libraries( wb ${CURSES_LIBRARIES} )