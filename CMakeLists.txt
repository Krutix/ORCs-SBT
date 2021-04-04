cmake_minimum_required(VERSION 3.7)

project(ORCsSBT VERSION 1.0.3.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(ORCsSBT
  src/ApplicationSettings.cpp
  src/ApplicationSettings.h
  src/DataTree.h
  src/DataTreeStorage.h
  src/DynamicWidgetList.cpp
  src/DynamicWidgetList.h
  src/Main.cpp
  src/MainWindow.cpp
  src/MainWindow.h
  src/MainWindow.ui
  src/MatchInfoWidget.cpp
  src/MatchInfoWidget.h
  src/MatchInfoWidget.ui
  src/PlayerListWidget.cpp
  src/PlayerListWidget.h
  src/PlayerListWidget.ui
  src/PlayerWidget.cpp
  src/PlayerWidget.h
  src/PlayerWidget.ui
  src/SettingsWidget.cpp
  src/SettingsWidget.h
  src/SettingsWidget.ui
  src/TeamWidget.cpp
  src/TeamWidget.h
  src/TeamWidget.ui
)

target_link_libraries(ORCsSBT PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
