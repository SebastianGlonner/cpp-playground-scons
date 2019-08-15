
import os

def add_sources(env, sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith('.' + extension):
            sources.append(dir + '/' + f)


sources = []

env = Environment(tools=['mingw'])
env['target'] = 'debug'

env.Append(CPPPATH=[
    'vendor',
    'src'
])

#add_sources(env, sources, 'vendor', 'hpp')
add_sources(env, sources, 'src', 'cpp')
add_sources(env, sources, 'tests', 'cpp')

if (env["target"] == "debug"):
    env.Append(CCFLAGS=['-g3', '-DDEBUG_ENABLED', '-DDEBUG_MEMORY_ENABLED'])

tests = env.Program(target='test', source=sources)

Default(tests)
