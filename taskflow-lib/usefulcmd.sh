# llvm ir
/home/lchang21/llvm-release/llvm-9/bin/clang++ -S -O0 -emit-llvm -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.ll

# standalone executable
/home/lchang21/llvm-release/llvm-9/bin/clang++ -g -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.exe

# static library
/home/lchang21/llvm-release/llvm-9/bin/clang++ -c -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.o
/home/lchang21/llvm-release/llvm-9/bin/llvm-ar rcs lib.a lib.o

# use this static library
/home/lchang21/llvm-release/llvm-9/bin/clang++ -g -std=c++17 /home/lchang21/taskflow/taskflow-lib/use.cpp -I /home/lchang21/taskflow/taskflow-lib/ -pthread lib.a -o use.exe


# show ast
/home/lchang21/llvm-release/llvm-9/bin/clang-check -ast-dump -ast-dump-filter=main /home/lchang21/taskflow/taskflow-lib/use.cpp -- -std=c++17 -I /home/lchang21/taskflow/taskflow-lib/ -pthread

