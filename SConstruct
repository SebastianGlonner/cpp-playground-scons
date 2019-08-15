
import os, sys

def add_sources(env, sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith('.' + extension):
            sources.append(dir + '/' + f)

outputPath = '#bin/'

use_mingw = False;

custom_tools = ['default'];

if use_mingw:
    custom_tools = ['mingw']

env = Environment(tools=custom_tools)
env['target'] = 'debug'

if use_mingw:
    env['LIBSUFFIX'] = '_dll.a' # fix @see readme.md
    env.Append(LINKFLAGS=['-static-libgcc', '-static-libstdc++'])

env_test = env.Clone();

#
# Build sharedtest dynamic library
#

libSources = []
add_sources(env, libSources, 'src', 'cpp')
#add_sources(env, sources, 'tests', 'cpp')

if (env["target"] == "debug"):
    if use_mingw:
        env.Append(CCFLAGS=['-g3', '-DDEBUG_ENABLED', '-DDEBUG_MEMORY_ENABLED'])
    # else:
    #     sys.exit("ERROR: debug target for msvc implemented")

if use_mingw:
    env.Append(CCFLAGS=['-fPIC'])

libTargetName = 'sharedtest-{}'.format(env['target'])
library = env.SharedLibrary(target=outputPath+libTargetName, source=libSources)
Default(library)

#
# Build catch unit test exe with library as dependency
#

env_test.Append(CPPPATH=[
    'vendor',
    'src'
])

testSources = []
add_sources(env_test, testSources, 'tests', 'cpp')

tests = env_test.Program(target='#bin/test', source=testSources
    , LIBS=[libTargetName], LIBPATH=[outputPath]
    )
Default(tests)
