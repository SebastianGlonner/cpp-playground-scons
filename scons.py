
from os.path import join;
import sys;
sys.path = [ join(sys.prefix, 'Lib', 'site-packages', 'scons-3.0.0'), join(sys.prefix, 'Lib', 'site-packages', 'scons'), join(sys.prefix, 'scons-3.0.0'), join(sys.prefix, 'scons')] + sys.path;
import SCons.Script;

SCons.Script.main();
