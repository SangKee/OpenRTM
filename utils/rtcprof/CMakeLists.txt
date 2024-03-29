cmake_minimum_required (VERSION 3.5.1)
set(target rtcprof2)
project (${target}
	VERSION ${RTM_VERSION}
	LANGUAGES CXX)

link_directories(${ORB_LINK_DIR})
add_definitions(${ORB_C_FLAGS_LIST})
add_definitions(${COIL_C_FLAGS_LIST})
if(WIN32)
	add_definitions(-DRTM_SKEL_IMPORT_SYMBOL)
endif()

set(srcs rtcprof.cpp)

set(libs ${RTM_PROJECT_NAME} ${ORB_LIBRARIES} ${DATATYPE_FACTORIES})


add_executable(${target} ${srcs})
openrtm_common_set_compile_props(${target})
openrtm_set_link_props_shared(${target})
openrtm_include_rtm(${target})
target_link_libraries(${target} ${libs} ${RTM_LINKER_OPTION})

if(VXWORKS)
	if(RTP)
		set_target_properties(${target} PROPERTIES SUFFIX ".vxe")
	else(RTP)	
		set_target_properties(${target} PROPERTIES SUFFIX ".out")
	endif(RTP)
endif(VXWORKS)





if(WIN32)
	install(TARGETS ${target} LIBRARY DESTINATION ${INSTALL_RTM_LIB_DIR}
				RUNTIME DESTINATION ${INSTALL_RTM_LIB_DIR}
				COMPONENT utils)
else(WIN32)
	install(TARGETS ${target} LIBRARY DESTINATION ${INSTALL_RTM_LIB_DIR}
				RUNTIME DESTINATION ${INSTALL_RTM_BIN_DIR}
				COMPONENT utils)
endif(WIN32)
