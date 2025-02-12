# compile to llvm ir
/heorot/lchang21/llvm-release/llvm/bin/clang++ -g -std=c++17 /heorot/lchang21/taskflow/taskflow/test-apps-dev/simple.cpp -I /heorot/lchang21/taskflow/taskflow/ -S -emit-llvm -o simple.ll

# convert to demangled llvm ir

/heorot/lchang21/llvm-release/llvm/bin/llvm-cxxfilt < simple.ll > simple.demangled.ll

/heorot/lchang21/llvm-release/llvm/bin/llvm-cxxfilt _ZN2tf10ObjectPoolINS_4NodeELm65536EE7animateIJRA1_KciDnDniSt15in_place_type_tINS1_6StaticEEZ4mainE3
