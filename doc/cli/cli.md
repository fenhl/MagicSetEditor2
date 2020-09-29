# Interactive command line interface

(since MSE 0.3.7)

## Description

```
mse --cli [my-set.mse-set]
```

The MSE interactive command line interface provides a way to work with set files without a graphical environment.
The CLI shows a prompt where commands can be entered, which are then executed by MSE.

## Commands

|Command|Short version|Description|
|---|---|---|
|`:help`|`:?`|Show a help screen describing the available commands.|
|`:quit`|`:q`|Exit the MSE command line interface.|
|`:load`|`:l`|Load a set file. The current set will be unloaded. For example: `:load my-set.mse-set`|
|`:reset`|`:r`|Clear all variable definitions.|
|`:cd`|`:c`|Change the working directory.|
|`:pwd`|`:p`|Print the current working directory.|
|`:!`||Perform a shell command. For example `:! dir` shows a directory listing.|
|*other*||Execute the command as a line of [script](../type/script) code. The script has access to the loaded set and all [built in functions](../function/index).|

## Raw mode

```
mse.exe --cli --raw
```

For interfacing MSE with other programs the raw mode is most convenient.

In the raw mode the only output is in response to commands.
For each command a single *record* is written to the standard output.
The records consists of:

* A line with an integer status code, `0` for ok, `1` for warnings, `2` for errors.
* A line containing an integer *k*, the number of lines to follow.
* *k* lines, each containing UTF-8 encoded string data.

Strings are not further encoded or escaped.

In this mode multi line strings can be transfered from MSE without much encoding/parsing hassle.

The behaviour of the raw mode is guaranteed not to change between versions of MSE (subject to bugs and changes in the scripting language),
for the normal mode no such guarantee is made.

## Example

Here is an example session, the text entered by the user is shown in blue.

<pre>
$ <span style="color:blue">mse --cli</span>
                                                                     ___
  __  __           _       ___     _      ___    _ _ _              |__ \
 |  \/  |__ _ __ _(_)__   / __|___| |_   | __|__| (_) |_ ___ _ _       ) |
 | |\/| / _` / _` | / _|  \__ | -_)  _|  | _|/ _` | |  _/ _ \ '_|     / /
 |_|  |_\__,_\__, |_\__|  |___|___|\__|  |___\__,_|_|\__\___/_|      / /_
             |___/                                                  |____|

> <span style="color:blue">:load myset.mse-set</span>
> <span style="color:blue">first_card := set.cards.0 <span style="color:green"># the first card</span></span>
[[card]]
> <span style="color:blue">first_card.name</span>
"Pineapple of Doom"
> <span style="color:blue">write_image_file(first_card, file: "firstcard.jpg")</span>
> <span style="color:green"># the image file "firstcard.jpg" is now saved</span>
> <span style="color:blue">:! dir</span>
2008-08-04  22:57            92 891 firstcard.jpg
               1 File(s)         92 891 bytes
               0 Dir(s)     986 562 560 bytes free
> <span style="color:blue">:reset</span>
> <span style="color:blue">first_card.name <span style="color:green"># variable was cleared</span></span>
<span style="color:red">ERROR:</span> Variable not set: first_card
> <span style="color:blue">:quit</span>
Goodbye
</pre>
