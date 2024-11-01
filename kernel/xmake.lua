set_project("kernel")

set_toolchains("clang")

target("kernel")
    set_kind("binary")                    
    set_arch("i386")    
                   
    add_files("src/kernel.c", "src/boot.S")

    set_filename("os.bin")
    set_targetdir(".")
    add_cxflags("-ffreestanding", "-O2", "-Wall", "-Wextra", "-target i686-elf")  
    add_asflags("-target i686-elf")         
    add_ldflags("-nostdlib", "-T linker.ld", "-lgcc", {force = true}) 

