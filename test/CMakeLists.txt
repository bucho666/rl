# プロジェクト名
project(rltest CXX)
# googletestのパスを定義
set(googletest googletest/googletest)
# includeディレクトリ指定
include_directories(${googletest}/include/)
# Library directory
link_directories(${googletest}/build/)
# カレントディレクトリのソースファイル取得
file(GLOB sorces *.cpp)
# 実行ファイルと依存ファイル
add_executable(${PROJECT_NAME} ${sorces})
# サブディレクトリ追加
add_subdirectory(${googletest})
# リンクライブラリ設定
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
