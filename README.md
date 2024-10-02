# Amply
Very simple language

## Sintax
```
#					First empty memory address
%					Last occupied memory address
```

### Memory acess
```
[n]					Access address n from a list
[n] = a
[n] = [a]
[n] = [a - b]
[n] = [a + b]
[n] = [[a]]
[n] = [[a] - b]
[n] = [[a] + b]
[n] = [[[a]]]
[a:b] = n
[a:b] = [n]
[n] = [a:b]			Sum
[n] += a
[n] += [a]
[n] -= a
[n] -= [a]
[n] *= a
[n] *= [a]
[n] /= [a]
[n] /= a
```

### Logic
```
[n] = [a] < [b]
[n] = [a] < b
[n] = a < [b]
[n] = a < b
[n] = [a] <= [b]
[n] = [a] <= b
[n] = a <= [b]
[n] = a <= b
[n] = [a] == [b]
[n] = [a] == b
[n] = a == [b]
```

### Loops
```
:a					Enter an address to return
goto:a
if[n]:a				If the memory address is 1, it returns to the indicated memory location
```

### Prints
```
print[n]
print[a:b]
```


## Examples

### FIBONACCI:
```
[0: 2] = 1
print([1:2])

:0
[1] += [2]
[2] += [1]
print[1:2]
[0] = [2] < 1000
if[0]:0
```

### SUM:
```
[0] = 0
[1] = 1
[2] = 0
[3] = 3

[4] = 12
[5] = 14
[6] = 23
[7] = 41

:0
[3] += 1
[2] = [[3]]
[0] += [2]
[1] = [3] < %
print[0]
if[1]:0
```

### ([0]^2 + [0])/2:
```
[1] = 1
[0] = 10

:0
[#] = #
[%] -= 1
[1] = [%] < [0]
if[1]:0

[1] = [2:%]
print[1]
```

### Exponential ([0]^[1]):
```
[0] = 5
[1] = 3
[2] = 1
[3] = 1
[4] = 5

:0
[4] *= [0]
[2] += 1
[3] = [2] < [1]
if[3]:0

print[4]
```

### Fatorial of [0]:
```
[0] = 5
[1] = [0]
[2] = 0

:0
[1] -= 1
[0] *= [1]
[2] = 1 < [1]
if[2]:0

print[0]
```
