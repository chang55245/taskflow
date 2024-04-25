module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<!llvm.ptr, dense<64> : vector<4xi32>>, #dlti.dl_entry<f80, dense<128> : vector<2xi32>>, #dlti.dl_entry<i16, dense<16> : vector<2xi32>>, #dlti.dl_entry<i1, dense<8> : vector<2xi32>>, #dlti.dl_entry<i8, dense<8> : vector<2xi32>>, #dlti.dl_entry<f64, dense<64> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<270>, dense<32> : vector<4xi32>>, #dlti.dl_entry<f128, dense<128> : vector<2xi32>>, #dlti.dl_entry<f16, dense<16> : vector<2xi32>>, #dlti.dl_entry<i32, dense<32> : vector<2xi32>>, #dlti.dl_entry<i64, dense<64> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<271>, dense<32> : vector<4xi32>>, #dlti.dl_entry<!llvm.ptr<272>, dense<64> : vector<4xi32>>, #dlti.dl_entry<"dlti.stack_alignment", 128 : i32>, #dlti.dl_entry<"dlti.endianness", "little">>, llvm.data_layout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128", llvm.target_triple = "x86_64-unknown-linux-gnu", "polygeist.target-cpu" = "x86-64", "polygeist.target-features" = "+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87", "polygeist.tune-cpu" = "generic"} {
  llvm.mlir.global internal constant @str5("C\0A\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str4("B\0A\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str3("A\0A\00") {addr_space = 0 : i32}
  llvm.func @printf(!llvm.ptr, ...) -> i32
  llvm.mlir.global internal constant @str2("C\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str1("B\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str0("A\00") {addr_space = 0 : i32}
  llvm.func @main() -> i32 {
    %0 = llvm.mlir.constant(2 : index) : i64
    %1 = llvm.mlir.constant(1 : index) : i64
    %2 = llvm.alloca %1 x !llvm.array<2 x ptr> : (i64) -> !llvm.ptr
    %3 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %4 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %5 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %6 = llvm.mlir.undef : i32
    %7 = llvm.mlir.addressof @str0 : !llvm.ptr
    %8 = llvm.getelementptr %7[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %9 = llvm.load %8 : !llvm.ptr -> i8
    llvm.store %9, %5 : i8, !llvm.ptr
    %10 = llvm.getelementptr %7[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %11 = llvm.load %10 : !llvm.ptr -> i8
    %12 = llvm.getelementptr %5[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %11, %12 : i8, !llvm.ptr
    %13 = llvm.mlir.addressof @str1 : !llvm.ptr
    %14 = llvm.getelementptr %13[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %15 = llvm.load %14 : !llvm.ptr -> i8
    llvm.store %15, %4 : i8, !llvm.ptr
    %16 = llvm.getelementptr %13[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %17 = llvm.load %16 : !llvm.ptr -> i8
    %18 = llvm.getelementptr %4[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %17, %18 : i8, !llvm.ptr
    %19 = llvm.mlir.addressof @str2 : !llvm.ptr
    %20 = llvm.getelementptr %19[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %21 = llvm.load %20 : !llvm.ptr -> i8
    llvm.store %21, %3 : i8, !llvm.ptr
    %22 = llvm.getelementptr %19[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %23 = llvm.load %22 : !llvm.ptr -> i8
    %24 = llvm.getelementptr %3[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %23, %24 : i8, !llvm.ptr
    llvm.call @_ZN11taskflowLibC1Ev(%2) : (!llvm.ptr) -> ()
    %25 = llvm.mlir.addressof @_Z5funcAv : !llvm.ptr
    %26 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %5, %25) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %27 = llvm.mlir.addressof @_Z5funcBv : !llvm.ptr
    %28 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %4, %27) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %29 = llvm.mlir.addressof @_Z5funcCv : !llvm.ptr
    %30 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%2, %3, %29) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%2, %30, %28) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%2, %28, %26) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib7executeEv(%2) : (!llvm.ptr) -> ()
    llvm.return %6 : i32
  }
  llvm.func @_ZN11taskflowLibC1Ev(!llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib15task_definitionEPvPFvvE(!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr attributes {sym_visibility = "private"}
  llvm.func @_Z5funcAv() {
    %0 = llvm.mlir.addressof @str3 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %2 = llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    llvm.return
  }
  llvm.func @_Z5funcBv() {
    %0 = llvm.mlir.addressof @str4 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %2 = llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    llvm.return
  }
  llvm.func @_Z5funcCv() {
    %0 = llvm.mlir.addressof @str5 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %2 = llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    llvm.return
  }
  llvm.func @_ZN11taskflowLib14add_dependencyEPvS0_(!llvm.ptr, !llvm.ptr, !llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib7executeEv(!llvm.ptr) attributes {sym_visibility = "private"}
}
