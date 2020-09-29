# MSE Command line

Magic set editor can be started from the command prompt by typing:

```
mse
```

in Windows, or

```
magicseteditor
```

on other platforms.

The MSE program has several flags for choosing different behaviour.

## Starting the GUI

```
mse
```

Invoking MSE with no arguments shows the welcome window.

```
mse my-set.mse-set
```

Invoking MSE with the filename of a [set](../type/set) shows the main window with that set loaded.
This command is automatically invoked when you double click on a set file in a file manager.

```
mse my-symbol.mse-symbol
```

Invoking MSE with the filename of a [symbol](../type/symbol) shows the symbol editor window with that symbol loaded.

```
mse --symbol-editor
```

With the `--symbol-editor` flag the symbol editor is started with a blank symbol.

## Information about MSE

```
mse --version
```

The `--version` flag (abbreviate as `-v`) writes the version number of MSE to the standard output,
 or in a message box if MSE was not started from the command prompt.

```
mse --help
```

The `--help` flag (abbreviate as `-?`) displays a list of available flags to the standard output,
 or in a message box if MSE was not started from the command prompt.

## Installers

```
mse my-installer.mse-installer
```

Invoking MSE with the filename of an [installer](../type/installer) shows the package window, from where the packages in that installer can be installed.
By passing the `--local` or `--global` flag you can change where the package will be installed.
Global installation is for all users, local installation is for the current user only (see [data directories](../file/index.html#data-directories)).

```
mse --create-installer output.mse-installer package1.mse-game package2.mse-game ...
```

Creates an installer package containing one or more packages from the mse [data directory](../file/index.html#data-directories).
The installer will be written to `output.mse-installer`. This name can be omitted, in which case the name of the first package will be used (in this case `package1.mse-installer`).

## Interactive cli interface

```
mse --cli
```

Starts the [Interactive command line interface](cli).
Optionally the filename of a set can be passed which will then be loaded.
