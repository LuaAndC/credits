package = "credits"
version = "dev-1"
source = {
    url = "git@github.com:LuaAndC/credits.git",
}
description = {
    summary = " Задания зачёта ",
    homepage = "https://github.com/LuaAndC/credits",
    license = "MIT/X11",
}
dependencies = {
    "lua >= 5.1",
}
build = {
    type = "builtin",
    modules = {
        ['distance'] = 'c-distance/credit.c',
        ['distance.credit'] = 'lua-distance/credit.lua',
        ['gaps'] = 'c-gaps/credit.c',
    },
}
