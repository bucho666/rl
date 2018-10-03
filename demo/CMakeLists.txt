# プロジェクト名
project(demo CXX)
# includeディレクトリ指定
include_directories(../)
# demoを定義
set(demos cellular random)
foreach(demo ${demos})
  # 実行ファイルと依存ファイル
  add_executable(${demo} ${demo}.cpp)
  # リンクライブラリ設定
  target_link_libraries(${demo} rl)
endforeach()
