set_project("kernel")

set_toolchains("clang_nasm")

target("kernel")
    set_kind("binary")                    
    set_arch("i386")    
                   
    add_files("src/*.c", "src/**/*.c")
    add_files("src/*.asm", "src/**/*.asm")

    set_filename("os.bin")
    set_targetdir(".")
    add_cxflags("-ffreestanding", "-O2", "-Wall", "-Wextra", "-target i686-elf")  
    --add_asflags("")         
    add_ldflags("-nostdlib", "-T linker.ld", {force = true}) 



toolchain("clang_nasm")
    set_kind("standalone")
    set_toolset("cc", "clang")       
    set_toolset("cxx", "clang++")    
    set_toolset("ld", "ld.lld")
    set_toolset("as", "nasm")  
    add_cxxflags("-m32", "-target i686-elf")
    add_cflags("-m32", "-target i686-elf")
    add_asflags("-f elf32")     
toolchain_end()



