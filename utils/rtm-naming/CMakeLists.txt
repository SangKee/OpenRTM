cmake_minimum_required (VERSION 3.5.1)

if(CORBA STREQUAL "ORBexpress")
elseif(CORBA STREQUAL "omniORB")
	if(UNIX)
		if(NOT ORB_ROOT)
			execute_process(COMMAND which omniNames OUTPUT_VARIABLE COSNAMES)
			string(REGEX REPLACE "\n" "" COSNAMES "${COSNAMES}")
		else()
			set(COSNAMES ${ORB_ROOT}/bin/omniNames)
		endif()
		if(COSNAMES)
			configure_file(${CMAKE_CURRENT_SOURCE_DIR}/rtm-naming.in ${PROJECT_BINARY_DIR}/rtm2-naming @ONLY)
			install(FILES ${PROJECT_BINARY_DIR}/rtm2-naming DESTINATION ${INSTALL_RTM_BIN_DIR} COMPONENT utils PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_READ WORLD_EXECUTE)
		else()
			message(WARNING "Please Install omniorb-nameserver")
		endif()
	elseif(WIN32)
		install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/rtm-naming.bat DESTINATION ${INSTALL_RTM_SCRIPT_DIR} COMPONENT utils)
		install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kill-rtm-naming.bat DESTINATION ${INSTALL_RTM_SCRIPT_DIR} COMPONENT utils)
	endif()
elseif(CORBA STREQUAL "TAO")
endif()
