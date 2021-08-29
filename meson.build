project('com.github.fBarbanti.Regex_tester', 'vala', 'c')

    # subdir('src')
gnome = import('gnome')

# Tell meson where to find our resources file and to compile it as a GResource
gresource = gnome.compile_resources(
    'gresource',
    'data' / 'gresource.xml',
    source_dir: 'data'
)



executable(
    meson.project_name(),
    gresource,
    
    'src/Main.vala',
    'src/Application.vala',

    'src/Objects/MatchItem.vala',

    'src/Widgets/Header.vala',
    'src/Widgets/Window.vala',


    dependencies: [
        dependency('gtk+-3.0')
    ],
    install: true
)

