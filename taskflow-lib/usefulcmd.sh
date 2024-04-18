# llvm ir
/home/lchang21/llvm-release/llvm-9/bin/clang++ -S -O0 -emit-llvm -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.ll

# static library
/home/lchang21/llvm-release/llvm-9/bin/clang++ -c -std=c++17 /home/lchang21/taskflow/taskflow-lib/lib.cpp -I /home/lchang21/taskflow/ -pthread -o lib.o
/home/lchang21/llvm-release/llvm-9/bin/llvm-ar rcs lib.a lib.o

# use this static library
/home/lchang21/llvm-release/llvm-9/bin/clang++ -g -std=c++17 /home/lchang21/taskflow/taskflow-lib/use.cpp -I /home/lchang21/taskflow/taskflow-lib/ -pthread lib.a -o use.exe


# show ast, in command line
/home/lchang21/llvm-release/llvm-9/bin/clang-check -ast-dump -ast-dump-filter=main /home/lchang21/taskflow/taskflow-lib/use.cpp -- -std=c++17 -I /home/lchang21/taskflow/taskflow-lib/ -pthread

# show ast, print to a file
/home/lchang21/llvm-release/llvm-9/bin/clang++ -Xclang -ast-dump -fsyntax-only -fno-color-diagnostics -Wno-visibility /home/lchang21/taskflow/taskflow-lib/use.cpp -I /home/lchang21/taskflow/taskflow-lib/ -pthread > ast.txt

# polygeist

CPLUS_INCLUDE_PATH=/home/lchang21/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/17.0.3/clangd_17.0.3/lib/clang/17/include/ /heorot/lchang21/llvm/Polygeist/build/bin/cgeist -std=c++17 /heorot/lchang21/taskflow/taskflow/taskflow-lib/use.cpp -I /heorot/lchang21/taskflow/taskflow/taskflow-lib/ --function=main -S