module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<!llvm.ptr, dense<64> : vector<4xi32>>, #dlti.dl_entry<f80, dense<128> : vector<2xi32>>, #dlti.dl_entry<i16, dense<16> : vector<2xi32>>, #dlti.dl_entry<i32, dense<32> : vector<2xi32>>, #dlti.dl_entry<i1, dense<8> : vector<2xi32>>, #dlti.dl_entry<i8, dense<8> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<270>, dense<32> : vector<4xi32>>, #dlti.dl_entry<f128, dense<128> : vector<2xi32>>, #dlti.dl_entry<f16, dense<16> : vector<2xi32>>, #dlti.dl_entry<f64, dense<64> : vector<2xi32>>, #dlti.dl_entry<i64, dense<64> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<271>, dense<32> : vector<4xi32>>, #dlti.dl_entry<!llvm.ptr<272>, dense<64> : vector<4xi32>>, #dlti.dl_entry<"dlti.stack_alignment", 128 : i32>, #dlti.dl_entry<"dlti.endianness", "little">>, llvm.data_layout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128", llvm.target_triple = "x86_64-unknown-linux-gnu", "polygeist.target-cpu" = "x86-64", "polygeist.target-features" = "+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87", "polygeist.tune-cpu" = "generic"} {
  llvm.mlir.global internal constant @str3("A\0A\00") {addr_space = 0 : i32}
  llvm.func @printf(!llvm.ptr, ...) -> i32
  llvm.mlir.global internal constant @str2("C\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str1("B\00") {addr_space = 0 : i32}
  llvm.mlir.global internal constant @str0("A\00") {addr_space = 0 : i32}
  func.func @main() -> i32 attributes {llvm.linkage = #llvm.linkage<external>} {
    %alloca = memref.alloca() : memref<1x!llvm.struct<(i8)>>
    %cast = memref.cast %alloca : memref<1x!llvm.struct<(i8)>> to memref<?x!llvm.struct<(i8)>>
    %alloca_0 = memref.alloca() : memref<!llvm.struct<(i8)>>
    %alloca_1 = memref.alloca() : memref<1x!llvm.struct<(i8)>>
    %cast_2 = memref.cast %alloca_1 : memref<1x!llvm.struct<(i8)>> to memref<?x!llvm.struct<(i8)>>
    %alloca_3 = memref.alloca() : memref<!llvm.struct<(i8)>>
    %alloca_4 = memref.alloca() : memref<1x2xmemref<?xi8>>
    %cast_5 = memref.cast %alloca_4 : memref<1x2xmemref<?xi8>> to memref<?x2xmemref<?xi8>>
    %alloca_6 = memref.alloca() : memref<2xi8>
    %alloca_7 = memref.alloca() : memref<2xi8>
    %alloca_8 = memref.alloca() : memref<2xi8>
    %0 = llvm.mlir.undef : i32
    %1 = llvm.mlir.addressof @str0 : !llvm.ptr
    %2 = llvm.getelementptr %1[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %3 = llvm.load %2 : !llvm.ptr -> i8
    affine.store %3, %alloca_8[0] : memref<2xi8>
    %4 = llvm.getelementptr %1[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %5 = llvm.load %4 : !llvm.ptr -> i8
    affine.store %5, %alloca_8[1] : memref<2xi8>
    %6 = llvm.mlir.addressof @str1 : !llvm.ptr
    %7 = llvm.getelementptr %6[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %8 = llvm.load %7 : !llvm.ptr -> i8
    affine.store %8, %alloca_7[0] : memref<2xi8>
    %9 = llvm.getelementptr %6[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %10 = llvm.load %9 : !llvm.ptr -> i8
    affine.store %10, %alloca_7[1] : memref<2xi8>
    %11 = llvm.mlir.addressof @str2 : !llvm.ptr
    %12 = llvm.getelementptr %11[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %13 = llvm.load %12 : !llvm.ptr -> i8
    affine.store %13, %alloca_6[0] : memref<2xi8>
    %14 = llvm.getelementptr %11[0, 1] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<2 x i8>
    %15 = llvm.load %14 : !llvm.ptr -> i8
    affine.store %15, %alloca_6[1] : memref<2xi8>
    call @_ZN11taskflowLibC1Ev(%cast_5) : (memref<?x2xmemref<?xi8>>) -> ()
    %cast_9 = memref.cast %alloca_8 : memref<2xi8> to memref<?xi8>
    %16 = "polygeist.get_func"() <{name = @_Z4testv}> : () -> !llvm.ptr
    %17 = "polygeist.pointer2memref"(%16) : (!llvm.ptr) -> memref<?x!llvm.func<void ()>>
    %18 = call @_ZN11taskflowLib15task_definitionEPvPFvvE(%cast_5, %cast_9, %17) : (memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?x!llvm.func<void ()>>) -> memref<?xi8>
    %cast_10 = memref.cast %alloca_7 : memref<2xi8> to memref<?xi8>
    %19 = affine.load %alloca_3[] : memref<!llvm.struct<(i8)>>
    affine.store %19, %alloca_1[0] : memref<1x!llvm.struct<(i8)>>
    %20 = call @_ZZ4mainENK3$_0cvPFvvEEv(%cast_2) : (memref<?x!llvm.struct<(i8)>>) -> memref<?x!llvm.func<void ()>>
    %21 = call @_ZN11taskflowLib15task_definitionEPvPFvvE(%cast_5, %cast_10, %20) : (memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?x!llvm.func<void ()>>) -> memref<?xi8>
    %cast_11 = memref.cast %alloca_6 : memref<2xi8> to memref<?xi8>
    %22 = affine.load %alloca_0[] : memref<!llvm.struct<(i8)>>
    affine.store %22, %alloca[0] : memref<1x!llvm.struct<(i8)>>
    %23 = call @_ZZ4mainENK3$_1cvPFvvEEv(%cast) : (memref<?x!llvm.struct<(i8)>>) -> memref<?x!llvm.func<void ()>>
    %24 = call @_ZN11taskflowLib15task_definitionEPvPFvvE(%cast_5, %cast_11, %23) : (memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?x!llvm.func<void ()>>) -> memref<?xi8>
    call @_ZN11taskflowLib14add_dependencyEPvS0_(%cast_5, %24, %21) : (memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?xi8>) -> ()
    call @_ZN11taskflowLib14add_dependencyEPvS0_(%cast_5, %21, %18) : (memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?xi8>) -> ()
    call @_ZN11taskflowLib7executeEv(%cast_5) : (memref<?x2xmemref<?xi8>>) -> ()
    return %0 : i32
  }
  func.func private @_ZN11taskflowLibC1Ev(memref<?x2xmemref<?xi8>>) attributes {llvm.linkage = #llvm.linkage<external>}
  func.func private @_ZN11taskflowLib15task_definitionEPvPFvvE(memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?x!llvm.func<void ()>>) -> memref<?xi8> attributes {llvm.linkage = #llvm.linkage<external>}
  func.func @_Z4testv() attributes {llvm.linkage = #llvm.linkage<external>} {
    %0 = llvm.mlir.addressof @str3 : !llvm.ptr
    %1 = llvm.getelementptr %0[0, 0] : (!llvm.ptr) -> !llvm.ptr, !llvm.array<3 x i8>
    %2 = llvm.call @printf(%1) vararg(!llvm.func<i32 (ptr, ...)>) : (!llvm.ptr) -> i32
    return
  }
  func.func private @_ZZ4mainENK3$_0cvPFvvEEv(%arg0: memref<?x!llvm.struct<(i8)>>) -> memref<?x!llvm.func<void ()>> attributes {llvm.linkage = #llvm.linkage<internal>} {
    %0 = "polygeist.get_func"() <{name = @_ZZ4mainEN3$_08__invokeEv}> : () -> !llvm.ptr
    %1 = "polygeist.pointer2memref"(%0) : (!llvm.ptr) -> memref<?x!llvm.func<void ()>>
    return %1 : memref<?x!llvm.func<void ()>>
  }
  func.func private @_ZZ4mainENK3$_1cvPFvvEEv(%arg0: memref<?x!llvm.struct<(i8)>>) -> memref<?x!llvm.func<void ()>> attributes {llvm.linkage = #llvm.linkage<internal>} {
    %0 = "polygeist.get_func"() <{name = @_ZZ4mainEN3$_18__invokeEv}> : () -> !llvm.ptr
    %1 = "polygeist.pointer2memref"(%0) : (!llvm.ptr) -> memref<?x!llvm.func<void ()>>
    return %1 : memref<?x!llvm.func<void ()>>
  }
  func.func private @_ZN11taskflowLib14add_dependencyEPvS0_(memref<?x2xmemref<?xi8>>, memref<?xi8>, memref<?xi8>) attributes {llvm.linkage = #llvm.linkage<external>}
  func.func private @_ZN11taskflowLib7executeEv(memref<?x2xmemref<?xi8>>) attributes {llvm.linkage = #llvm.linkage<external>}
  func.func private @_ZZ4mainEN3$_08__invokeEv() attributes {llvm.linkage = #llvm.linkage<internal>} {
    return
  }
  func.func private @_ZZ4mainEN3$_18__invokeEv() attributes {llvm.linkage = #llvm.linkage<internal>} {
    return
  }
}