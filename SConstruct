
import os

def add_sources(env, sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith('.' + extension):
            sources.append(dir + '/' + f)

use_mingw = True;

custom_tools = ['default'];

if use_mingw:
    custom_tools = ['mingw']

env = Environment(tools=custom_tools)
env['target'] = 'debug'

if use_mingw:
    env.Append(LINKFLAGS=['-static-libgcc', '-static-libstdc++'])

env_test = env.Clone();

libSources = []
add_sources(env, libSources, 'src', 'cpp')
#add_sources(env, sources, 'tests', 'cpp')

if (env["target"] == "debug"):
    env.Append(CCFLAGS=['-g3', '-DDEBUG_ENABLED', '-DDEBUG_MEMORY_ENABLED'])

env.Append(CCFLAGS=['-fPIC'])
libTarget = '#bin/library-{}'.format(env['target'])
# library = env.SharedLibrary(target=libTarget, source=libSources)

env_test.Append(CPPPATH=[
    'vendor',
    'src'
])

# env_test.Append(LIBS=[library])
# env_test.Append(LIBS=[library])

testSources = []
add_sources(env_test, testSources, 'src', 'cpp')
add_sources(env_test, testSources, 'tests', 'cpp')

tests = env_test.Program(target='test', source=testSources)
Default(tests)
