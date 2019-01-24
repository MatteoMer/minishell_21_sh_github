# minishell_21_sh_github
Copy of my repo of minishell/21sh

The goal of this project is to create a pseudo-shell.
Bash was our reference shell for this project

## This mini-shell handle :
- Quote `"` and `'`

- Redirection `>`, `<`, `>>`, `<<`

- The following builtin : read, export, setenv, unsetenv, cd (the builtin are POSIX)

- Pipe `|`

- The operators `&&` , `||`, `;`

- A cool line edition

- A really cool lexer-parser with an AST ! (it's my favorite part, so I will tell some details below :) )

### The lexer-parser 
With all these cool feature we needed a really strong parsing ! So I did some research about the method about parsing a line.
I found that the most usefull here was an AST (Abstract Syntax Tree).
Let's take an example !

With the line :

```ls /var | cat -e && echo "Hello, " ; echo "World!"```

We first need to do `ls /var | cat -e` then if it was a success `echo "Hello, "` and finally `echo "World!"`

First, we need to understand what the user gave us. Here's come my lexer !
The lexer, with some basic grammar rule, divides the line in multiple node in a linked list, we're going to have this :

`ls [word]` -> `/var [word]` -> `| [operator]` -> `cat [word]` -> `-e [word]` -> `&& [operator]` -> [...] -> `"World!" [word]` -> `NULL`

Nice ! After the lexer, comes the first step of the parsing, check if the output is valid with some defined rules, for instance
check if there's no two operator next to each other

And finally ! The coolest part of our parsing, the AST !

Why an AST ? Because it's a simple way to handle priority rules in a simple output !

So after the AST did his job, the output is a binary tree, that look like this
```
                  ---;---
                 |     |
               --&&--  echo "World!"
               |    |
ls /var | cat -e    echo "Hello, "
```

It's actually the less priority operator that is on top of the AST
