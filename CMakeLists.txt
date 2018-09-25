# バージョン指定
cmake_minimum_required(VERSION 3.12.2)
# コンパイラ指定
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# プロジェクト名
project(rl CXX)
# Cのバージョン指定
set(CMAKE_CXX_STANDARD 17)
# コンパイルオプション
set(CMAKE_CXX_FLAGS "-O2 -Wall")
# カレントディレクトリのソースファイル取得
file(GLOB sorces *.cpp)
# 実行ファイルと依存ファイル
add_executable(${PROJECT_NAME} ${sorces})
