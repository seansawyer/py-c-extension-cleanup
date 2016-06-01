from distutils.core import setup, Extension

module1 = Extension('watch', sources = ['watch.c'])

setup(name = 'PyCleanupDemo',
      version = '1.0',
      description = 'A demo of GCC __cleanup__ in CPython extension',
      ext_modules = [module1])
