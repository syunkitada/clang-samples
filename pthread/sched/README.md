# sched

- スケジューラの挙動を確認するための実験プログラム

```
# 1 cpuのみで実行
$ gcc main.c -o main.o -l pthread; taskset -c 1 ./main.o
thread[139769511884544] elapsed=[0.109017] ______+++________________________++++________________________________++++___________________________
thread[139769503491840] elapsed=[0.113026] __________+++________________________++++____________________________________++++___________________
thread[139769520277248] elapsed=[0.117022] _++++_+__________________________________________++++________________________________++++___________
thread[139769537062656] elapsed=[0.125032] ______________________+++________________________________++++____________________________________+++
thread[139769545455360] elapsed=[0.125060] __________________________+++________________________________++++___________________________________
thread[139769553848064] elapsed=[0.129062] ______________________________+++________________________________++++_______________________________
thread[139769495099136] elapsed=[0.129079] ______________+++________________________++++____________________________++++_______________________
thread[139769528669952] elapsed=[0.129092] __________________+++________________________++++________________________________++++_______________
thread[139769570633472] elapsed=[0.140819] __________________________________________________________________________________________+++_______
thread[139769562240768] elapsed=[0.148862] ______________________________________________________+++____________________________________++++___

# 1,2 cpuのみで実行
$ gcc main.c -o main.o -l pthread; taskset -c 1,2 ./main.o
thread[139844486489856] elapsed=[0.050145] _++++++++++++________________________________++++++_________________________________________________
thread[139844427740928] elapsed=[0.057046] _____++++____________++++________________________________+__________________________________________
thread[139844419348224] elapsed=[0.057068] _++++____________________++++____________________________+__________________________________________
thread[139844436133632] elapsed=[0.065044] _____________++++++++++++_________________________+++_______________________________________________
thread[139844444526336] elapsed=[0.069061] _________++++________________________++++++++________________________+______________________________
thread[139844452919040] elapsed=[0.069080] _____________++++____________________________++++++++_______________________________________________
thread[139844478097152] elapsed=[0.079079] _____________________________++++++++____________________________++++++++++++++_____________________
thread[139844469704448] elapsed=[0.079095] _________________++++________________________________++++++++++++___________________________________
thread[139844461311744] elapsed=[0.079112] _________________________++++++++________++++________++++++++++++___________________________________
thread[139844494882560] elapsed=[0.081344] _________________________________++++++++________________________+++++++++++++++++__________________

# 全 cpuで実行
$ gcc main.c -o main.o -l pthread; ./main.o
thread[139719421458176] elapsed=[0.010346] _++++++++++_________________________________________________________________________________________
thread[139719413065472] elapsed=[0.010355] _++++++++++_________________________________________________________________________________________
thread[139719404672768] elapsed=[0.010370] _++++++++++_________________________________________________________________________________________
thread[139719379494656] elapsed=[0.010434] _++++++++++_________________________________________________________________________________________
thread[139719387887360] elapsed=[0.010396] _++++++++++_________________________________________________________________________________________
thread[139719396280064] elapsed=[0.010374] _++++++++++_________________________________________________________________________________________
thread[139719371101952] elapsed=[0.010476] _++++++++++_________________________________________________________________________________________
thread[139719362709248] elapsed=[0.010527] _++++++++++_________________________________________________________________________________________
thread[139719354316544] elapsed=[0.010890] _++++++++++_________________________________________________________________________________________
thread[139719345923840] elapsed=[0.020124] _++++++++++++++++++++_______________________________________________________________________________
```
