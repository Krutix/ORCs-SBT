set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(ORCsSBT
  ApplicationSettings.cpp
  DynamicWidgetList.cpp
  DataTree.cpp
  DataTreeStorage.cpp
  Main.cpp
  Widgets/MainWindow.cpp
  Widgets/MainWindow.ui
  Widgets/MatchInfoWidget.cpp
  Widgets/MatchInfoWidget.ui
  Widgets/PlayerListWidget.cpp
  Widgets/PlayerListWidget.ui
  Widgets/PlayerWidget.cpp
  Widgets/PlayerWidget.ui
  Widgets/SettingsWidget.cpp
  Widgets/SettingsWidget.ui
  Widgets/TeamWidget.cpp
  Widgets/TeamWidget.ui
)

target_include_directories(ORCsSBT PUBLIC ./ Widgets/)

target_link_libraries(ORCsSBT PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
