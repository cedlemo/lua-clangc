#ruby-clangc

lua bindings to the clang C interface

Just a hobby project for now.

# Build:

## Standard:

The autotools will detect automaticaly your lua version
and install the library in a path build on the prefix variable.

    ./autogen.sh --prefix=/usr
    make
    sudo make install

The library files will be isntalled in /usr/lib/lua/LUA_VERSION/clangc.

## Custom directory:

You can still use the *libdir* variable. If your current version of lua
is 5.3 for example:

    ./autogen.sh --libdir=/usr/lib/lua/5.3
    make
    sudo make install


# Clean:

    sudo make uninstall
    make maintainer clean

