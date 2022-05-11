include(CPM)

###############################################
# Catch 2
###############################################
if(DDL_BUILD_TESTING)
    CPMAddPackage("gh:catchorg/Catch2@2.13.9")
endif()