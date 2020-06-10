# include

## 標準ライブラリから include

```c
#include <stdio.h>
```

## 独自ライブラリから include

- ライブラリのあるルートディレクトリを-I で明示的に指定する

```c
#include <lib/calc.h>
```

```sh
gcc main.c -I ./
```

## 相対パスから include

- 基本的にカレントディレクトリ配下での依存時のみ利用される
- "../" のように上のディレクトリを相対的に指定することもできるが複雑になるため利用は避ける
  - -I で指定したディレクトリから、相対パスで指定するのが一般的

```c
#include "lib/echo.h"

// 以下みたいにしてもよい
#include "../include/lib/echo.h"
```
