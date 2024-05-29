module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<i32, dense<32> : vector<2xi32>>, #dlti.dl_entry<i16, dense<16> : vector<2xi32>>, #dlti.dl_entry<f16, dense<16> : vector<2xi32>>, #dlti.dl_entry<f64, dense<64> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr, dense<64> : vector<4xi32>>, #dlti.dl_entry<i8, dense<8> : vector<2xi32>>, #dlti.dl_entry<i1, dense<8> : vector<2xi32>>, #dlti.dl_entry<i64, dense<64> : vector<2xi32>>, #dlti.dl_entry<f80, dense<128> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<270>, dense<32> : vector<4xi32>>, #dlti.dl_entry<f128, dense<128> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<271>, dense<32> : vector<4xi32>>, #dlti.dl_entry<!llvm.ptr<272>, dense<64> : vector<4xi32>>, #dlti.dl_entry<"dlti.endianness", "little">, #dlti.dl_entry<"dlti.stack_alignment", 128 : i32>>, llvm.data_layout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128", llvm.target_triple = "x86_64-unknown-linux-gnu", "polygeist.target-cpu" = "x86-64", "polygeist.target-features" = "+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87", "polygeist.tune-cpu" = "generic"} {
  llvm.mlir.global internal constant @str4("C\0A\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str3("A\0A\00") {addr_space = 0 : i32}
  llvm.func @printf(!llvm.ptr, ...) -> i32
  llvm.mlir.global internal constant @str2("C\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str1("B\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str0("A\00") {addr_space = 0 : i32}
  llvm.func @main() -> i32 {
    %0 = llvm.mlir.constant(2 : index) : i64
    %1 = llvm.mlir.constant(1 : index) : i64
    %2 = llvm.alloca %1 x !llvm.struct<(i8)> : (i64) -> !llvm.ptr
    %3 = llvm.alloca %1 x !llvm.struct<(i8)> : (i64) -> !llvm.ptr
    %4 = llvm.alloca %1 x !llvm.array<2 x ptr> : (i64) -> !llvm.ptr
    %5 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %6 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %7 = llvm.alloca %0 x i8 : (i64) -> !llvm.ptr
    %8 = llvm.mlir.undef : i32
    %9 = llvm.mlir.addressof @str0 : !llvm.ptr
    %10 = llvm.getelementptr %9[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %11 = llvm.load %10 : !llvm.ptr -> i8
    llvm.store %11, %7 : i8, !llvm.ptr
    %12 = llvm.getelementptr %9[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %13 = llvm.load %12 : !llvm.ptr -> i8
    %14 = llvm.getelementptr %7[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %13, %14 : i8, !llvm.ptr
    %15 = llvm.mlir.addressof @str1 : !llvm.ptr
    %16 = llvm.getelementptr %15[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %17 = llvm.load %16 : !llvm.ptr -> i8
    llvm.store %17, %6 : i8, !llvm.ptr
    %18 = llvm.getelementptr %15[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %19 = llvm.load %18 : !llvm.ptr -> i8
    %20 = llvm.getelementptr %6[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %19, %20 : i8, !llvm.ptr
    %21 = llvm.mlir.addressof @str2 : !llvm.ptr
    %22 = llvm.getelementptr %21[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %23 = llvm.load %22 : !llvm.ptr -> i8
    llvm.store %23, %5 : i8, !llvm.ptr
    %24 = llvm.getelementptr %21[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %25 = llvm.load %24 : !llvm.ptr -> i8
    %26 = llvm.getelementptr %5[1] : (!llvm.ptr) -> !llvm.ptr, i8
    llvm.store %25, %26 : i8, !llvm.ptr
    llvm.call @_ZN11taskflowLibC1Ev(%4) : (!llvm.ptr) -> ()
    %27 = llvm.mlir.addressof @_Z5funcAv : !llvm.ptr
    %28 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%4, %7, %27) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %29 = llvm.getelementptr %3[] : (!llvm.ptr) -> !llvm.ptr, !llvm.struct<(i8)>
    %30 = llvm.load %29 : !llvm.ptr -> !llvm.struct<(i8)>
    llvm.store %30, %2 : !llvm.struct<(i8)>, !llvm.ptr
    %31 = llvm.call @_ZZ4mainENK3$_0cvPFvvEEv(%2) : (!llvm.ptr) -> !llvm.ptr
    %32 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%4, %6, %31) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    %33 = llvm.mlir.addressof @_Z5funcCv : !llvm.ptr
    %34 = llvm.call @_ZN11taskflowLib15task_definitionEPvPFvvE(%4, %5, %33) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%4, %34, %32) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib14add_dependencyEPvS0_(%4, %32, %28) : (!llvm.ptr, !llvm.ptr, !llvm.ptr) -> ()
    llvm.call @_ZN11taskflowLib7executeEv(%4) : (!llvm.ptr) -> ()
    llvm.return %8 : i32
  }
  llvm.func @_ZN11taskflowLibC1Ev(!llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib15task_definitionEPvPFvvE(!llvm.ptr, !llvm.ptr, !llvm.ptr) -> !llvm.ptr attributes {sym_visibility = "private"}
  llvm.func @_Z5funcAv() {
    %0 = llvm.mlir.constant(0 : index) : i64
    %1 = llvm.mlir.constant(3 : index) : i64
    %2 = llvm.mlir.constant(1 : index) : i64
    %3 = llvm.mlir.constant(0 : i32) : i32
    %4 = llvm.mlir.constant(9 : i32) : i32
    %5 = llvm.mlir.constant(8 : i32) : i32
    %6 = llvm.mlir.constant(7 : i32) : i32
    %7 = llvm.mlir.constant(6 : i32) : i32
    %8 = llvm.mlir.constant(5 : i32) : i32
    %9 = llvm.mlir.constant(4 : i32) : i32
    %10 = llvm.mlir.constant(3 : i32) : i32
    %11 = llvm.mlir.constant(2 : i32) : i32
    %12 = llvm.mlir.constant(1 : i32) : i32
    %13 = llvm.alloca %1 x !llvm.array<3 x i32> : (i64) -> !llvm.ptr
    %14 = llvm.alloca %1 x !llvm.array<3 x i32> : (i64) -> !llvm.ptr
    %15 = llvm.alloca %1 x !llvm.array<3 x i32> : (i64) -> !llvm.ptr
    %16 = llvm.getelementptr %15[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %12, %16 : i32, !llvm.ptr
    %17 = llvm.getelementptr %15[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %11, %17 : i32, !llvm.ptr
    %18 = llvm.getelementptr %15[0, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %10, %18 : i32, !llvm.ptr
    %19 = llvm.getelementptr %15[1, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %9, %19 : i32, !llvm.ptr
    %20 = llvm.getelementptr %15[1, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %8, %20 : i32, !llvm.ptr
    %21 = llvm.getelementptr %15[1, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %7, %21 : i32, !llvm.ptr
    %22 = llvm.getelementptr %15[2, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %6, %22 : i32, !llvm.ptr
    %23 = llvm.getelementptr %15[2, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %5, %23 : i32, !llvm.ptr
    %24 = llvm.getelementptr %15[2, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %4, %24 : i32, !llvm.ptr
    %25 = llvm.getelementptr %14[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %4, %25 : i32, !llvm.ptr
    %26 = llvm.getelementptr %14[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %5, %26 : i32, !llvm.ptr
    %27 = llvm.getelementptr %14[0, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %6, %27 : i32, !llvm.ptr
    %28 = llvm.getelementptr %14[1, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %7, %28 : i32, !llvm.ptr
    %29 = llvm.getelementptr %14[1, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %8, %29 : i32, !llvm.ptr
    %30 = llvm.getelementptr %14[1, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %9, %30 : i32, !llvm.ptr
    %31 = llvm.getelementptr %14[2, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %10, %31 : i32, !llvm.ptr
    %32 = llvm.getelementptr %14[2, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %11, %32 : i32, !llvm.ptr
    %33 = llvm.getelementptr %14[2, 2] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %12, %33 : i32, !llvm.ptr
    llvm.br ^bb1(%0 : i64)
  ^bb1(%34: i64):  // 2 preds: ^bb0, ^bb5
    %35 = llvm.icmp "slt" %34, %1 : i64
    llvm.cond_br %35, ^bb2, ^bb6
  ^bb2:  // pred: ^bb1
    llvm.br ^bb3(%0 : i64)
  ^bb3(%36: i64):  // 2 preds: ^bb2, ^bb4
    %37 = llvm.icmp "slt" %36, %1 : i64
    llvm.cond_br %37, ^bb4, ^bb5
  ^bb4:  // pred: ^bb3
    %38 = llvm.getelementptr %13[%34, %36] : (!llvm.ptr, i64, i64) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %3, %38 : i32, !llvm.ptr
    %39 = llvm.add %36, %2  : i64
    llvm.br ^bb3(%39 : i64)
  ^bb5:  // pred: ^bb3
    %40 = llvm.add %34, %2  : i64
    llvm.br ^bb1(%40 : i64)
  ^bb6:  // pred: ^bb1
    llvm.br ^bb7(%0 : i64)
  ^bb7(%41: i64):  // 2 preds: ^bb6, ^bb14
    %42 = llvm.icmp "slt" %41, %1 : i64
    llvm.cond_br %42, ^bb8, ^bb15
  ^bb8:  // pred: ^bb7
    llvm.br ^bb9(%0 : i64)
  ^bb9(%43: i64):  // 2 preds: ^bb8, ^bb13
    %44 = llvm.icmp "slt" %43, %1 : i64
    llvm.cond_br %44, ^bb10, ^bb14
  ^bb10:  // pred: ^bb9
    llvm.br ^bb11(%0 : i64)
  ^bb11(%45: i64):  // 2 preds: ^bb10, ^bb12
    %46 = llvm.icmp "slt" %45, %1 : i64
    llvm.cond_br %46, ^bb12, ^bb13
  ^bb12:  // pred: ^bb11
    %47 = llvm.getelementptr %15[%41, %45] : (!llvm.ptr, i64, i64) -> !llvm.ptr, !llvm.array<3 x i32>
    %48 = llvm.load %47 : !llvm.ptr -> i32
    %49 = llvm.getelementptr %14[%45, %43] : (!llvm.ptr, i64, i64) -> !llvm.ptr, !llvm.array<3 x i32>
    %50 = llvm.load %49 : !llvm.ptr -> i32
    %51 = llvm.mul %48, %50  : i32
    %52 = llvm.getelementptr %13[%41, %43] : (!llvm.ptr, i64, i64) -> !llvm.ptr, !llvm.array<3 x i32>
    %53 = llvm.load %52 : !llvm.ptr -> i32
    %54 = llvm.add %53, %51  : i32
    %55 = llvm.getelementptr %13[%41, %43] : (!llvm.ptr, i64, i64) -> !llvm.ptr, !llvm.array<3 x i32>
    llvm.store %54, %55 : i32, !llvm.ptr
    %56 = llvm.add %45, %2  : i64
    llvm.br ^bb11(%56 : i64)
  ^bb13:  // pred: ^bb11
    %57 = llvm.add %43, %2  : i64
    llvm.br ^bb9(%57 : i64)
  ^bb14:  // pred: ^bb9
    %58 = llvm.add %41, %2  : i64
    llvm.br ^bb7(%58 : i64)
  ^bb15:  // pred: ^bb7
    %59 = llvm.mlir.addressof @str3 : !llvm.ptr
    %60 = llvm.getelementptr %59[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %61 = llvm.call @printf(%60) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    llvm.return
  }
  llvm.func internal @_ZZ4mainENK3$_0cvPFvvEEv(%arg0: !llvm.ptr) -> !llvm.ptr attributes {sym_visibility = "private"} {
    %0 = llvm.mlir.addressof @_ZZ4mainEN3$_08__invokeEv : !llvm.ptr
    llvm.return %0 : !llvm.ptr
  }
  llvm.func @_Z5funcCv() {
    %0 = llvm.mlir.addressof @str4 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %2 = llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    llvm.return
  }
  llvm.func @_ZN11taskflowLib14add_dependencyEPvS0_(!llvm.ptr, !llvm.ptr, !llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func @_ZN11taskflowLib7executeEv(!llvm.ptr) attributes {sym_visibility = "private"}
  llvm.func internal @_ZZ4mainEN3$_08__invokeEv() attributes {sym_visibility = "private"} {
    llvm.return
  }
}
