# standalone executable
/home/lchang21/llvm-release/llvm-9/bin/clang++ -g -std=c++17 /home/lchang21/taskflow/test-apps-dev/simple.cpp -I /home/lchang21/taskflow/ -pthread -o simple.exe

#show ast, in command line

/home/lchang21/llvm-release/llvm-9/bin/clang-check -ast-dump -ast-dump-filter=main /home/lchang21/taskflow/test-apps-dev/simple.cpp -- -std=c++17 -I /home/lchang21/taskflow/ -pthread