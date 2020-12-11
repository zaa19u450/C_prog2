from distutils.core import setup, Extension

setup(name='arr_dll',
    ext_modules=[
        Extension('arr_dll',
            ['./dll/wrap.c'],
            include_dirs = ['.'],
            define_macros = [('FOO','1')],
            undef_macros = ['BAR'],
            library_dirs = ['.'],
            libraries = ['arr']
            )
        ]
)