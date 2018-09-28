# プロジェクト名
project(rltest CXX)
# googletestのパスを定義
set(gtest googletest/googletest)
# includeディレクトリ指定
include_directories(${gtest}/include/)
# Library directory
link_directories(${gtest}/build/)
# カレントディレクトリのソースファイル取得
file(GLOB sorces *.cpp)
# 実行ファイルと依存ファイル
add_executable(${PROJECT_NAME} ${sorces})
# サブディレクトリ追加
add_subdirectory(${gtest})
# リンクライブラリ設定
target_link_libraries(${PROJECT_NAME} rl gtest gtest_main pthread)
