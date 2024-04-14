# Amply
Very simple language

##Sintax

```
#					Primeiro endereço de memória vazio
%					Último endereço de memória ocupado
```

###Memory acess

```
[n]					Acessa o endereço n de uma lista
[n] = a
[n] = [a]
[n] += a
[n] += [a]
[n] -= a
[n] -= [a]
[n] *= a
[n] *= [a]
```

###Lógic

```
[n] = [a] < [b]
[n] = [a] <= [b]
[n] = [a] == [b]
```

###Loops
```
:a
goto:a
if[n]:a
```


##Example
```
[0: 2] = 1
print([1:2])

:0

[1] += [2]
[2] += [1]
print([1:2])
[0] = [2] < 1000

if[0]:0
``
