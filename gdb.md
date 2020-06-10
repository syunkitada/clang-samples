# GDB

## コンパイル

- gdb でデバッグするには、gcc でコンパイルするときに以下のオプションを入れる
- -g
  - デバッグ情報を付与するオプションで、ファイル名や行番号、引数の値もバックトレースに含まれる
- -g3
  - デバッグ情報に加えて、マクロの展開ができるようになる
- -O0
  - 最適化を行わない(最適化を行うとコードの修正が入るのでデバッグがしにくくなる)

```sh
gcc -g3 -O0 ...
```

## スレッドのデバッグ

```sh
(gdb) set non-stop on
(gdb) set target-async on
```

```sh
set non-stop on
set target-async on
```

```sh
(gdb) i thread

(gdb) thread

(gdb) thread 2

(gdb) thread apply 2 [command]
```
