# Playground for scons,c++, mingw, msvc

# configure clion with scons

Configure Custom Build Targets (Settings > Build, Execution, Deployment > Custom Build Targets)

Use external tools:
Programm: $PyInterpreterDirectory$/scons.bat
Working directory: $ProjectFileDir$

Configur Run/Debug Configurations

Type: Custom Build Application
Target: You previously created <custom build target>
Executable: The resulting exe? You need to execute scons once to be able to select the file.

# gotchas

## link program with dll on linux

you have to export functions etc. in the .dll and also have to import these functions
in the programm which is using the .dll:

```
__declspec(dllexport)
__declspec(dllimport)
```

## mingw

scons + mingw automatically compile a <lib>.dll and a lib<lib>.a file (i dont know why yet
there are reasons but these are obsolete?) when compiling shared libraries.
It is done the the command: -Wl,--out-implib,bin\sharedtest-debug.a

when you link with mingw (gnu?) than you have specific naming conventions like you
give the name <lib> and the linker links <lib>.dll or lib<lib>.a. the problem here is:
<lib>.dll and lib<lib>.a are NOT considiered equals ...

sooo ... both files get compiled and both files will be found by the linker ...
when you also used the flags -static-libgcc -static-libstdc++ then you get some error like:

```
libgcc/unwind.inc:230: multiple definition of _Unwind_Resume; bin/libsharedtest-debug.afirst defined here
```

this is due too the linking of both libraries windows <lib>.dll and linux like  and a lib<lib>.a

How to fix:

Adjust the suffix for the shared library like so:

```
env['LIBSUFFIX'] = '_dll.a'
```

This changes the implib command to something like this:
-Wl,--out-implib,bin\sharedtest-debug_dll.a

This prevent the linker from including both:
    sharedtest-debug.dll
    libsharedtest-debug.a
