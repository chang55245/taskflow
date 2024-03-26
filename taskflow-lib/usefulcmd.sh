/home/lchang21/llvm-release/llvm-9/bin/clang++ -S -O0 -emit-llvm -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.ll


/home/lchang21/llvm-release/llvm-9/bin/clang++ -g -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.exe