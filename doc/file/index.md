# Data files

MSE uses several different types of [data files](format), usually organized into [packages](package).

## File types

The following types are stored in [packages](package) in the:

* [game](../type/game)
* [stylesheet](../type/stylesheet)
* [symbol font](../type/symbol_font)
* [export template](../type/export_template)
* [locale](../type/locale)
* [include](../type/include)

The following types are stored in [packages](package) that can be located anywhere:

* [set](../type/set)
* [installer](../type/installer)

The following types are stored diractly in [hierarchical files](format), they can be located anywhere:

* [symbol](../type/symbol)

## Data directories

The data files that come with Magic Set Editor are stored in [packages](package) in the *data directory*,
these are usually subdirectories of that directory.

There are two data directories, a *global* one with data files installed with the program,
and a *local*''* data directory for the current logged in user.
The latter is used for installing packages if the user doesn't have administrator priviliges.

On Windows, the location of the global data directory is `%MSE_DIR%\data`, usually `C:\Program Files\Magic Set Editor 2\data`.

The location of the local data directory is `%USER_APPLICATION_DATA%\Magic Set Editor\data`, usually `C:\Documents and Settings\%USERNAME%\Application Data\Magic Set Editor\data`.
