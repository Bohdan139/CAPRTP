cmake_minimum_required(VERSION 3.16)


set(mysql-concpp_DIR "D:/mysql-connector-c++-9.3.0-winx64")

include_directories("${mysql-concpp_DIR}/include")
link_directories("${mysql-concpp_DIR}/lib64")
link_directories("${mysql-concpp_DIR}/lib64/vs14")

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        database.h database.cpp
        materialsdb.h materialsdb.cpp
        tabledb.h tabledb.cpp
        instrumentsdb.h instrumentsdb.cpp
        drillingmachinedb.h drillingmachinedb.cpp
        collector.h collector.cpp
        dbheaders.h
        feeddb.h feeddb.cpp
        kmvdb.h kmvdb.cpp
        tvaluedb.h tvaluedb.cpp
        tablevaluedb.h tablevaluedb.cpp
        prmdb.h prmdb.cpp
        mainalgorithm.h mainalgorithm.cpp
        result.h result.cpp
        abstractmath.h abstractmath.cpp
        drillingmath.h drillingmath.cpp
        restdata.h restdata.cpp
        resultform.h resultform.cpp resultform.ui
        kmpdb.h kmpdb.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CAPRTP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}














    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CAPRTP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CAPRTP SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CAPRTP
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CAPRTP PRIVATE mysqlcppconnx)
target_link_libraries(CAPRTP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CAPRTP)
endif()
set_target_properties(CAPRTP PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CAPRTP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CAPRTP)
endif()
