add_custom_target(UnitTests)
set_target_properties(UnitTests PROPERTIES FOLDER "Tests/UnitTests")

function(add_llvm_unittest test_dirname)
  add_unittest(UnitTests ${test_dirname} ${ARGN})
endfunction()
function(add_llvm_unittest_with_input_files test_dirname)
  add_unittest_with_input_files(UnitTests ${test_dirname} ${ARGN})
endfunction()

# The target unittests may test APIs that aren't exported in libLLVM.so, so
# we need to always link against the static libraries.
function(add_llvm_target_unittest test_dir_name)
  add_llvm_unittest(${test_dir_name} DISABLE_LLVM_LINK_LLVM_DYLIB ${ARGN})
endfunction()

add_subdirectory(ADT)
