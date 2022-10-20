project('sdl_sort_visualizer', 'cpp',
        default_options: 'default_library=static')

cpp = meson.get_compiler('cpp')
add_project_arguments(
cpp.get_supported_arguments('-std=c++2a'),
language: 'cpp'
)


sdl2_dep = dependency('sdl2')

executable('sdlprog', 'main.cpp',
           win_subsystem: 'windows',
           dependencies: sdl2_dep)
