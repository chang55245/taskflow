module attributes {llvm.data_layout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128", llvm.target_triple = "x86_64-unknown-linux-gnu"} {
  llvm.mlir.global internal constant @str5("C\0A\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str4("B\0A\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str3("A\0A\00") {addr_space = 0 : i32}
  llvm.func @printf(!llvm.ptr, ...)
  llvm.mlir.global internal constant @str2("C\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str1("B\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str0("A\00") {addr_space = 0 : i32}
  llvm.func @main() {
    %0 = llvm.mlir.constant(2 : index) : i64
    %1 = llvm.mlir.constant(1 : index) : i64
    %2 = llvm.alloca %1 x !llvm.array<2 x ptr> : (i64) -> !llvm.ptr
    %3 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %4 = builtin.unrealized_conversion_cast %3 : !llvm.ptr to memref<2xi8>
    %5 = builtin.unrealized_conversion_cast %4 : memref<2xi8> to !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)>
    %6 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %7 = builtin.unrealized_conversion_cast %6 : !llvm.ptr to memref<2xi8>
    %8 = builtin.unrealized_conversion_cast %7 : memref<2xi8> to !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)>
    %9 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %10 = builtin.unrealized_conversion_cast %9 : !llvm.ptr to memref<2xi8>
    %11 = builtin.unrealized_conversion_cast %10 : memref<2xi8> to !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)>
    %12 = llvm.mlir.undef : i32
    %13 = llvm.mlir.addressof @str0 : !llvm.ptr
    %14 = llvm.getelementptr %13[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %15 = llvm.load %14 : !llvm.ptr -> i8
    %16 = llvm.mlir.constant(0 : index) : i64
    %17 = builtin.unrealized_conversion_cast %16 : i64 to index
    %18 = builtin.unrealized_conversion_cast %17 : index to i64
    %19 = llvm.extractvalue %11[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %20 = llvm.getelementptr %19[%18] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %15, %20 : i8, !llvm.ptr
    %21 = llvm.getelementptr %13[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %22 = llvm.load %21 : !llvm.ptr -> i8
    %23 = llvm.mlir.constant(1 : index) : i64
    %24 = builtin.unrealized_conversion_cast %23 : i64 to index
    %25 = builtin.unrealized_conversion_cast %24 : index to i64
    %26 = llvm.extractvalue %11[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %27 = llvm.getelementptr %26[%25] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %22, %27 : i8, !llvm.ptr
    %28 = llvm.mlir.addressof @str1 : !llvm.ptr
    %29 = llvm.getelementptr %28[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %30 = llvm.load %29 : !llvm.ptr -> i8
    %31 = llvm.mlir.constant(0 : index) : i64
    %32 = builtin.unrealized_conversion_cast %31 : i64 to index
    %33 = builtin.unrealized_conversion_cast %32 : index to i64
    %34 = llvm.extractvalue %8[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %35 = llvm.getelementptr %34[%33] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %30, %35 : i8, !llvm.ptr
    %36 = llvm.getelementptr %28[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %37 = llvm.load %36 : !llvm.ptr -> i8
    %38 = llvm.mlir.constant(1 : index) : i64
    %39 = builtin.unrealized_conversion_cast %38 : i64 to index
    %40 = builtin.unrealized_conversion_cast %39 : index to i64
    %41 = llvm.extractvalue %8[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %42 = llvm.getelementptr %41[%40] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %37, %42 : i8, !llvm.ptr
    %43 = llvm.mlir.addressof @str2 : !llvm.ptr
    %44 = llvm.getelementptr %43[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %45 = llvm.load %44 : !llvm.ptr -> i8
    %46 = llvm.mlir.constant(0 : index) : i64
    %47 = builtin.unrealized_conversion_cast %46 : i64 to index
    %48 = builtin.unrealized_conversion_cast %47 : index to i64
    %49 = llvm.extractvalue %5[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %50 = llvm.getelementptr %49[%48] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %45, %50 : i8, !llvm.ptr
    %51 = llvm.getelementptr %43[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %52 = llvm.load %51 : !llvm.ptr -> i8
    %53 = llvm.mlir.constant(1 : index) : i64
    %54 = builtin.unrealized_conversion_cast %53 : i64 to index
    %55 = builtin.unrealized_conversion_cast %54 : index to i64
    %56 = llvm.extractvalue %5[1] : !llvm.struct<(ptr, ptr, i64, array<1 x i64>, array<1 x i64>)> 
    %57 = llvm.getelementptr %56[%55] : (!llvm.ptr, i64) -> !llvm.ptr, i8
    llvm.store %52, %57 : i8, !llvm.ptr
    llvm.call @_ZN11taskflowLibC1Ev(%2) : (!llvm.ptr) -> ()
    %58 = llvm.mlir.addressof @_Z5funcAv : !llvm.ptr
    %59 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %9, %58) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %60 = llvm.mlir.addressof @_Z5funcBv : !llvm.ptr
    %61 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %6, %60) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %62 = llvm.mlir.addressof @_Z5funcCv : !llvm.ptr
    %63 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %3, %62) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%2, %63, %61) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%2, %61, %59) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib7executeEv(%2) : (!llvm.ptr) -> ()
    llvm.return
  }
  llvm.func @_ZN11taskflowLibC1Ev(!llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib15task_definitionEPvPFvvE(!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr attributes {sym_visibility = "private"}
  llvm.func @_Z5funcAv() {
    %0 = llvm.mlir.addressof @str3 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
   llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> ()
    llvm.return
  }
  llvm.func @_Z5funcBv() {
    %0 = llvm.mlir.addressof @str4 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> ()
    llvm.return
  }
  llvm.func @_Z5funcCv() {
    %0 = llvm.mlir.addressof @str5 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> ()
    llvm.return
  }
  llvm.func @_ZN11taskflowLib14add_dependencyEPvS0_(!llvm.ptr, !llvm.ptr, !llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib7executeEv(!llvm.ptr) attributes {sym_visibility = "private"}
}