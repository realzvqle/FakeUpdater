set_project("update")

set_xmakever("2.6.0")

set_languages("c11")

target("update")
    set_kind("binary")  
    add_files("src/*.c")
    add_files("src/**/*.c") 
    add_includedirs("src") 
    add_linkdirs("lib/windows") 
    add_links("raylibdll", "raylib") 
    add_syslinks("gdi32", "winmm", "shell32", "user32", "ntdll", "Advapi32") 
    add_ldflags("/SUBSYSTEM:WINDOWS")
    