# build

cmake ../

# compile test to llvm ir
/heorot/lchang21/llvm-release/llvm/bin/clang++ -std=c++17 /heorot/lchang21/taskflow/taskflow/taskflow-lib/test.cpp -I /heorot/lchang21/taskflow/taskflow/taskflow-lib/ -S -emit-llvm -o test.ll

