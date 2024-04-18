# standalone executable
/heorot/lchang21/llvm-release/llvm/bin/clang++ -g -std=c++17 /heorot/lchang21/taskflow/taskflow/test-apps-dev/simple.cpp -I /heorot/lchang21/taskflow/taskflow/ -pthread -o simple.exe

/heorot/lchang21/llvm-release/llvm/bin/clang++ -g -std=c++11 /heorot/lchang21/taskflow/taskflow/test-apps-dev/simple.cpp -I /heorot/lchang21/taskflow/taskflow/ -pthread -o simple.exe

#show ast, in command line

/heorot/lchang21/llvm-release/llvm/bin/clang-check -ast-dump -ast-dump-filter=main /heorot/lchang21/taskflow/taskflow/test-apps-dev/simple.cpp -- -std=c++17 -I /heorot/lchang21/taskflow/taskflow -pthread


/heorot/lchang21/llvm/Polygeist/build/bin/cgeist /heorot/lchang21/taskflow/taskflow/test-apps-dev/simple.cpp


/heorot/lchang21/llvm/Polygeist/build/bin/cgeist -I /heorot/lchang21/taskflow/taskflow/ /heorot/lchang21/llvm/Polygeist/tools/cgeist/Test/Verification/constexpr.cpp --function=* -show-ast -S


# polygeist
CPLUS_INCLUDE_PATH=/home/lchang21/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/17.0.3/clangd_17.0.3/lib/clang/17/include/ /heorot/lchang21/llvm/Polygeist/build/bin/cgeist -std=c++17 -I /heorot/lchang21/taskflow/taskflow/ simple.cpp --function=main -show-ast  -S
